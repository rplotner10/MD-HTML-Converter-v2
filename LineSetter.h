#pragma once

#include <iostream>
#include <vector>

#include "TextMDCheck.h"

class TextMDCheck;

using namespace std;
 
class LineSetter
{
    public:
        void bold(int start, int end, string line);
        void italics(int start, int end, string line);
        void monospace(int start, int end, string line);
        void paragraph(string line);
        void header(int headers,string lineInput);

        string compileLine();

        bool isParagraph();

        vector <LineSetter> getChildren();

        int getStartPos();
        int getEndPos();

        string getText();

        bool hasChildren();

    private:
        bool iP; //isParagraph bool val

        bool hC; //hasChildren bool val

        int startPos;
        int endPos;

        string startTag;
        string endTag;

        string text;

        vector <LineSetter> children; //Child Elements
};
