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
    if(hv_name==-1||hv_kurz==-1)
    {
        cout<<"Aktie schon vorhanden!"<<endl;
    }
    else
    {
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
        cout<<"Aktie angelegt"<<endl;
    }

}

void DEL(std::string &str,Entry HT[],Kuerzel KU[],bool s)//bool s -> Auswahl ob durch Kürzel (false) oder Name (true) gesucht wird
{
    int index=-1,iK=-1;
    if(s)//Suche durch Name
    {
        index=DELSEARCH_HT(str,HT,0);
        if(index>=0)
        {
            string tmp=HT[index].getKuerzel();
            iK=DELSEARCH_KU(tmp,KU,0);
            if(iK>=0)
            {
                tmp="";
                HT[index].setState(false);
                HT[index].setName(tmp);
                HT[index].setKuerzel(tmp);
                HT[index].setWKN(tmp);
                for(int i=0;i<30;i++)
                {
                    HT[index].DataSet[i].Date="";
                    HT[index].DataSet[i].AdjClose=0;
                    HT[index].DataSet[i].Close=0;
                    HT[index].DataSet[i].Open=0;
                    HT[index].DataSet[i].High=0;
                    HT[index].DataSet[i].Low=0;
                }
                KU[iK].setKuerzel(tmp);
                KU[iK].setReferenz(NULL);
                KU[iK].setState(false);
                cout<<"Eintrag gelöscht"<<endl;
            }
            else
                cout<<"Eintrag nicht gefunden!"<<endl;
        }
        else
            cout<<"Eintrag nicht gefunden!"<<endl;
    }
    else//Suche durch Kürzel
    {
        index=DELSEARCH_KU(str,KU,0);
        if(index>=0)
        {
            string tmp="";
            Entry* PT;
            PT=KU[index].getReferenz();
            KU[index].setKuerzel(tmp);
            KU[index].setReferenz(NULL);
            KU[index].setState(false);

            PT->setState(false);
            PT->setName(tmp);
            PT->setKuerzel(tmp);
            PT->setWKN(tmp);
            for(int i=0;i<30;i++)
            {
                PT->DataSet[i].Date="";
                PT->DataSet[i].AdjClose=0;
                PT->DataSet[i].Close=0;
                PT->DataSet[i].Open=0;
                PT->DataSet[i].High=0;
                PT->DataSet[i].Low=0;
            }
            cout<<"Eintrag gelöscht"<<endl;
        }
        else
            cout<<"Eintrag nicht gefunden!"<<endl;
    }
}
