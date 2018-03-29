#include "Hashtable.h"
#include <string>
#include <iostream>

using namespace std;

//-----HASHINGFUNKTION-----
int HashFunc(string &str)
{
    int hashvalue, seed = 127;
    unsigned long z = 0;
    for(int i = 0; i < (int)str.length(); i++)
    {
        z = (z * seed) + str[i];
    }
    hashvalue=z%1000;
    return hashvalue;
}

//-----CLASS ENTRY FUNKTIONEN-----
void Entry::setName(string &str)
{
    Name=str;
}
void Entry::setKuerzel(string &str)
{
    Kuerzel=str;
}
void Entry::setWKN(string &str)
{
    WKN=str;
}
void Entry::setState(bool s)
{
    State=s;
}
string Entry::getName(void)
{
    return Name;
}
string Entry::getKuerzel(void)
{
    return Kuerzel;
}
string Entry::getWKN(void)
{
    return WKN;
}
bool Entry::getState(void)
{
    return State;
}


//-----CLASS KUERZEL FUNKTIONEN------
void Kuerzel::setKuerzel(string &str)
{
    Kurz=str;
}
void Kuerzel::setReferenz(Entry* pt)
{
    Referenz = pt;
}
Entry* Kuerzel::getReferenz(void)
{
    return Referenz;
}
string Kuerzel::getKuerzel(void)
{
    return Kurz;
}
