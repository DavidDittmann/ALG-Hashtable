#include "HashingFunctions.h"
#include "MenuFunctions.h"
#include "FileIO.h"
#include <string>
#include <iostream>
#include <sstream>

void LastEntry(int index,bool decide)//Ausgabe letzter Kurstag der Aktie
{//decide=true -> Hashtable "Longname"; decide=false -> Hashtable "Kuerzel"
    string filename;

    if(decide==true)
        filename=Longname[index]->getFilename();
    else
        filename=Kuerzel[index]->getFilename();
    //
    //Ausgabe der letzten Tageskurs Daten aus dem File !!!FEHLT!!!!
    //
}
