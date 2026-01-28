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
    
    //feeds in output line by line
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

        bool inP;

        if((int) c >= 48 && (int) c <= 57)
        {
            int j = i;
            c = lineInput[j];
            while((int) c >= 48 && (int) c <= 57)
            {
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
        // if(c == '!')
        // {
        //     string title;
        //     string link;
            

        //     string test = "![some_text](some_text)";

        //     if(lineInput[i + 1] == '['){
        //         int g = i + 1;
        //         while(c != ']'){
        //             g++;
        //             c = lineInput[g];
        //             if(c != ']'){
        //                 title += c;
        //             }
                    
        //         }
        //         g++;
        //         if(lineInput[g] == '('){
        //             while(c != ')'){
        //                 g++;
        //                 c = lineInput[g];
        //                 if(c != ')'){
        //                     link += c;
        //                 }
        //             }
                    
        //         }
        //     }



        //     // while(c != ')')
        //     // {
        //     //     title += c;
        //     //     if(c == '[')  
        //     //     {
        //     //         if(c != ')')
        //     //         {
        //     //             link += c;
        //     //         }
        //     //     }
        //     //     g++;
        //     //     c = lineInput[g];
        //     // }
        //     LineSetter Image1;
        //     Image1.images(link, title);
        //     LSElements.push_back(Image1);
        //     continue;
        // }
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
                
    //offsets for original line

    if(lineI.find(tag) == string::npos)
    {
        return string::npos;
    }
    return (lineI.find(tag) + startTag);
}