#include "StringSetter.h"

void StringSetter::setParagraph(string line, int start, int end)
{

    for (int i = start; i <= end; i++)
    {
        char c = line[i];
        

    }  
}

string StringSetter::parse(string mdStr)
{
    stringstream ss(mdStr);

    string lineInput;

    while(getline(ss, lineInput))
    {
        //cheks if empty line
        if (lineInput == "")
        {
            continue;
        }
        
        //find first no space char \/
        int i = -1;
        char c;
        do
        {
            i++;
            c = lineInput[i];
        }
        while(c == ' ');

        //Check what first character is to see if in MD Block

        //if statements to determine code
        if (c == '*') //italics
        {
            if (lineInput[i+1] == '*') //bold
            {
                LineSetter bold;
                bold.bold();
            }
            else
            {
                LineSetter italics;
                italics.italics();
            }
        }
        else if (c == '`') //monospace
        {
            LineSetter monospace;
            monospace.monospace();
        }
        

        //if paragraph \/
        if (true)
        {
            LineSetter para;
            para.paragraph(i, lineInput);
        }
    

    }
    return "";
}