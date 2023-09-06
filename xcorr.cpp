//Katrice Annika Mendoza
//Ezekiel Thomas Laygo
//John Kyle Lluz

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <stdexcept>

using namespace std;

struct Record {
    int xraw;
    int yraw;
};
vector<Record> parseFromFiles(const string& xDataFileName, const string& yDataFileName) {
    vector<Record> records;
    // Parse the x value file
    ifstream xInputFile(xDataFileName);
    if (!xInputFile) {
        cerr << "Error opening the x value file." << endl;
        return records;
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
        return records;
    }
    size_t currentIndex = 0; // Keep track of the current index in 'records'
    while (getline(yInputFile, line)) {
        try {
            // Convert the line to an integer and store it in the vector
            int yValue = stoi(line);
            if (currentIndex < records.size()) {
                // Assign the y value to the corresponding x value
                records[currentIndex].yraw = yValue;
                currentIndex++;
            } else {
                cerr << "More y values found than x values." << endl;
                break; // Stop parsing if there are more y values than x values
            }
        } catch (const invalid_argument& e) {
            cerr << "Invalid data found in y value file: " << line << endl;
        }
    }
    yInputFile.close();
    return records;
}
void normCrossCorr()
{
    //calculations go here
}
int main(int argc, char* argv[]) {
    cout
            << "please call the program in the format \n > xcorr [xdata] [ydata] [outputfile] \n where each of the bracketed terms are the respective file names."<< endl;
    if (argc != 4) {
        cerr << "Usage: " << argv[0] << " [xdata] [ydata] [output file]" << endl;
        return 1;
    }
    string programName = argv[0];
    string xDataFileName = argv[1];
    string yDataFileName = argv[2];
    string outputFileName = argv[3];
    if (programName != "xcorr") {
        cerr << "Usage: " << programName << " [xdata] [ydata] [output file]" << endl;
        return 1;
    }
    vector<Record> records = parseFromFiles(xDataFileName, yDataFileName);
    // Now, 'records' vector contains the parsed data
    for (const Record& rec : records) {
        cout << "xraw: " << rec.xraw << ", yraw: " << rec.yraw << endl;
    }
    // Implement cross-correlation here using 'records'
    return 0;
}



