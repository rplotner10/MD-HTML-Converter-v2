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
    inList = false;
    ordered = false;

    string lineInput;

    string paragraphText;
    vector <string> listElements;

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
                paragraphText = "";

            }else if(inList){
                inList = false;
                LineSetter list;
                list.list(listElements, ordered);
                LSElements.push_back(list);

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

        //Checking for unordered list
        if(c == '*'){
            int secondBraceIndex = findEndTag(lineInput, '*', i + 2);



            if(secondBraceIndex == string::npos){
                inList = true;
                ordered = false;
                listElements.push_back(lineInput.substr(i));
                continue;
            }
        }
        

        //Checking for header
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
    if(inParagraph){
        LineSetter para;
        para.paragraph(paragraphText);
        inParagraph = false;

        LSElements.push_back(para);
    }
    compileLS();
    return outputText;
}

void StringSetter::htmlStartLabeling()
{
    string htmlSRetVal;

    htmlSRetVal = "<!DOCTYPE html>\n<html>\n<body>\n";

    outputText.append(htmlSRetVal);
}

string StringSetter::htmlEndingLabeling()
{
    string htmlERetVal;

    htmlERetVal = "</body>\n</html>\n";

    outputText.append(htmlERetVal);

    return outputText;
}

int StringSetter::findEndTag(string line, char tag, int startTag)
{
    string lineI = line.substr(startTag);
                
    //offsets for original line

    if(lineI.find(tag) == string::npos)
    {
        return string::npos;
    }
    return (lineI.find(tag) + startTag);
}