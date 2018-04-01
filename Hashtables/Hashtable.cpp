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
    this->Name=str;
}
void Entry::setKuerzel(string &str)
{
    this->Kuerzel=str;
}
void Entry::setWKN(string &str)
{
    this->WKN=str;
}
void Entry::setState(bool s)
{
    this->State=s;
}
string Entry::getName(void)
{
    return this->Name;
}
string Entry::getKuerzel(void)
{
    return this->Kuerzel;
}
string Entry::getWKN(void)
{
    return this->WKN;
}
bool Entry::getState(void)
{
    return this->State;
}


//-----CLASS KUERZEL FUNKTIONEN------
void Kuerzel::setKuerzel(string &str)
{
    this->Kurz=str;
}
void Kuerzel::setReferenz(Entry* pt)
{
    this->Referenz = pt;
}
Entry* Kuerzel::getReferenz(void)
{
    return this->Referenz;
}
string Kuerzel::getKuerzel(void)
{
    return this->Kurz;
}
void Kuerzel::setState(bool s)
{
    this->State=s;
}
bool Kuerzel::getState(void)
{
    return this->State;
}


int CollisionDetectHT(string &N,int OriginalIndex,Entry HT[],int offset)
{
    int I=OriginalIndex+(offset*offset);
    int ret;

    if(HT[I].getState())//Eintrag Gültig (TRUE)
    {
        if(HT[I].getName()==""||HT[I].getName()==N)
        {
            ret=I%1000;
        }
        else
        {
            offset++;
            ret=CollisionDetectHT(N,OriginalIndex,HT,offset);
        }
    }
    else
    {
        ret=I%1000;
    }
    return ret;
}
int CollisionDetectKU(string &K,int OriginalIndex,Kuerzel KU[],int offset)
{
    int I=OriginalIndex+(offset*offset);
    int ret;

    if(KU[I].getState())//Eintrag Gültig (TRUE)
    {
        if(KU[I].getKuerzel()==""||KU[I].getKuerzel()==K)
        {
            ret=I%1000;
        }
        else
        {
            offset++;
            ret=CollisionDetectKU(K,OriginalIndex,KU,offset);
        }
    }
    else
    {
        ret=I%1000;
    }
    return ret;
}


