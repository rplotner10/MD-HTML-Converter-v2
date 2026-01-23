#pragma once

#include <string>
#include <sstream>
#include <iostream>


using namespace std;

class StringSetter
{
    public:
        //StringSetter();

        string parse(string mdStr);

    private:

        void findHtmlTag();

        void setParagraph(string line, int start, int end);
        void setItalics();
        void setBold();
        void setMonospace();


        string startPattern;
        string endPattern;
        bool inMarkdown;
        int posContentStart;
        int posContentEnd;
        string startTag;
        string endtag;

        bool inParagraph;

        string outputText;

        
};