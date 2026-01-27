#include "LineSetter.h"

string LineSetter::compileLine()
{
    return (startTag + text + endTag);
}
void LineSetter::bold(int start, int end, string line)
{
    startTag = "<b>";
    endTag = "</b>";

    text = line.substr(start, (end - start));
}
void LineSetter::italics(int start, int end, string line)
{
    startTag = "<em>";
    endTag = "</em>";

    text = line.substr(start, (end - start));
}
void LineSetter::monospace(int start, int end, string line)
{
    startTag = "<code>";
    endTag = "</code>";

    text = line.substr(start, (end - start));
}
//NOT FINISHED!!!
void LineSetter::paragraph(int start, string line)
{
    char c = line[start];
    
    if ((char) tolower(c) >= 97 && (char) tolower(c) <= 122)
    {
        //remove end spaces
        for (int i = line.size()-1; i >= 0; i--)
        {
            if (line[i] != ' ')
            {
                int posContentEnd = i;
                break;
            }

        }

    }

    string startTag = "<p>";
    string endTag = "<\\p>";
}
void LineSetter::header(int headers,string lineInput)
{ 
    string textWNoPound;
    for(int i =0;i<lineInput.length();i++)
    {
        if(lineInput[i] != '#')
        {
            textWNoPound += lineInput[i];
        }
        else
        {

        }
    }
    string headerNumInString = to_string(headers);
    startTag = "<h";
    endTag = "</h";
    // not sure where to sotre the final html text form
    text = startTag + headerNumInString + '>' +  textWNoPound + endTag + headerNumInString + '>';
}