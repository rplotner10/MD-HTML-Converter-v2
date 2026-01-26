#pragma once

#include "LineSetter.h"
#include "TextMDCheck.h"

#include <string>
#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

class StringSetter
{
    public:
    
        string parse(string mdStr);
        
        string htmlStartLabeling();

        string htmlEndingLabeling();

        int findEndTag(string line, char tag, int startTag);


    private:

        void compileLS();

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

        vector <LineSetter> LSElements;
};