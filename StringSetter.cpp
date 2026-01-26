#include "StringSetter.h"

void StringSetter::compileLS()
{
    for(LineSetter ls : LSElements)
    {
        outputText.append(ls.compileLine() + "\n");
    }
}

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
        //if paragraph \/
        if (true)
        {
            LineSetter para;
            para.paragraph(i, lineInput);
        }
    

    }

    compileLS();

    return outputText;
}

int StringSetter::findEndTag(string line, char tag, int startTag)
{
    string lineI = line.substr(startTag);
                
    //offsets for original line
    return (lineI.find(tag) + startTag);
}