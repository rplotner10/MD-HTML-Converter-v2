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

    TextMDCheck TMDCheck; //utility class used for checkMD method
    
    //feeds in output line by line
    while(getline(ss, lineInput))
    {
        //checks if empty line
        if (lineInput == "")
        {
            //if empty line we check if we are in a block to compile finishing
            //element
            if(inParagraph)
            {
                inParagraph = false;

                LineSetter para;
                para.paragraph(paragraphText);
                LSElements.push_back(para);
                paragraphText = "";

            }else if(inList){
                inList = false;

                LineSetter list;
                list.list(listElements, ordered);
                LSElements.push_back(list);

                listElements = {};

            }
            continue; //starts new iteration of while loop
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

        //if first value is a number, we are in an unordered list potentionally
        //then we check if the next character is a dot
        if((int) c >= 48 && (int) c <= 57)
        {
            int j = i;
            c = lineInput[j];
            //finds next non number character in case of double or triple 
            //digit numbers
            while((int) c >= 48 && (int) c <= 57){
                j++;
                c = lineInput[j];
            }

            if(c == '.'){
                ordered = true;
                inList = true;
                string lineSub = lineInput.substr(j+2);//trimmed lineInput
                listElements.push_back(lineSub);

                continue;
            }
        }

        //Checking for unordered list
        if(c == '*'){
            
            int secondBraceIndex = findEndTag(lineInput, '*', i + 2);
            
            //this block checks if the block has another * implieing it is an italics or 
            //bold
            if(secondBraceIndex == string::npos){
                inList = true;
                ordered = false;

                string lineSub = lineInput.substr(i+2);//trimmed lineInput

                listElements.push_back(lineSub);

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

        if(c == '-' && lineInput[i + 1] == '-' && lineInput[i + 2] == '-')
        {
            LineSetter hL; // Horizontal Line
            hL.hL();
            LSElements.push_back(hL);
            continue;
        }

        bool inP; //bool that detects if we are in a paragraph

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

    //When we exit the while loop, we check if there were any elements 
    //in progress
    if(inParagraph){
        LineSetter para;
        para.paragraph(paragraphText);
        inParagraph = false;

        LSElements.push_back(para);
    }else if(inList){

        LineSetter list;
        list.list(listElements, ordered);
        inList = false;
        
        LSElements.push_back(list);

        cout << endl;

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

    if(lineI.find(tag) == string::npos)
    {
        return string::npos;
    }
    
    return (lineI.find(tag) + startTag);
}