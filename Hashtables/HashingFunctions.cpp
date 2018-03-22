#include "HashingFunctions.h"
#include <sstream>
#include <string>
#include <iostream>



void HT_init()
{
    for(int i=0;i<1000;i++)//Allozieren des Speichers
    {
        Longname[i]=new Hashtable;
        Kuerzel[i]=new Hashtable;
    }
}

void HT_kill()
{
    for(int i=0;i<1000;i++)//Allozieren des Speichers
    {
        delete(Longname[i]);
        delete(Kuerzel[i]);
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
        Longname[index]->setState(true);
    }
    else
    {
        Kuerzel[index]->setName(name);
        Kuerzel[index]->setWKN(WKN);
        Kuerzel[index]->setIndex(indexother);
        Kuerzel[index]->setState(true);
    }
}

int CollisionDetectAdd(int index, string &name, bool decide, int offset)
{
    int indexO=index;
    index=(index+(offset*offset))%1000;//Modulo SIZE!!!!
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

int CollisionDetectSEARCH(int index,string str,bool decide,int offset)
{
    int indexO=index;
    index=(index+(offset*offset))%1000;
    if(decide==true)
    {
        if(Longname[index]->getState()==true)
        {
            if(Longname[index]->getName()=="")
                return -1;
            else if(Longname[index]->getName()!=str)
            {
                offset++;
                return CollisionDetectSEARCH(indexO,str,decide,offset);
            }
            else if(Longname[index]->getName()==str)
            {
                return index;
            }
        }
        else
        {
            offset++;
            return CollisionDetectSEARCH(indexO,str,decide,offset);
        }
    }
    else
    {
        if(Kuerzel[index]->getState()==true)
        {
            if(Kuerzel[index]->getName()=="")
                return -1;
            else if(Kuerzel[index]->getName()!=str)
            {
                offset++;
                return CollisionDetectSEARCH(indexO,str,decide,offset);
            }
            else if(Kuerzel[index]->getName()==str)
            {
                return index;
            }
        }
        else
        {
            offset++;
            return CollisionDetectSEARCH(indexO,str,decide,offset);
        }
    }
    return -1;
}


