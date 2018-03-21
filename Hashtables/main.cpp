#define SIZE 1000 //Muss auch in HashingFunctions.h geändert werden!

#include "FileIO.h"
#include "HashingFunctions.h"
#include "MenuFunctions.h"
#include <iostream>

using namespace std;

int main()
{
    int i;


    string str="Hallo";

    cout<<HashFunction(str);


    return 0;
}
