#define SIZE 1000 //Muss auch in HashingFunctions.h geändert werden!

#include "FileIO.h"
#include "HashingFunctions.h"
#include "MenuFunctions.h"
#include <iostream>

using namespace std;

int main()
{
    int i;
    Hashtable* Longname[SIZE];//PointerArray der Klasse Hashtable
    Hashtable* Kuerzel[SIZE];


    for(i=0;i<SIZE;i++)//Allozieren des Speichers
    {
        Longname[i]=new Hashtable;
        Kuerzel[i]=new Hashtable;
    }

    Longname[1]->setIndex(1);//ansprechen einer Objekteigenschaft
    cout<<Longname[1]->getIndex()<<endl;


    string str="Hallo";

    cout<<HashFunction(str);

    for(i=0;i<1000;i++) //Freigabe des Speichers
    {
        delete(Longname[i]);
        delete(Kuerzel[i]);
    }
    return 0;
}
