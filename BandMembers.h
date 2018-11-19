#include <iostream>
#include <vector>
#include <string>
using namespace std;
class BandMembers{
    private:
        vector<string> memberNames;
    public:
        BandMembers(): memberNames(vector<string>()){} //Default constructor
        BandMembers(vector<string> members): memberNames(members){}
        vector<string> getMemberNames(){
            return memberNames;
        }
        void setMemberNames(vector<string> members){
            memberNames = members;
        }
        string toString(){
            string s = "";
            for(auto m: memberNames){
                s.append(m);
                s.append(" ");
            }
            return s;
        }
};