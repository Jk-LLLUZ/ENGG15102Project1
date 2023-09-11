//Katrice Annika Mendoza
//Ezekiel Thomas Laygo
//John Kyle Lluz

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <stdexcept>
#include <cctype>

using namespace std;

bool firstLineInputValidation(string lineToCheck)
{
 int spaceCount;

 for(char c : lineToCheck)
 {
  if (isspace(c))
  {
   spaceCount++;
  }
 }

 if(spaceCount>0)
 {
  return 1; //yes there is an index
 } else
 {
  return 0; //no there is no index provided
 }
}

class Signal
{
 public:
  vector<double> signalData;
  
  int index;
  int duration;

  void parseFromFile(string inputfile1, string inputfile2)
  {
    //parse and input validate first line
    ifstream fileToParse(inputfile1);

    if(!fileToParse)
    {
     cout << "could not open " << inputfile1 << " to be parsed" << endl;
    } else
    {
     string firstLine;

     getline(fileToParse, firstLine);

     cout << "first line: \t" << firstLine << endl;

     bool isThereIndex = firstLineInputValidation(firstLine);

     if (isThereIndex == 1)
     {
      cout << "yes theres index" << endl;
     } if (isThereIndex == 0)
     {
      cout << "no no index" << endl;
     }
    }
    //set index
    //parse the rest into signalData
      string line;
      while (getline(fileToParse, line))
      {
          double value = stod(line);
          signalData.push_back(value);
      }

      // Parse the rest into signalData for the second signal
      string line;
      while (getline(fileToParse, line))
      {
          double value = stod(line);
          signalData.push_back(value);
      }
    //set duration according to how big the vector is
      duration = signalData1.size();
      cout << "Duration of the first signal is " << duration1 << endl;
      cout << "Duration of the second signal is " << duration2 << endl;
  }
};


void normCrossCorr()
{
    //calculations go here
}

int main(int argc, char* argv[]) {
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
 
 string xDataFileName, yDataFileName, outputFileName;

 xDataFileName = argv[1];
 yDataFileName = argv[2];
 outputFileName = argv[3];

 Signal xData;
 Signal yData;

 xData.parseFromFile(xDataFileName,yDataFileName);

    return 0;
}



