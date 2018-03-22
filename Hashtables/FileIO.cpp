#include "FileIO.h"
#include "HashingFunctions.h"
#include <string>
#include <iostream>

using namespace std;

void LastO(int index,bool decide)//Ausgabe letzter Kurstag der Aktie
{   //decide=true -> Hashtable "Longname"; decide=false -> Hashtable "Kuerzel"
    string file;

    if(decide==true)
        file=Longname[index]->getFilename();
    else
        file=Kuerzel[index]->getFilename();
    //
    //Ausgabe der letzten Tageskurs Daten aus dem File !!!FEHLT!!!!
    //
}
