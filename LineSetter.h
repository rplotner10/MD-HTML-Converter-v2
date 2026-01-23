#pragma once

#include <iostream>
#include <vector>

 using namespace std;
 
 class LineSetter
 {
    public:
        void bold();
        void italics();
        void monospace();
        void paragraph(int start, string line);

    private:
        string startPattern;
        string endPattern;

        bool inMarkdown;
        int posContentStart;
        int posContentEnd;

        string startTag;
        string endtag;

        vector <LineSetter> children; //Child Elements
 };
