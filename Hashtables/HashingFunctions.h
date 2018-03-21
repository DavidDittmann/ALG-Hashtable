#ifndef HASHINGFUNCTIONS_H_INCLUDED
#define HASHINGFUNCTIONS_H_INCLUDED

#define SIZE 1000 //Muss auch in main.cpp geändert werden!

#include <sstream>
#include <iostream>

using namespace std;

class Hashtable
{
    private:
        bool state;
        string name;
        int IndexOther;
        string filename;
    public:
        bool getState(void) const;
        void setState(bool s);
        string getName(void) const;
        void setName(string str);
        int getIndex(void) const;
        void setIndex(int i);
        string getFilename(void) const;
        void setFilename(string str);

        Hashtable()//Constructor
        {
            state=true;
            name="";
            IndexOther=-1;
            filename="";
        }


};

int HashFunction(string &str);


#endif // HASHINGFUNCTIONS_H_INCLUDED
