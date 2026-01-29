#pragma once

#include <iostream>
#include <vector>

#include "TextMDCheck.h"

class TextMDCheck;

using namespace std;
 
class LineSetter
{
    public:
        LineSetter();

        void bold(int start, int end, string line);
        void italics(int start, int end, string line);
        void monospace(int start, int end, string line);
        void paragraph(string line);
        void header(int headers,string lineInput);

        void list(vector <string> listStrings, bool ordered);
        void listElement(string std); //helper method that creates children for lists
        
        void images(string link, string linkDescription, int start, int end);
        void links(string link, string title, int start, int end);

        void hL(); //Horizontal Line

        string compileLine();

        void setAllFalse();

    private:
        bool iP; //isParagraph bool val
        bool hC; //hasChildren bool val
        bool iL; //isList bool val

        int startPos;
        int endPos;

        string startTag;
        string endTag;

        string text;

        vector <LineSetter> children; //Child Elements
};
