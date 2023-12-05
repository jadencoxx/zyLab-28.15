#ifndef PLAYLIST_H
#define PLAYLIST_H
#include <string>

using namespace std;

class PlaylistNode {
private:
   string uniqueID;
   string songName;
   string artistName;
   int songLength;
   PlaylistNode* nextNodePtr;
   
public:
   PlaylistNode();
   PlaylistNode(string ID, string sName, string aName, int length);
   string GetID();
   string GetSongName();
   string GetArtistName();
   int GetSongLength();
   PlaylistNode* GetNext();
   void InsertAfter(PlaylistNode* nodePtr);
   void SetNext(PlaylistNode* nodePtr);
   void PrintPlaylistNode();
};

#endif
