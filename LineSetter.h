#pragma once

#include <iostream>
#include <vector>

 using namespace std;
 
 class LineSetter
 {
    public:
        void bold(int start, int end, string line);
        void italics();
        void monospace();
        void paragraph(int start, string line);

        string compileLine();

    private:
        string startPattern;
        string endPattern;

        bool inMarkdown;
        int posContentStart;
        int posContentEnd;

        string startTag;
        string endTag;

        string text;

        vector <LineSetter> children; //Child Elements
 };
