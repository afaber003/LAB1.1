#ifndef PLAYLIST_H
#define PLAYLIST_H
#include <string>

using namespace std;

class PlaylistNode {
    
    public: 
        PlaylistNode();
        PlaylistNode(string& title, string& artist, int length, string& ID, PlaylistNode* next) : //paramatized constructor
            nextNodePtr(next), songLength(length), songTitle(title), uniqueID(ID), artistName(artist){};
        void InsertAfter();
        void SetNext(); //Mutator 
        string GetID(); //Accessor 
        string GetSongName(); //Accessor
        string GetArtistName(); //Accessor
        int GetSongLength(); //Accessor
        PlaylistNode* GetNext(); //Accessor
        void PrintPlaylistNode();
        

    
    
    
    private:
        PlaylistNode* nextNodePtr;
        int songLength;
        string songTitle;
        string uniqueID;
        string artistName;
};


#endif