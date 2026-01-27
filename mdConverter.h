#pragma once

#include <string.h>
#include <iostream>
#include <fstream>
#include <sstream>

#include "StringSetter.h"

using namespace std;

class StringSetter;

class MDConverter 
{
    public:

      void compileDoc(string filePath);

      string returnFileText(string filePath);
      void writeOutToFile(string outPutText);
    private:

};