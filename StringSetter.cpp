#include "StringSetter.h"

string StringSetter::parse(string mdStr)
{
    stringstream ss(mdStr);

    string lineInput;

    while(getline(ss, lineInput)){
        cout << lineInput << endl;
    }
    return "";

}