#include <iostream>
#include <fstream>
#include "Playlist.h"

using namespace std;


PlaylistNode* head = nullptr;
PlaylistNode* tail = nullptr;


void addSong();
void PrintMenu(string);

int main(){

  string playlistName;
  cout << "Enter playlist's title:" << endl;
  getline(cin, playlistName);
  cout << endl;
  PrintMenu(playlistName);


    return 0;
}

void PrintMenu(string songlistName)
{
  char menuOption;
  cout << songlistName << " PLAYLIST MENU" << endl;
  cout << "a - Add song" << endl;
  cout << "d - Remove song" << endl;
  cout << "c - Change position of song" << endl;
  cout << "s - Output songs by specific artist" << endl;
  cout << "t - Output total time of playlist (in seconds)" << endl;
  cout << "o - Output full playlist" << endl;
  cout << "q - Quit" << endl;

  cout << endl;
  cout << "Choose an option: " << endl;
  cin >> menuOption;
  cout << endl;

  
  if (menuOption == 'q')
  {
    return;
  }
  else if (menuOption == 'a'){

    
    // User Input
    string tempid = "";
    cout << "Enter song's unique ID: " << endl;
    cin >> tempid;
    cout << endl;
    string tempname = "";
    cout << "Enter song's name: " << endl;
    getline(cin, tempname);
    cout << endl;
    string tempartist;
    cout << "Enter artist's name: " << endl;
    getline(cin, tempartist);
    int templength;
    cout << "Enter song's length (in seconds): " << endl;
    cin >> templength;

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
          delete curr;
        }
        break;
      }
      curr = curr->GetNext();
    }


  }
  else if (menuOption == 't') //testing option
  {
    cout << "test" << endl;
  }

  PrintMenu(songlistName);

}