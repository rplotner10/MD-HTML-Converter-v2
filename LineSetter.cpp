#include "LineSetter.h"

void LineSetter::bold()
{
    cout << "found bold\n";
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
    string endtag = "<\\p>";
}
