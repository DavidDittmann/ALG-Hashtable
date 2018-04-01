#include "Hashtable.h"
#include "MenuFunctions.h"
#include "FileIO.h"
#include <iostream>
#include <string>

using namespace std;

void ADD(string &N,string &K,string &w, Entry HT[],Kuerzel KU[])
{
    int hv_name=0,hv_kurz=0;
    hv_name=HashFunc(N);
    hv_kurz=HashFunc(K);
    //Erste Hashvalues

    hv_name=CollisionDetectHT(N,hv_name,HT,0);  //Feststellung ob Kollision bei Hashvalues
    hv_kurz=CollisionDetectKU(K,hv_kurz,KU,0);  //Neuer Hashvalue ist der (nächste) freie Platz, oder falls frei der zuerst berechnete Platz
                                                //->Quadratische Sondierung
    HT[hv_name].setState(true);
    HT[hv_name].setName(N);
    HT[hv_name].setKuerzel(K);
    HT[hv_name].setWKN(w);


    KU[hv_kurz].setKuerzel(K);
    KU[hv_kurz].setReferenz(&HT[hv_name]);

    for(int i=0;i<30;i++)
    {
        HT[hv_name].DataSet[i].Date="";
        HT[hv_name].DataSet[i].AdjClose=0;
        HT[hv_name].DataSet[i].Close=0;
        HT[hv_name].DataSet[i].Open=0;
        HT[hv_name].DataSet[i].High=0;
        HT[hv_name].DataSet[i].Low=0;
    }
}
