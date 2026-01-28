#include "LineSetter.h"
#include "TextMDCheck.h"

string LineSetter::compileLine()
{
    string outputHelper = "";

    //if in paragraph and have children
    if (iP && hC)
    {
        //adds all child elements
        int lastChildEndPos = 0;
        for(const LineSetter& child : children)
        {
            outputHelper += text.substr(lastChildEndPos, child.startPos - lastChildEndPos);
            outputHelper += (child.startTag + child.text + child.endTag);
            lastChildEndPos = child.endPos;
            
        }

        //adds end of paragraph if there is any
        outputHelper += text.substr(lastChildEndPos);
        
        return (startTag + outputHelper + endTag);
    }else if(hC && iL) //if in paragraph and have children
    {

        outputHelper.append(startTag + "\n");
        for(const LineSetter& child: children)
        {
            outputHelper.append((child.startTag + child.text + child.endTag + "\n"));
        }
        outputHelper.append(endTag);

        return outputHelper;

    }else
    {
        return (startTag + text + endTag);
    }
    
}
void LineSetter::bold(int start, int end, string line)
{
    iP = false;
    hC = false;
    iL = false;

    //pos include tags
    startPos = start - 2;
    endPos = end + 2;

    startTag = "<b>";
    endTag = "</b>";

    text = line.substr(start, (end - start));
}
void LineSetter::italics(int start, int end, string line)
{
    iP = false;
    hC = false;
    iL = false;

    //pos include tags
    startPos = start - 1;
    endPos = end + 1;

    startTag = "<em>";
    endTag = "</em>";

    text = line.substr(start, (end - start));
}
void LineSetter::monospace(int start, int end, string line)
{
    iP = false;
    hC = false;
    iL = false;

    //pos include tags
    startPos = start - 1;
    endPos = end + 1;

    startTag = "<code>";
    endTag = "</code>";

    text = line.substr(start, (end - start));
}
//NOT FINISHED!!!
void LineSetter::paragraph(string line)
{
    TextMDCheck mdCheck;
    
    //loops through every char and checks if is in a MD block
    for(int i = 0; i < line.size(); i++)
    {
        bool inP = false;
        LineSetter element = mdCheck.checkMD(inP, i, line);
        if (!inP)
        {
            hC = true;
            children.push_back(element);
            i = element.endPos;
        }
    }

    iP = true;
    text = line;
    startTag = "<p>";
    endTag = "</p>";
}

vector <LineSetter> LineSetter::getChildren()
{
    return children;
}

string LineSetter::getText()
{
    return text;
}


int LineSetter::getStartPos()
{
    return startPos;
}

int LineSetter::getEndPos()
{
    return endPos;
}

bool LineSetter::isParagraph()
{
    return iP;
}

bool LineSetter::hasChildren()
{
    return hC;
}
void LineSetter::header(int headers, string lineInput)
{ 
    string textWNoPound;
    //use startIndex, from p in the previous funciton
    for(int i =0;i < lineInput.length();i++)
    {
        if(lineInput[i] != '#')
        {
            textWNoPound += lineInput[i];
        }
    }
    string headerNumInString = to_string(headers);
    startTag = "<h" + headerNumInString + ">";
    endTag = "</h" + headerNumInString + ">";

    text = textWNoPound;
}

void LineSetter::list(vector <string> listStrings, bool ordered)
{
    iP = false;

    iL = true;

    if(ordered)
    {
        startTag = "<ol>";
        endTag = "</ol>";
        
    }else
    {
        startTag = "<ul>";
        endTag = "</ul>";
    }

    for(const string& str: listStrings)
    {
        hC = true;
        LineSetter listE;

        // char c = str[0];
        // int j = 0;

        // while(c != ' '){
            
        //     j++;
        //     c = str[j];
        // }

        // //remove asterisk and space from string
        // string strEdited = str.substr(j+1);


        listE.listElement(str);
        children.push_back(listE);
    }

    text = "";
}

void LineSetter::listElement(string str){
    text = str;
    startTag = "<li>";
    endTag = "</li>";
}
void LineSetter::images(string link, string linkDescription, int start, int end)
{    
    iP = false;
    hC = false;

    //pos include tags
    startPos = start;
    endPos = end;

    string linkURL = link;
    string description = linkDescription;
    startTag = "<img src=\"" + link + "\" alt=\"" + linkDescription;
    endTag = "\">";
    text = "";
}

void LineSetter::links(string link, string title, int start, int end)
{
    iP = false;
    hC = false;

    //pos include tags
    startPos = start;
    endPos = end;

    string linkURL = link;
    string subject = title;
    startTag = "<a href=\"" + link + "\">";
    endTag = "</a>";
    text = title;
}
