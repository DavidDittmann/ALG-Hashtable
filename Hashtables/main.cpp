#include "Hashtable.h"
#include "MenuFunctions.h"
#include <iostream>

using namespace std;

int main()
{
    string N,K,W,filename;
    //-----------------------Initialisierung der Hash-Tabellen------------------------------
    Entry* Hashtable=new Entry[1000];
    Kuerzel* Kurztable=new Kuerzel[1000];

    cout<<"Name: ";cin>>N;
    cout<<"Kurz: ";cin>>K;
    cout<<"WKN: ";cin>>W;

    ADD(N,K,W,Hashtable,Kurztable);
    ADD(N,K,W,Hashtable,Kurztable);//Bei selben Namen wird überschrieben


    /*int i=HashFunc(N);
    Hashtable[i].DataSet[0].Open=1;
    Hashtable[i].DataSet[0].Close=2;
    Hashtable[i].DataSet[0].High=3;
    Hashtable[i].DataSet[0].Low=4;
    Hashtable[i].DataSet[0].AdjClose=5;
    Hashtable[i].DataSet[0].Volume=6;
    Hashtable[i].DataSet[0].Date="01.04.2018";*/

    cout<<"IMPORT CSV - Absoluter Pfad: ";cin>>filename;
    IMPORT(filename,Hashtable,Kurztable,N,true);

    SEARCH(N,Hashtable,Kurztable,true);
    SEARCH(K,Hashtable,Kurztable,false);

    DEL(N,Hashtable,Kurztable,true);
    DEL(N,Hashtable,Kurztable,true);





    //--------------------------------Freigeben der Tabellen------------------------------
    delete[] Hashtable;
    delete[] Kurztable;


    return 0;
}
