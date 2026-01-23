#include "LineSetter.h"

void LineSetter::bold()
{

}
void LineSetter::italics()
{

}
void LineSetter::monospace()
{

}
void LineSetter::paragraph()
{
    string startPattern = "";
    string endPattern = "";
    bool inMarkdown = false;
    int posContentStart = start;
    int posContentEnd = end;
    string startTag = "<p>";
    string endtag = "<\\p>";
}
