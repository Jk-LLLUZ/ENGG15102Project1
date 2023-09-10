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

  void parseFromFile(string inputfile)
  {
    //parse and input validate first line
    ifstream fileToParse(inputfile);

    if(!fileToParse)
    {
     cout << "could not open " << inputfile << " to be parsed" << endl;
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
    //set duration according to how big the vector is
  }
};

// struct Record {
//     int xraw;
//     int yraw;
// };
// vector<Record> parseFromFiles(const string& xDataFileName, const string& yDataFileName) {
//     vector<Record> records;
//     // Parse the x value file
//     ifstream xInputFile(xDataFileName);
//     if (!xInputFile) {
//         cerr << "Error opening the x value file." << endl;
//         return records;
//     }
//     string line;
//     while (getline(xInputFile, line)) {
//         try {
//             // Convert the line to an integer and store it in the vector
//             int xValue = stoi(line);
//             Record newRecord;
//             newRecord.xraw = xValue;
//             records.push_back(newRecord);
//         } catch (const invalid_argument& e) {
//             cerr << "Invalid data found in x value file: " << line << endl;
//         }
//     }
//     xInputFile.close();
//     // Parse the y value file
//     ifstream yInputFile(yDataFileName);
//     if (!yInputFile) {
//         cerr << "Error opening the y value file." << endl;
//         return records;
//     }
//     size_t currentIndex = 0; // Keep track of the current index in 'records'
//     while (getline(yInputFile, line)) {
//         try {
//             // Convert the line to an integer and store it in the vector
//             int yValue = stoi(line);
//             if (currentIndex < records.size()) {
//                 // Assign the y value to the corresponding x value
//                 records[currentIndex].yraw = yValue;
//                 currentIndex++;
//             } else {
//                 cerr << "More y values found than x values." << endl;
//                 break; // Stop parsing if there are more y values than x values
//             }
//         } catch (const invalid_argument& e) {
//             cerr << "Invalid data found in y value file: " << line << endl;
//         }
//     }
//     yInputFile.close();
//     return records;
// }
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

 xData.parseFromFile(xDataFileName);

    // vector<Record> records = parseFromFiles(xDataFileName, yDataFileName);
    // // Now, 'records' vector contains the parsed data
    // for (const Record& rec : records) {
    //     cout << "xraw: " << rec.xraw << ", yraw: " << rec.yraw << endl;
    // }
    // Implement cross-correlation here using 'records'
    return 0;
}



