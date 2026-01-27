#include "mdConverter.h"

void MDConverter :: compileDoc(string filePath)
{
    string inputText = returnFileText(filePath);

    StringSetter S1;

    S1.htmlStartLabeling();

    S1.parse(inputText);

    writeOutToFile(S1.htmlEndingLabeling());
}



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
  fout.open("demo-test.html");
  if(fout.is_open())
  {
    fout << outPutText;
  }
  else{
    fout << "unable to open file" << endl;
  }
}
