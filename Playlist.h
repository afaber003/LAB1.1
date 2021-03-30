#ifndef PLAYLIST_H
#define PLAYLIST_H
#include <string>

using namespace std;

class PlaylistNode {
    
    public: 
        PlaylistNode();
        //paramatized constructor
        PlaylistNode(string& title, string& artist, int length, string& ID, PlaylistNode* next) : 
          nextNodePtr(next), songLength(length), songTitle(title), uniqueID(ID), artistName(artist){};
        void InsertAfter();
        void SetNext(); //Mutator 
        string GetID() const; //Accessor 
        string GetSongName() const; //Accessor
        string GetArtistName() const; //Accessor
        int GetSongLength() const; //Accessor
        PlaylistNode* GetNext() const; //Accessor
        void PrintPlaylistNode();
        

    
    
    
    private:
        PlaylistNode* nextNodePtr;
        int songLength;
        string songTitle;
        string uniqueID;
        string artistName;
};


#endif