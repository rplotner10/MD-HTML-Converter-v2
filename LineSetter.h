#pragma once

#include <iostream>
#include <vector>

 using namespace std;
 
 class LineSetter
 {
    public:
        void bold(int start, int end, string line);
        void italics(int start, int end, string line);
        void monospace(int start, int end, string line);
        void paragraph(string line);

        string compileLine();

    private:
        string startTag;
        string endTag;

        string text;

        vector <LineSetter> children; //Child Elements
 };
