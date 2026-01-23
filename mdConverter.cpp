#include "mdConverter.h"

string MDConverter :: returnFileText(string path)
{
  ifstream infile;
  string filePath = path;
  string finalResult;
  infile.open(filePath);
  if(infile.is_open())
  {
    stringstream line;
    line << infile.rdbuf();
    finalResult = line.str();
  }
  else
  {
    cout << "Error opening file." << endl;
  }
  return finalResult;
}

void MDConverter :: writeOutToFile(string outPutText)
{
  ofstream fout;
  string text = outPutText;
  fout.open("fileWText.txt");
  if(fout.is_open())
  {
    fout << outPutText;
  }
  else{
    fout << "unable to open file" << endl;
  }
}
