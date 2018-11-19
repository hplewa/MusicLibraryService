#include "MyLinkedList.h"
#include <iostream>
#include <fstream>
using namespace std;
int main(int argc, char** args){
    auto list = new MyLinkedList();
    char cmd;
    // Repeat until user enters q
    while (cmd != 'q'){
        cout << "Enter a command: " << endl 
        << "(q to quit)" << endl 
        << "(l to list clips)" << endl
        << "(c to ceate a clip)" << endl
        << "(y to copy the current clip)" << endl
        << "(p to change the current clip price)" << endl
        << "(s to save all clips to a file (data.txt)" << endl;
        cin >> cmd;
        if (cmd == 'l'){
            /*
            List  all  music  clips. 
            Each clip is read from its file and its information (ID, Genre, etc.) is displayed in the user’s screen. 
            All fields are displayed except for the clip field. MusicClip instances are written back to files and 
            deleted from memory as needed to keep a maximum of three total memory clips in memory at all times.
            */
           list->print();
        }
        else if (cmd == 'e'){
            /*
            Edit a MusicClip instance.   
            This command sets the numbered MusicClip to be the current clip.  
            If the clip is not already in memory, it is read from file and assigned to the corresponding MusicClipPtr instance.  
            In this case, a MusicClip instance currently in memory may have to be written back into its corresponding file 
            and deleted from memory not to exceed the limit of 3 music clips.
            */
            //MusicClipPtr* mc = list->pop();
        }
        else if (cmd == 'c'){
            /*
            Create a music clip.  The user is prompted for the various fields in the new clip instance.  The
            clip is then written to a file and associated with smart pointer instance.  The clip’s ID must be
            between 0 and 9.  If a clip with the same ID existed before this clip is created,  the older clip is
            deleted from both memory and the associated file.
            */
            int id;
            string artist;
            int genre;
            BandMembers* people;
            char* clip = nullptr;
            int price;
            cout << "Enter an id (0-9): " << endl;
            cin >> id;
            cout << "Enter an artist name (no spaces): " << endl;
            cin >> artist;
            cout << "Enter a genre (POP_MUSIC, FOLK_MUSIC, JAZZ, BLUES, CLASSICAL, OPERA, COUNTRY_MUSIC, REGGAE, ROCK) or (0-8): " << endl;
            cin >> genre;
            cout << "Enter band member names (no spaces), 0 when done: " << endl;
            vector<string> names = vector<string>();
            string name = "";
            cin >> name;
            while(name != "0"){
                names.push_back(name);
                cin >> name;
            }
            people = new BandMembers(names);
            cout << "Enter a price (integer in cents): " << endl;
            cin >> price;

            MusicClipPtr* mc = new MusicClipPtr(id, artist, Genre(genre), people, clip, price);
            list->add(mc); 
        }
        else if (cmd == 'y'){
            /*
            Copy the current clip.  The current clip is deep copied and stored to a temporary file in the
            current directory called “temp.clip”.
            */
           MusicClipPtr* mc = list->pop();
           ofstream myfile;
           myfile.open("data.txt");
           string s = mc->toString();
           myfile << s;
           myfile << "\n";
           myfile.close();
        }
        else if (cmd == 'i'){
            /*
            Read commands from file.  This command reads and executes a sequence of commands from a
            file in the current directory.  The file is called “input.inp”.  All commands in this list can appear in
            the file, one command per line, except for the i command.
            */
        }
        else if (cmd == 'p'){
            /*
            This  command  changes  the  price  of  the  current  music  clip.   The  user  is  prompted  for  a  new
            number, which becomes the new price of the clip.  The current clip is not saved to file as part of
            this command.  The new content of current clip is displayed in the user’s screen.  The new price will
            be saved when the music clip instance is written back to its file.
            */
           int price;
           cout << "Enter a price: " << endl;
           cin >> price;
           MusicClipPtr* cur = list->pop();
           cur->setPrice(price);
           list->add(cur);
        }
        else if (cmd == 's'){
            /*
            Save all clips.  This command save the clip(s) currently in memory to the corresponding file(s).
            First, the files are deleted (e.g., using the remove() function).  
            Next, an ofstream instance is opened on the named file, 
            and the clip’s information is saved to the new file.  Finally, the stream is closed.
            */
           ofstream myfile;
           myfile.open("data.txt");
           while(!list->empty()){
               MusicClipPtr* mc = list->pop();
               string s = mc->toString();
                myfile << s;
           }
           myfile << "\n";
           myfile.close();
        }
    }
}