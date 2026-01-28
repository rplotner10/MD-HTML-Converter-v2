#include "TextMDCheck.h"

LineSetter TextMDCheck::checkMD(bool &inPara, int charIndex, string line)
{
    StringSetter SS;

    inPara = false;

    char c = line[charIndex];
    if (c == '*') // italics
    {
        if (line[charIndex + 1] == '*') // bold
        {
            int endBold = SS.findEndTag(line, '*', charIndex + 2);

            LineSetter bold;
            bold.bold(charIndex + 2, endBold, line);
            
            return bold;
        }
        else
        {
            int endItalics = SS.findEndTag(line, '*', charIndex + 1);

            LineSetter italics;
            italics.italics(charIndex + 1, endItalics, line);
            return italics;
        }
    }
    else if (c == '`') // monospace
    {
        int endMonospace = SS.findEndTag(line, '`', charIndex + 1);

        LineSetter monospace;
        monospace.monospace(charIndex + 1, endMonospace, line);
        return monospace;
    }else if(c == '!'){
        c = line[charIndex + 1];
        if(c == '[')
        {
            int searchBracket = SS.findEndTag(line, ']', charIndex + 1);
            if(searchBracket != string::npos){
                string title = line.substr(charIndex+2, searchBracket - charIndex - 2);
                c = line[searchBracket + 1];
                if(c == '('){
                    int searchParenth = SS.findEndTag(line, ')', charIndex + 1);
                    if(searchParenth != string::npos){
                        string imgSrc = line.substr(searchBracket + 2, searchParenth - searchBracket - 2);

                        LineSetter img;
                        img.images(imgSrc, title, charIndex, searchParenth + 1);
                        return img;
                    }
                }
            }
        }
    //finds links    
    }else if(c == '[')
    {
        int searchBracket = SS.findEndTag(line, ']', charIndex);
        if(searchBracket != string::npos){
            string title = line.substr(charIndex+1, searchBracket - charIndex - 1);
            c = line[searchBracket + 1];
            if(c == '('){
                int searchParenth = SS.findEndTag(line, ')', charIndex + 1);
                if(searchParenth != string::npos){
                    string linkSrc = line.substr(searchBracket + 2, searchParenth - searchBracket - 2);

                    LineSetter link;
                    link.links(linkSrc, title, charIndex, searchParenth + 1);
                    return link;
                }
            }
        }
    }

    LineSetter empty;

    inPara = true;
    return empty;
}