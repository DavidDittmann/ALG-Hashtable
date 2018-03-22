#ifndef HASHINGFUNCTIONS_H_INCLUDED
#define HASHINGFUNCTIONS_H_INCLUDED

#define SIZE 1000 //Muss auch in main.cpp geändert werden!

#include <sstream>

using namespace std;

class Hashtable
{
    private:
        bool state;
        string name;
        int IndexOther;
        string filename;
        string WKN;
    public:
        bool getState(void) const;
        void setState(bool s);
        string getName(void) const;
        void setName(string str);
        int getIndex(void) const;
        void setIndex(int i);
        string getFilename(void) const;
        void setFilename(string str);
        string getWKN(void) const;
        void setWKN(string str);

        Hashtable()//Constructor
        {
            state=true;
            name="";
            IndexOther=-1;
            filename="";
        }


};

void HT_init(void);
void HT_kill(void);

int HashFunction(string &str);

void NewHTEntry(int index, int indexother, string &name, string &WKN, bool decide);
int CollisionDetectAdd(int index, string &name, bool decide, int offset);
int CollisionDetectSEARCH(int index,string str,bool decide, int offset);


#endif // HASHINGFUNCTIONS_H_INCLUDED
