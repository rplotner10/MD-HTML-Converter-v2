#include "StringSetter.h"

void StringSetter::compileLS()
{
    for(LineSetter ls : LSElements)
    {
        outputText.append(ls.compileLine() + "\n");
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
                int endBold = findEndTag(lineInput, '*', i+2);

                LineSetter bold;
                bold.bold(i+2, endBold, lineInput);
                LSElements.push_back(bold);
            }
            else
            {
                int endItalics = findEndTag(lineInput, '*', i+1);

                LineSetter italics;
                italics.italics(i+1, endItalics, lineInput);
                LSElements.push_back(italics);
            }
        }
        else if (c == '`') //monospace
        {
            int endMonospace = findEndTag(lineInput, '`', i+1);

            LineSetter monospace;
            monospace.monospace(i+1, endMonospace, lineInput);
            LSElements.push_back(monospace);
        }  
        else if(c == '#')
        {
            int headerNum = 0;
            int p = i;
            cout << p << endl;
            while(c == '#')
            {
                c = lineInput[p];
                headerNum+= 1;
                c++;
            }
            LineSetter H1;
            H1.header(headerNum,lineInput);
            LSElements.push_back(H1);
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

string StringSetter::htmlStartLabeling()
{
    string htmlSRetVal;

    htmlSRetVal = "<!DOCTYPE html>\n<html>\n<body>\n";

    return htmlSRetVal;
}

string StringSetter::htmlEndingLabeling()
{
    string htmlERetVal;

    htmlERetVal = "</body>\n</html>\n";

    return htmlERetVal;

    compileLS();

    return outputText;
}

int StringSetter::findEndTag(string line, char tag, int startTag)
{
    string lineI = line.substr(startTag);
                
    //offsets for original line
    return (lineI.find(tag) + startTag);
}