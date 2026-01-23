  #include "mdConverter.h"
  #include <fstream>
  #include <iostream>
  #include <sstream>
  using namespace std;

  void MDConverter :: FileConverter()
    
    {
    ifstream inputFile("markdown-sample.md");

    if (!inputFile.is_open()) 
    {
        cerr << "Error opening file." << endl;
        return;
    }

    ofstream outputFile("output.txt");
    }

  string MDConverter :: returnFileText(string path)
  {
    ifstream infile;
    string filePath = path;
    string finalResult;
    infile.open(filePath);
    if(infile.is_open()){
      stringstream line;
      line << infile.rdbuf();
      finalResult = line.str();
    }
    else{
      cout << "Error opening file." << endl;
    }
    return finalResult;
  }