#include "FileIO.h"
#include "HashingFunctions.h"
#include "MenuFunctions.h"
#include <sstream>
#include <string>
#include <iostream>

Hashtable* Longname[1000];//PointerArray der Klasse Hashtable
Hashtable* Kuerzel[1000];

void HT_init()
{
    for(int i=0;i<1000;i++)//Allozieren des Speichers
    {
        Longname[i]=new Hashtable;
        Kuerzel[i]=new Hashtable;
    }
}

//Funktionen zum Auslesen der Instanzdaten
bool Hashtable::getState(void) const
{
    return this->state;
}
string Hashtable::getName(void) const
{
    return this->name;
}
int Hashtable::getIndex(void) const
{
    return this->IndexOther;
}
string Hashtable::getFilename(void) const
{
    return this->filename;
}
string Hashtable::getWKN(void) const
{
    return this->WKN;
}


//Funktionen zum Schreiben der Instanzdaten
void Hashtable::setState(bool s)
{
    this->state=s;
}

void Hashtable::setName(string str)
{
    this->name=str;
}

void Hashtable::setIndex(int i)
{
    this->IndexOther=i;
}

void Hashtable::setFilename(string str)
{
    this->filename=str;
}
void Hashtable::setWKN(string str)
{
    this->WKN=str;
}


//Hashfunktion
int HashFunction(string &str)
{
    int hashvalue;
    int seed = 127;
    unsigned long z = 0;
    for(int i = 0; i < (int)str.length(); i++)
    {
        z = (z * seed) + str[i];
    }
    hashvalue=z%SIZE;
    return hashvalue;
}

void NewHTEntry(int index, int indexother, string &name, string &WKN, bool decide)
{
    index=CollisionDetectAdd(index,name,decide,0);
    if(decide==true)
    {
        Longname[index]->setName(name);
        Longname[index]->setWKN(WKN);
        Longname[index]->setIndex(indexother);
    }
    else
    {
        Kuerzel[index]->setName(name);
        Kuerzel[index]->setWKN(WKN);
        Kuerzel[index]->setIndex(indexother);
    }
}

int CollisionDetectAdd(int index, string &name, bool decide, int offset)
{
    int indexO=index;
    index+=(offset*offset);
    if(decide==true)
    {
        if(Longname[index]->getState()==true)//Eintrag Gültig oder Leer
        {
            if(Longname[index]->getName()==""||Longname[index]->getName()==name)
            {
                return index;
            }
            else
            {
                offset++;
                return CollisionDetectAdd(indexO,name,decide,offset);
            }
        }
        else//Eintrag ungültig
        {
            return index;
        }
    }
    else
    {
        if(Kuerzel[index]->getState()==true)//Eintrag Gültig oder Leer
        {
            if(Kuerzel[index]->getName()==""||Kuerzel[index]->getName()==name)
            {
                return index;
            }
            else
            {
                offset++;
                return CollisionDetectAdd(indexO,name,decide,offset);
            }
        }
        else//Eintrag ungültig
        {
            return index;
        }
    }
}

void ADD()
{
    string name,kuerzel,wkn;
    int hashN, hashK;
    cout<<"Geben Sie den Namen, das Kuerzel und die WKN-Nr. der Aktie an:"<<endl;
    cout<<"Name: ";     cin>>name;
    cout<<"Kuerzel: ";  cin>>kuerzel;
    cout<<"WKN";        cin>>wkn;
    hashN=HashFunction(name);
    hashK=HashFunction(kuerzel);
    NewHTEntry(hashN,hashK,name,wkn,true);//True bei Name-, False bei Kuerzel-Tabelle
    NewHTEntry(hashK,hashN,kuerzel,wkn,false);
}
