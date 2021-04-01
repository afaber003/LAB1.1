#include <iostream>
#include <fstream>
#include "Playlist.h"
#define space cout << endl;
#define space2 space space

using namespace std;

//Made by Andrew Faber and Benjamin Bravo CS10C Section 001


PlaylistNode* head = nullptr;
PlaylistNode* tail = nullptr;


void addSong();
void PrintMenu(string);

int main(){

  string playlistName;
  cout << "Enter playlist's title:";
  getline(cin, playlistName);
  space2
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
  cout << "Choose an option:";
  cin >> menuOption;
  space
  
  if (menuOption == 'q')
  {
    return;
  }
  else if (menuOption == 'a'){

    cout << "ADD SONG" << endl;
    // User Input
    string tempid = "";
    cout << "Enter song's unique ID:";
    cin >> tempid;
    space
    string tempname = "";
    string tempname2 = "";
    cout << "Enter song's name:";
    cin >> tempname;
    getline(cin, tempname2);
    space
    tempname += tempname2;
    string tempartist;
    cout << "Enter artist's name:";
    getline(cin, tempartist);
    space
    int templength;
    cout << "Enter song's length (in seconds):";
    cin >> templength;
    space
    space

    //Construction of new Song
    if (head == nullptr){
      PlaylistNode* newnode = new PlaylistNode(tempid, tempname, tempartist, templength, nullptr);
      head = tail = newnode;
    } else {
      PlaylistNode* newnode = new PlaylistNode(tempid, tempname, tempartist, templength, nullptr);
      tail->SetNext(newnode); // this will work once "setnext()" is implemented
      tail = newnode;
      
    }
  }

  else if (menuOption == 'd'){

    cout << "REMOVE SONG" << endl;
    // User Input
    string tempid = "";
    cout << "Enter song's unique ID:";
    cin >> tempid;
    space

    // Find and Remove Song
    PlaylistNode* curr = head;
    while (curr != nullptr) {
      if (curr->GetID() == tempid){ //checks for songID to set curr to node to be deleted
        if (head == curr){              //condition for if deleting head
          head = curr->GetNext();
          cout << '"' << curr->GetSongName() << '"' << " removed." << endl;
          space
          delete curr;
        }
        else if (tail == curr) {              //condition for if deleting tail
          PlaylistNode* prev = head;
          while (prev->GetNext() != curr){
            prev = prev->GetNext();
          }
          tail = prev;
          tail->SetNext(nullptr);
          cout << '"' << curr->GetSongName() << '"' << " removed." << endl;
          space
          delete curr;
        }
        else {
          PlaylistNode* prev = head;
          while (prev->GetNext() != curr){
            prev = prev->GetNext();
          }
          prev->SetNext(curr->GetNext());
          cout << '"' << curr->GetSongName() << '"' << " removed." << endl;
          space
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
    cout << "Enter artist's name:";
    cin >> artistname2;
    getline(cin, artistName);
    space
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
    cout << songListName << " - OUTPUT FULL PLAYLIST" << endl;
    if (head == nullptr){cout << "Playlist is empty" << endl;space}
    for (PlaylistNode* currNode = head; currNode != nullptr; currNode = currNode->GetNext())
    {
      cout << songCounter << "." << endl;
      currNode->PrintPlaylistNode();
      cout << endl;
      ++songCounter;
    }

  }

  else if (menuOption == 'c' and head != nullptr){
    
    cout << "CHANGE POSITION OF SONG" << endl;

    PlaylistNode* temp = nullptr;
    PlaylistNode* tempprev = head;

    // User input
    int currpos = 0;
    int newpos = 0;
    cout << "Enter song's current position:";
    cin >> currpos;
    space
    if (currpos < 1){currpos = 1;}
    cout << "Enter new position for song:";
    cin >> newpos;
    space
    if (newpos < 1){newpos = 1;}

    // Movement of songs
    if (currpos == newpos) {/*doesn't do anything*/}
    else {
      temp = head;
      bool isTail = false;
      for (int i = 1; i < currpos; i++){   // sets temp as the one that is moving
        if (temp->GetNext() == nullptr){break;}
        temp = temp->GetNext();
      }
      cout << '"' << temp->GetSongName() << '"' << " moved to position ";
      string tempname = temp->GetSongName(); string artistname = temp->GetArtistName(); int legnth = temp->GetSongLength(); string idd = temp->GetID();
      PlaylistNode* newone = new PlaylistNode(idd, tempname, artistname, legnth, nullptr);
      
      if (temp->GetNext() == nullptr){ //if its tail
        if (currpos == 1) { //if its tail and head
          delete temp;
        }
        else { 
          PlaylistNode* tailtemp = head;
          while (tailtemp->GetNext() != temp){
            tailtemp = tailtemp->GetNext();
          }
          tail = tailtemp;
          tailtemp->SetNext(nullptr);
          delete temp;
        }
      }
      else if (currpos == 1) { //if its head
        head = temp->GetNext();
        delete temp;
      }
      else {
        while (tempprev->GetNext() != temp){ //sets tempprev to proper value
          tempprev = tempprev->GetNext();
        }
        tempprev->SetNext(temp->GetNext());
        delete temp;
      }

/*****************
      From here temp points at the node that newone should come after

*****************/

      temp = head;
      if (newpos == 1){         // case for if newpos is head
        newone->SetNext(head);
        cout << "1" << endl;
        head = newone;
      }
      else {
        int counter = 1;
        while(isTail == false and counter + 1 < newpos){ // setting temp as defined above
          if (temp->GetNext() == nullptr){
            isTail = true;
            break;
          }
          temp = temp->GetNext();
          counter++;
        }
        cout << counter + 1 << endl;
        temp->InsertAfter(newone);
        if (isTail){                    //if newpos is tail
          tail = newone;
        }
      }
      space
    }
  }

  else if (menuOption == 'z') //testing option
  {
    cout << "test" << endl;
  }

  
  PrintMenu(songListName);


}