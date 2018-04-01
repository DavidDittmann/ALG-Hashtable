#ifndef MENUFUNCTIONS_H_INCLUDED
#define MENUFUNCTIONS_H_INCLUDED
#include "Hashtable.h"

void ADD(std::string &N,std::string &K,std::string &w,Entry HT[],Kuerzel KU[]);
void DEL(std::string &str,Entry HT[],Kuerzel KU[],bool s);
void SEARCH(std::string &str,Entry HT[],Kuerzel KU[],bool s);
int LATEST_DATA(Entry HT[],int index);
void IMPORT(std::string &filename,Entry HT[],Kuerzel KU[],std::string &str, bool s);

#endif // MENUFUNCTIONS_H_INCLUDED
