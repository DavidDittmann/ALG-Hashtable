#define SIZE 1000 //Muss auch in HashingFunctions.h geändert werden!

#include "FileIO.h"
#include "HashingFunctions.h"
#include "MenuFunctions.h"
#include <iostream>

using namespace std;

int main()
{
    Hashtable* Longname[1000];//PointerArray der Klasse Hashtable
    Hashtable* Kuerzel[1000];

    HT_init();
    string str="Hallo";

    cout<<HashFunction(str);

    HT_kill();
    return 0;
}
