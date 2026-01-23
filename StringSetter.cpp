#include "StringSetter.h"

void StringSetter::setParagraph(string line, int start, int end)
{
    LineSetter para;

    para.paragraph();

    for (int i = start; i <= end; i++)
    {
        char c = line[i];
        //if statements to determine code
        if (c == '*') //italics
        {
            if (line[i+1] == '*') //bold
            {

            }
            
        }

    }  
}
string StringSetter::parse(string mdStr)
{
    stringstream ss(mdStr);

    string lineInput;

    while(getline(ss, lineInput))
    {
        cout << lineInput << endl;
        
        if (lineInput == "")
        {
            continue;
        }
        
        int i = -1;
        char c;
        do
        {
            i++;
            c = lineInput[i];
        }
        while(c != ' ');

        int start = i;
        
        if ((char) tolower(c) >= 97 && (char) tolower(c) <= 122)
        {
            //remove end spaces
            for (i = lineInput.size()-1; i >= 0; i--)
            {
                if (lineInput[i] != ' ')
                {
                    break;
                }

            }
            setParagraph(lineInput, start, i);

        }
        
    }
    return "";
}