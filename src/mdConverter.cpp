  #include "mdConverter.h"
  #include <fstream>
  #include <iostream>
  using namespace.std;

  void MDConverter :: FileConverter()
    
    {
    ifstream inputFile("markdown-sample.md");

    if (!inputFile.is_open()) 
    {
        cerr << "Error opening file." << endl;
        return 1;
    }

    ofstream outputFile("output.txt");
    }