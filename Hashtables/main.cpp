#define SIZE 1000 //Muss auch in HashingFunctions.h geändert werden!

#include "Hashtable.h"
#include "MenuFunctions.h"
#include <iostream>

using namespace std;

int main()
{
    string N,K,W;
    //-----------------------Initialisierung der Hash-Tabellen------------------------------
    Entry* Hashtable=new Entry[1000];
    Kuerzel* Kurztable=new Kuerzel[1000];

    cout<<"Name: ";cin>>N;
    cout<<"Kurz: ";cin>>K;
    cout<<"WKN: ";cin>>W;

    ADD(N,K,W,Hashtable,Kurztable);
    ADD(N,K,W,Hashtable,Kurztable);//Bei selben Namen wird überschrieben

    DEL(N,Hashtable,Kurztable,true);
    DEL(N,Hashtable,Kurztable,true);


    //------------------------Zugrifftests für die Haupt-Hashtable------------------------------
    /*
    string str="Microsoft";
    string Kuerzel="MS";
    string wkn="abc123";
    bool s=false;
    Hashtable[0]->setName(str); //Setzen der Aktieneigenschaften/Namen etc.
    Hashtable[0]->setKuerzel(Kuerzel);
    Hashtable[0]->setWKN(wkn);
    Hashtable[0]->setState(s);

    str=Hashtable[0]->getName();    //Auslesen dieses Eintrages in der HT
    Kuerzel=Hashtable[0]->getKuerzel();
    wkn=Hashtable[0]->getWKN();
    s=Hashtable[0]->getState();
    cout<<"Gesetzter Entry:"<<str<<Kuerzel<<wkn<<s<<endl;

    for(int i=0;i<30;i++)   //Tages-Datensätze (alle 30) setzen
    {
        Hashtable[0]->DataSet[i].Volume=1;
        Hashtable[0]->DataSet[i].Close=2;
        Hashtable[0]->DataSet[i].Open=3;
        Hashtable[0]->DataSet[i].AdjClose=4;
        Hashtable[0]->DataSet[i].High=5;
        Hashtable[0]->DataSet[i].Low=6;
    }

    double V=Hashtable[0]->DataSet[14].Volume;  //einen Tages-Datensatz auslesen
    double L=Hashtable[0]->DataSet[14].Low;
    double H=Hashtable[0]->DataSet[14].High;
    double C=Hashtable[0]->DataSet[14].Close;
    double O=Hashtable[0]->DataSet[14].Open;
    double A=Hashtable[0]->DataSet[14].AdjClose;

    cout<<"Dataset: "<<V<<L<<H<<C<<O<<A<<endl;

    str=Hashtable[1]->getName();    //Auslesen der Eigenschaften eines nicht gesetzten Aktieneintrages
    Kuerzel=Hashtable[1]->getKuerzel();
    wkn=Hashtable[1]->getWKN();
    s=Hashtable[1]->getState();
    cout<<"Nicht gesetzter HT-Entry"<<str<<Kuerzel<<wkn<<s<<endl;



    //-------------------------Zugrifftests für Kürzelreferenztabelle--------------------------------------
    string k="Test";
    Entry* Ref=NULL;
    Ref=Hashtable[0];

    cout<<"Daten vor KT set"<<k<<Ref<<endl;

    Kurztable[0]->setKuerzel(k);    //Daten in Referenztabelle setzen
    Kurztable[0]->setReferenz(Ref);

    k=Kurztable[0]->getKuerzel();//Daten auslesen und ausgeben
    Ref=Kurztable[0]->getReferenz();
    cout<<"KT mit Set: "<<k<<Ref<<endl;

    k=Kurztable[1]->getKuerzel();//Daten eines nicht gesetzten Eintrages auslesen
    Ref=Kurztable[1]->getReferenz();
    cout<<"KT ohne Set: "<<k<<Ref<<endl;

    */
















    //--------------------------------Freigeben der Tabellen------------------------------
    delete[] Hashtable;
    delete[] Kurztable;


    return 0;
}
