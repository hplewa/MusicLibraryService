#include "MyLinkedList.h"
#include <iostream>
using namespace std;
int main(int argc, char** args){
    auto list = new MyLinkedList<int>();
    list->add(0);
    list->print();
    return 0;

    char cmd;
    // Repeat until user enters q
    while (cmd != 'q'){
        if (cmd == 'l'){
            /*
            List  all  music  clips. 
            Each clip is read from its file and its information (ID, Genre, etc.) is displayed in the user’s screen. 
            All fields are displayed except for the clip field. MusicClip instances are written back to files and 
            deleted from memory as needed to keep a maximum of three total memory clips in memory at all times.
            */
        }
        else if (cmd == 'e'){
            /*
            Edit a MusicClip instance.   
            This command sets the numbered MusicClip to be the current clip.  
            If the clip is not already in memory, it is read from file and assigned to the corresponding MusicClipPtr instance.  
            In this case, a MusicClip instance currently in memory may have to be written back into its corresponding file 
            and deleted from memory not to exceed the limit of 3 music clips.
            */
        }
        else if (cmd == 'c'){
            /*
            Create a music clip.  The user is prompted for the various fields in the new clip instance.  The
            clip is then written to a file and associated with smart pointer instance.  The clip’s ID must be
            between 0 and 9.  If a clip with the same ID existed before this clip is created,  the older clip is
            deleted from both memory and the associated file.
            */
        }
        else if (cmd == 'y'){
            /*
            Copy the current clip.  The current clip is deep copied and stored to a temporary file in the
            current directory called “temp.clip”.
            */
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
        }
        else if (cmd == 's'){
            /*
            Save all clips.  This command save the clip(s) currently in memory to the corresponding file(s).
            First, the files are deleted (e.g., using the remove() function).  
            Next, an ofstream instance is opened on the named file, 
            and the clip’s information is saved to the new file.  Finally, the stream is closed.
            */
        }
    }
}