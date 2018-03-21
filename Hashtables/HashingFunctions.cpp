#include "FileIO.h"
#include "HashingFunctions.h"
#include "MenuFunctions.h"
#include <sstream>
#include <string>
#include <iostream>


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
