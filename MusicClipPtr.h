#include <string>
#include "BandMembers.h"
using namespace std;
enum Genre {POP_MUSIC, FOLK_MUSIC, JAZZ, BLUES, CLASSICAL, OPERA, COUNTRY_MUSIC, REGGAE, ROCK};
string GenreToString[9] = {"POP_MUSIC", "FOLK_MUSIC", "JAZZ", "BLUES", "CLASSICAL", "OPERA", "COUNTRY_MUSIC", "REGGAE", "ROCK"};
class MusicClipPtr{
    private:
        class MusicClip{
            public:
            int ID;
            string Artist;
            Genre genre;
            BandMembers* People;
            char* Clip;
            int Price;
            MusicClip(): ID(0), Artist(""), genre(POP_MUSIC), People(new BandMembers()), Clip(nullptr), Price(0){} //Default constructor

            MusicClip(int id): ID(id), Artist(""), genre(POP_MUSIC), People(new BandMembers()), Clip(nullptr), Price(0){}

            MusicClip(int id, string artist, enum Genre genre, BandMembers* people, char* clip, int price): ID(id), Artist(artist), genre(genre), People(people), Clip(clip), Price(price){}

            string toString(){
                string s = "";
                s.append(to_string(ID));
                s.append("\n");
                s.append(Artist);
                s.append("\n");
                s.append(GenreToString[genre]);
                s.append("\n");
                s.append(People->toString());
                s.append("\n");
                s.append(to_string(Price));
                s.append("\n");
                return s;
            }      
        }; //End MusicClip
        MusicClip* musicClip;
        //static MusicClipFile musicClipIndex("musicClipIndexData");
        static int CACHE_SIZE;
        //static MusicClipCache cache(CACHE_SIZE);
    public:
        //Default constructor
        MusicClipPtr(void): musicClip(new MusicClip()){}

        MusicClipPtr(int id, string artist = "", Genre genre = POP_MUSIC, BandMembers* people = new BandMembers(), char* clip = nullptr, int price = 0): musicClip(new MusicClip(id, artist, genre, people, clip, price)){} 

        string toString(){
            return musicClip->toString();
        }

        //Setters
        void setPrice(int price){
            musicClip->Price = price;
        }
};