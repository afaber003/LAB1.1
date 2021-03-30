#ifndef PLAYLIST_H
#define PLAYLIST_H
#include <string>

using namespace std;

class PlaylistNode {
    
    public: 
        PlaylistNode();
        PlaylistNode(string& title, string& artist, int length, string& ID, PlaylistNode* next) : //paramatized constructor
            nextNodePtr(next), songLength(length), songTitle(title), uniqueID(ID), artistName(artist){};
        

    
    
    
    private:
        PlaylistNode* nextNodePtr;
        int songLength;
        string songTitle;
        string uniqueID;
        string artistName;
};


#endif