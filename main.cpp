#include <iostream>
#include "PlaylistNode.h"

using namespace std;

void PrintMenu(const string playlistTitle) {
   cout << endl << playlistTitle << " PLAYLIST MENU" << endl;
   cout << "a - Add song" << endl;
   cout << "d - Remove song" << endl;
   cout << "c - Change position of song" << endl;
   cout << "s - Output songs by specific artist" << endl;
   cout << "t - Output total time of playlist (in seconds)" << endl;
   cout << "o - Output full playlist" << endl;
   cout << "q - Quit" << endl;
}

PlaylistNode* ExecuteMenu(char option, string playlistTitle, PlaylistNode* headNode) {
   if(option == 'a'){
         string uniqueID, songName, artistName;
         int songLength;
         
         if(headNode == nullptr)
            headNode = new PlaylistNode();
           
         PlaylistNode* curr = nullptr;
         PlaylistNode* last = headNode;
         
         while(last->GetNext() != nullptr){
            last = last->GetNext();
         }

         cout << "ADD SONG" << endl;
         cout << "Enter song's unique ID:" << endl;
         getline(cin, uniqueID);

         cout << "Enter song's name:" << endl;
         getline(cin, songName);

         cout << "Enter artist's name:" << endl;
         getline(cin, artistName);

         cout << "Enter song's length (in seconds):" << endl;
         cin >> songLength;

         curr = new PlaylistNode(uniqueID, songName, artistName, songLength);
         last->InsertAfter(curr);
      }
       
      if (option == 'd') {
      cout << "REMOVE SONG" << endl;
      string deleteID;
      cout << "Enter song's unique ID:" << endl;
      cin >> deleteID;
   
      PlaylistNode* prev = nullptr;
      PlaylistNode* curr = headNode;
   
      while (curr != nullptr && curr->GetID() != deleteID) {
         prev = curr;
         curr = curr->GetNext();
      }
   
      if (curr == nullptr)
         cout << "\"" << deleteID << "\" not found." << endl;
      else {
         if (prev != nullptr)
            prev->SetNext(curr->GetNext());
         else
            headNode = curr->GetNext();
   
         cout << "\"" << curr->GetSongName() << "\" removed." << endl;
         delete curr;
      }
   }
       
      if(option == 's'){
            cout << "OUTPUT SONGS BY SPECIFIC ARTIST" << endl;
            string artistName;
            cout << "Enter artist's name:" << endl;
            getline(cin, artistName);

            int position = 1;
            PlaylistNode* curr = headNode;
            curr = curr->GetNext();

            while(curr != nullptr){
               if(curr->GetArtistName() == artistName){
                  cout << endl << position << "." << endl;
                  curr->PrintPlaylistNode();
               }
               position++;
               curr = curr->GetNext();
            }
      }
       
   
}

int main() {
   /* Type your code here */
   
   return 0;
}
