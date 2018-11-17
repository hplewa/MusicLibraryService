#include <iostream>
#include <string>
#include "BandMembers.h"
using namespace std;
class MusicClip{
    private:
        int ID;
        string Artist;
        enum Genre {POP_MUSIC, FOLK_MUSIC, JAZZ, BLUES, CLASSICAL, OPERA, COUNTRY_MUSIC, REGGAE, ROCK};
        Genre Genre;
        BandMembers People;
        char* Clip;
        int Price;
    public:
        MusicClip(): ID(0), Artist(""), Genre(POP_MUSIC), People(), Clip(nullptr), Price(0){} //Default constructor
        MusicClip(int id, string artist, enum Genre genre, BandMembers people, char* clip, int price):
        ID(id), Artist(artist), Genre(genre), People(people), Clip(clip), Price(price){}
        string toString(){
            string s = "";
            return s;
        }      
};