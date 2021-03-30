#ifndef PLAYLIST_H
#define PLAYLIST_H
#include <string>

using namespace std;

class PlaylistNode {
    
    public: 
        PlaylistNode();
        PlaylistNode(string& title, string& artist, int length, string& ID, PlaylistNode* next) : //paramatized constructor
            nextNodePtr(next), songLength(length), songTitle(title), uniqueID(ID), artistName(artist){};
        InsertAfter();
        SetNext(); //Mutator 
        GetID(); //Accessor 
        GetSongName() //Accessor
        GetArtistName() //Accessor
        GetSongLength() //Accessor
        GetNext() //Accessor
        PrintPlaylistNode()
        

    
    
    
    private:
        PlaylistNode* nextNodePtr;
        int songLength;
        string songTitle;
        string uniqueID;
        string artistName;
};


#endif