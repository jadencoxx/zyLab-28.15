//Jaden Cox and Anna Leo

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
   if(option == 't'){
         cout << "OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)" << endl;
         int totalTime = 0;
         PlaylistNode* curr = headNode;

            while (curr != nullptr){
               totalTime += curr->GetSongLength();
               curr = curr->GetNext();
            }
               cout << "Total time: " << totalTime << " seconds" << endl;
      }
      
      if(option == 'o'){
         cout << playlistTitle << " - OUTPUT FULL PLAYLIST" << endl; 
         if (headNode == nullptr)
            cout << "Playlist is empty" << endl;
         else{
            int position = 1;
            PlaylistNode* curr = headNode;
            curr = curr->GetNext();
            while(curr != nullptr){
               cout << position << "." << endl;
               curr->PrintPlaylistNode();
               curr = curr->GetNext();
               position++;
               if(curr != nullptr)
                  cout << endl;
            }
         }
      }
   return headNode;     
   
}

int main() {
   string playlistTitle;
   
   cout << "Enter playlist's title:" << endl;
   getline(cin, playlistTitle);
   
   PlaylistNode* headNode = nullptr;
   
   char option;
   do{
      PrintMenu(playlistTitle);
      cout << endl << "Choose an option:" << endl;
      cin >> option;
      cin.ignore();

      headNode = ExecuteMenu(option, playlistTitle, headNode);
   } while (option != 'q');
   
   return 0;
}
