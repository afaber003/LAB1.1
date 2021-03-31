#ifndef PLAYLIST_H
#define PLAYLIST_H
#include <string>

using namespace std;

class PlaylistNode {
    
    public: 
        PlaylistNode();
        //paramatized constructor
        PlaylistNode(string& ID, string& title, string& artist, int length, PlaylistNode* next = nullptr) :
          songLength(length), songTitle(title), uniqueID(ID), artistName(artist){nextNodePtr = next;};
        void InsertAfter(PlaylistNode* );
        void SetNext(PlaylistNode* ); //Mutator 
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