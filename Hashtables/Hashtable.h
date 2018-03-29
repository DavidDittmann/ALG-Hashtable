#ifndef HASHTABLE_H_INCLUDED
#define HASHTABLE_H_INCLUDED
#include <string>
#include <iostream>

using namespace std;

typedef struct Data{
    string Date;
    double Open;
    double High;
    double Low;
    double Close;
    double Volume;
    double AdjClose;
}Data;

class Entry{
    private:
        bool State;
        string Name;
        string Kuerzel;
        string WKN;
    public:
        Data DataSet[30];
        Entry()
        {
            State=true;
            Name="";
            Kuerzel="";
            WKN="";
            //cout<<"Entry erstellt"<<endl;
        }
        ~Entry()
        {
            //cout<<"Entry zerstört"<<endl;
        }
        void setName(string &str);
        void setKuerzel(string &str);
        void setWKN(string &str);
        void setState(bool s);
        string getName(void);
        string getKuerzel(void);
        string getWKN(void);
        bool getState(void);
};

class Kuerzel{
    private:
        string Kurz;
        Entry* Referenz;
    public:
        Kuerzel()
        {
            Kurz="";
            Referenz=NULL;
            //cout<<"Kuerzeleintrag erstellt"<<endl;
        }
        ~Kuerzel()
        {
            //cout<<"Kuerzeleintrag zerstört"<<endl;
        }
        void setKuerzel(string &str);
        void setReferenz(Entry* pt);
        Entry* getReferenz(void);
        string getKuerzel(void);
};

int HashFunc(string &str);



#endif // HASHTABLE_H_INCLUDED
