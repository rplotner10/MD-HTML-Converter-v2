#pragma once

#include "LineSetter.h"
#include "TextMDCheck.h"

#include <string>
#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

class TextMDCheck;

class LineSetter;

class StringSetter
{
    public:

        string parse(string mdStr);
        
        void htmlStartLabeling();

        string htmlEndingLabeling();

        int findEndTag(string line, char tag, int startTag);


    private:

        void compileLS();

        void findHtmlTag();

        string startPattern;
        string endPattern;
        bool inMarkdown;
        int posContentStart;
        int posContentEnd;
        string startTag;
        string endtag;

        bool inParagraph;
        bool inList;

        bool ordered;

        string outputText;

        vector <LineSetter> LSElements;
};