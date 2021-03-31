#include <iostream>
#include <fstream>
#include "Playlist.h"
#define space cout << endl;

using namespace std;


PlaylistNode* head = nullptr;
PlaylistNode* tail = nullptr;


void addSong();
void PrintMenu(string);

int main(){

  string playlistName;
  cout << "Enter playlist's title:" << endl;
  getline(cin, playlistName);
  space
  PrintMenu(playlistName);


    return 0;
}

void PrintMenu(string songListName)
{
  char menuOption;
  cout << songListName << " PLAYLIST MENU" << endl;
  cout << "a - Add song" << endl;
  cout << "d - Remove song" << endl;
  cout << "c - Change position of song" << endl;
  cout << "s - Output songs by specific artist" << endl;
  cout << "t - Output total time of playlist (in seconds)" << endl;
  cout << "o - Output full playlist" << endl;
  cout << "q - Quit" << endl;

  space
  cout << "Choose an option: " << endl;
  cin >> menuOption;
  space

  
  if (menuOption == 'q')
  {
    return;
  }
  else if (menuOption == 'a'){

    
    // User Input
    string tempid = "";
    cout << "Enter song's unique ID: " << endl;
    cin >> tempid;
    string tempname = "";
    string tempname2 = "";
    cout << "Enter song's name: \n";
    cin >> tempname;
    getline(cin, tempname2);
    tempname += tempname2;
    string tempartist;
    cout << "Enter artist's name: \n";
    getline(cin, tempartist);
    int templength;
    cout << "Enter song's length (in seconds): " << endl;
    cin >> templength;
    space

    //Construction of new Song
    if (head == nullptr){
      PlaylistNode* newnode = new PlaylistNode(tempname, tempartist, templength, tempid, nullptr);
      head = tail = newnode;
    } else {
      PlaylistNode* newnode = new PlaylistNode(tempname, tempartist, templength, tempid, nullptr);
      tail->SetNext(newnode); // this will work once "setnext()" is implemented
      tail = newnode;
      
    }
  }

  else if (menuOption == 'd'){

    // User Input
    string tempid = "";
    cout << "Enter song's unique ID: " << endl;
    cin >> tempid;
    space

    // Find and Remove Song
    PlaylistNode* curr = head;
    while (curr != nullptr) {
      if (curr->GetID() == tempid){
        if (head == curr){              //condition for if deleting head
          head = curr->GetNext();
          delete curr;
        }
        else if (tail == curr) {              //condition for if deleting tail
          PlaylistNode* prev = head;
          while (prev->GetNext() != curr){
            prev = prev->GetNext();
          }
          tail = prev;
          tail->SetNext(nullptr);
          delete curr;
        }
        break;
      }
      curr = curr->GetNext();
    }


  }

  else if (menuOption == 's')
  {
    string artistName;
    string artistname2;
    int songCounter = 1;
    cout << "OUTPUT SONGS BY SPECIFIC ARTIST" << endl;
    cout << "Enter artist's name: \n";
    cin >> artistname2;
    getline(cin, artistName);
    artistName = artistname2 + artistName;
    space

    for (PlaylistNode* currNode = head; currNode != nullptr; currNode = currNode->GetNext())
    {
      if (currNode->GetArtistName() == artistName)
      {
        cout << songCounter << "." << endl;
        currNode->PrintPlaylistNode();
        cout << endl;
      }
      ++songCounter;
    }
  }
  else if (menuOption == 't')
  {
    if (head == nullptr){
      cout << "Playlist is empty" << endl;
    } else {
      int playlistTime = 0;
      cout << "OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)" << endl;
      for (PlaylistNode* currNode = head; currNode != nullptr; currNode = currNode->GetNext()){
        playlistTime += currNode->GetSongLength();
      }
      cout << "Total time: " << playlistTime << " seconds" << endl;
    }
    space
  }
  
  else if (menuOption == 'o')
  {
    int songCounter = 1;
    cout << songListName << "- OUTPUT FULL PLAYLIST" << endl;
    space
    for (PlaylistNode* currNode = head; currNode != nullptr; currNode = currNode->GetNext())
    {
      cout << songCounter << "." << endl;
      currNode->PrintPlaylistNode();
      cout << endl;
      ++songCounter;
    }

  }

  else if (menuOption == 'c'){
    
    PlaylistNode* temp = nullptr;

    // User input
    int currpos = 0;
    int newpos = 0;
    cout << "Enter song's current position:\n";
    cin >> currpos;
    cout << "Enter new position for song:\n";
    cin >> newpos;

    // Movement of songs
    if (currpos == newpos) {/*doesn't do anything*/}
    else if (currpos == 1) {                            // case for head
      temp = head;
      head = head->GetNext();
    }
    else {
      temp = head;
      int counter = 1;
      while (temp->GetNext() != nullptr and counter != newpos){
        temp = temp->GetNext();
      }
    }
    



    PlaylistNode* curr = head;
    for (int i = 0; i < newpos; i++){
      
    }


  }

  else if (menuOption == 'z') //testing option
  {
    cout << "test" << endl;
  }

  
  PrintMenu(songListName);


}