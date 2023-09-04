//Katrice Annika Mendoza
//Ezekiel Thomas Laygo
//John Kyle Lluz

#include <iostream>
#include <string>

using namespace std;

string xDataFileName, yDataFileName, outputFileName;

void parseFromFile()
{
 //parse from file to vector
}

void normCrossCorr()
{
 //calculations go here
}

int main(int argc, char* argv[])
{
 //main
 if (argc == 4)
 {
  cout << "received file " << argv[1] << " for use as x values" << endl;
  cout << "received file " << argv[2] << " for use as y values" << endl;
  cout << "received file " << argv[3] << " for use as the output file" << endl;
 } else
 {
  cout << "please call the program in the format \n > xcorr [xdata] [ydata] [outputfile] \n where each of the bracketed terms are the respective file names." << endl;

  return 0;
 }

 xDataFileName = argv[1];
 yDataFileName = argv[2];
 outputFileName = argv[3];

 //call the file parser here

 return 0;
}