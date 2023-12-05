#include "PlaylistNode.h"
#include <iostream>

using namespace std;

PlaylistNode::PlaylistNode(string ID, string sName, string aName, int length){
   uniqueID = ID;
   songName = sName;
   artistName = aName;
   songLength = length;
   nextNodePtr = 0;
}

string PlaylistNode::GetID(){
   return uniqueID;
}

string PlaylistNode::GetSongName(){
   return songName;
}

string PlaylistNode::GetArtistName(){
   return artistName;
}

int PlaylistNode::GetSongLength(){
   return songLength;
}

PlaylistNode* PlaylistNode::GetNext(){
   return nextNodePtr;
}

void PlaylistNode::InsertAfter(PlaylistNode* nodePtr){
   PlaylistNode* tmp = nextNodePtr;
   nextNodePtr = nodePtr;
   nodePtr->nextNodePtr = tmp;
}

void PlaylistNode::SetNext(PlaylistNode* nodePtr){
   nextNodePtr = nodePtr;
}

void PlaylistNode::PrintPlaylistNode(){
   cout << "Unique ID: " << uniqueID << endl;
   cout << "Song Name: " << songName << endl;
   cout << "Artist Name: " << artistName << endl;
   cout << "Song Length (in seconds): " << songLength << endl;
}

