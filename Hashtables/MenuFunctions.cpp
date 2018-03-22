#include "MenuFunctions.h"
#include "FileIO.h"
#include "HashingFunctions.h"
#include <iostream>
#include <string>

using namespace std;

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

void SEARCH()
{
    int index;
    char input;
    string str;
    cout<<"Suche Eintrag nach (K)uerzel oder (V)ollname:"<<endl;
    cin>>input;
    do
    {
        if(input=='v'||'V')
        {
            cout<<"Vollname eingeben: "<<endl;cin>>str;
            index=HashFunction(str);
            index=CollisionDetectSEARCH(index,str,true,0);//Vollname Hashtable Suche
            if(index<0)
                cout<<"Eintrag nicht gefunden"<<endl;
            else
            {
                LastO(index,true);
            }
        }
        else if(input=='k'||'K')
        {
            cout<<"Kuerzel eingeben: "<<endl;cin>>str;
            index=HashFunction(str);
            index=CollisionDetectSEARCH(index,str,false,0);//Kuerzel Hashtable Suche
            if(index<0)
                cout<<"Eintrag nicht gefunden"<<endl;
            else
            {
                LastO(index,true);
            }
        }
        else
        {
            cout<<"Eingabe nicht erkannt"<<endl;
        }
    }while(input!='k'||'K'||'v'||'V');

}
