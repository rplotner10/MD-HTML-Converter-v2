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
void LineSetter::paragraph(string line)
{

    string startTag = "<p>";
    string endTag = "</p>";
}
