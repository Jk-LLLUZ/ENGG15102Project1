//Katrice Annika Mendoza
//Ezekiel Thomas Laygo
//John Kyle Lluz

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include <stdexcept>
#include <cctype>

using namespace std;

bool firstLineInputValidation(string lineToCheck)
{
 int spaceCount;
 bool firstC = false;

 for(char c : lineToCheck)
 {
  if (isspace(c))
  if (firstC && isspace(c))
  {
   spaceCount++;
  }
  firstC = true;
 }

 cout << "space count: " << spaceCount << endl;

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

  void parseFromFile(string inputfile)
  {
    //parse and input validate first line
    ifstream fileToParse(inputfile);

    if(!fileToParse)
    {
     cout << "could not open " << inputfile << " to be parsed" << endl;
    } else
    {
     //first line parsing
     string firstLine;

     getline(fileToParse, firstLine);

     cout << "first line: \t" << firstLine << endl;

     bool isThereIndex = firstLineInputValidation(firstLine);

     if (isThereIndex == 1)
     {
      cout << "yes theres index" << endl;

      istringstream divideFirstLine(firstLine);
      
      string strIndex, strFirstValue;
      divideFirstLine >> strIndex >> strFirstValue;

      cout << "index: " << strIndex << "\t first: " << strFirstValue << endl;

      this->index = stoi(strIndex);
      signalData.push_back(stod(strFirstValue));

      cout << "index int works: " << this->index << "\t first value in vector works: " << signalData[0] << endl;

     } if (isThereIndex == 0)
     {
      cout << "no no index" << endl;
      this->index = 0;

      signalData.push_back(stod(firstLine));
     }

     //parse the rest into signalData
     string parserNextValue;
     while(getline(fileToParse, parserNextValue))
     {
        cout << parserNextValue << endl;
        signalData.push_back(stod(parserNextValue));
     }

     //set duration
     this->duration = signalData.size();

     cout << "duration of signal is " << this->duration << endl;
    }
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
 
 cout << "parsing data from x file..." << endl;
 xData.parseFromFile(xDataFileName);

 Signal yData;

 cout << "parsing data from y file..." << endl;
 yData.parseFromFile(yDataFileName);


    // vector<Record> records = parseFromFiles(xDataFileName, yDataFileName);
    // // Now, 'records' vector contains the parsed data
    // for (const Record& rec : records) {
    //     cout << "xraw: " << rec.xraw << ", yraw: " << rec.yraw << endl;
    // }
    // Implement cross-correlation here using 'records'
    return 0;
}



