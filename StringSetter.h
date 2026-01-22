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

        string startPattern;
        string endPattern;
        bool inMarkdown;
        int posContentStart;
        int posContentEnd;
        string startTag;
        string endtag;

        string outputText;

        
};