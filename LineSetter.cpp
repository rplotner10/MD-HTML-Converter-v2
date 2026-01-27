#include "LineSetter.h"
#include "TextMDCheck.h"

string LineSetter::compileLine()
{
    string outputHelper = "";

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
    }else
    {
        return (startTag + text + endTag);
    }
    
}
void LineSetter::bold(int start, int end, string line)
{
    iP = false;
    hC = false;

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
void LineSetter::images(string link, string linkDescription)
{    
    string linkURL = link;
    string description = linkDescription;
    startTag = "<img src=\"" + link + "\" alt=\"" + linkDescription;
    endTag = "\">";
    text = "";
}
