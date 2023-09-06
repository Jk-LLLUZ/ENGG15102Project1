//Katrice Annika Mendoza
//Ezekiel Thomas Laygo
//John Kyle Lluz

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <stdexcept>

using namespace std;

string xDataFileName, yDataFileName, outputFileName;


struct Record {
    int xraw;
    int yraw;
};

void parseFromFile() {
    Record record;

    // Get the names of the x and y value files
    cout << "What is the name of the x value file?" << endl;
    cin >> xDataFileName;
    xDataFileName += ".txt"; // Append ".txt" to the filename

    cout << "What is the name of the y value file?" << endl;
    cin >> yDataFileName;
    yDataFileName += ".txt"; // Append ".txt" to the filename

    vector<Record> records;

    // Parse the x value file
    ifstream xInputFile(xDataFileName);
    if (!xInputFile) {
        cerr << "Error opening the x value file." << endl;
        return;
    }

    string line;
    while (getline(xInputFile, line)) {
        try {
            // Convert the line to an integer and store it in the vector
            int xValue = stoi(line);
            Record newRecord;
            newRecord.xraw = xValue;
            records.push_back(newRecord);
        } catch (const invalid_argument& e) {
            cerr << "Invalid data found in x value file: " << line << endl;
        }
    }

    xInputFile.close();

    // Parse the y value file
    ifstream yInputFile(yDataFileName);
    if (!yInputFile) {
        cerr << "Error opening the y value file." << endl;
        return;
    }

    while (getline(yInputFile, line)) {
        try {
            // Convert the line to an integer and store it in the vector
            int yValue = stoi(line);
            // Check if there is a corresponding x value for this y value
            if (!records.empty()) {
                records.back().yraw = yValue;
            } else {
                cerr << "No corresponding x value found for y value: " << yValue << endl;
            }
        } catch (const invalid_argument& e) {
            cerr << "Invalid data found in y value file: " << line << endl;
        }
    }

    yInputFile.close();

    // Now, 'records' vector contains the parsed data
    for (const Record& rec : records) {
        cout << "xraw: " << rec.xraw << ", yraw: " << rec.yraw << endl;
    }
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