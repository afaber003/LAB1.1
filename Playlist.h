#ifndef PLAYLIST_H
#define PLAYLIST_H
#include <string>

using namespace std;

class PlaylistNode {
    
    public: 
        PlaylistNode();
        

    
    
    
    private:
        PlaylistNode* nextNodePtr;
        int songLength;
        string songTitle;
        string uniqueID;
        string artistName;
};


#endif