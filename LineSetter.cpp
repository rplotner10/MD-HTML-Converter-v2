#include "LineSetter.h"

string LineSetter::compileLine()
{
    return (startTag + text + endTag);
}
void LineSetter::bold(int start, int end, string line)
{
    int posContentStart = start;
    startTag = "<b>";
    endTag = "<\\b>";

    text = line.substr(start, (end - start));
}
void LineSetter::italics()
{
    cout << "found italics\n";

}
void LineSetter::monospace()
{
    cout << "found monospace\n";

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

    string startPattern = "";
    string endPattern = "";
    bool inMarkdown = false;
    int posContentStart = start;
    string startTag = "<p>";
    string endTag = "<\\p>";
}
