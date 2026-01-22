  #include "mdConverter.h"
  #include <fstream>
  #include <iostream>
  using namespace std;

  void MDConverter :: FileConverter()
    {
    ifstream inputFile("markdown-sample.md");
    ofstream outputFile("output.txt");

    string line;
    inputFile>>line;
    if (!inputFile.is_open()){
    
        cerr << "Error opening file." << endl;
        return;
    }

    
    inputFile.close();
    outputFile.close();
    }