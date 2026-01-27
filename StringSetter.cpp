#include "StringSetter.h"
#include "TextMDCheck.h"
#include "LineSetter.h"

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

    inParagraph = false;

    string lineInput;

    string paragraphText;

    TextMDCheck TMDCheck;

    while(getline(ss, lineInput))
    {
        //checks if empty line
        if (lineInput == "")
        {
            if(inParagraph)
            {
                LineSetter para;
                para.paragraph(paragraphText);
                inParagraph = false;

                LSElements.push_back(para);

            }
            continue;
        }

        if(inParagraph)
        {
            paragraphText.append(" " + lineInput);
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

        bool inP;

        if(c == '#')
        {
            int headerNum = 0;
            int p = i;
            while(c == '#')
            {
                
                headerNum+= 1;
                p++;
                c = lineInput[p];
            }
            LineSetter H1;
            H1.header(headerNum, lineInput);
            LSElements.push_back(H1);
            continue;

        }

        LineSetter element = TMDCheck.checkMD(inP, i, lineInput);

        if(!inP)
        {
            LSElements.push_back(element);
        }else
        {
            inParagraph = true;
            paragraphText.append(lineInput);
        }
    

    }

    compileLS();
    return outputText;
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