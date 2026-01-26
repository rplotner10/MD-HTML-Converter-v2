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
    }

    inPara = true;
    
}