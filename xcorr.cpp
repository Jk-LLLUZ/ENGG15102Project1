//Katrice Annika Mendoza
//Ezekiel Thomas Laygo
//John Kyle Lluz

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <stdexcept>

using namespace std;

pair<vector<int>, vector<int>> parseFromFiles(const string& xDataFileName, const string& yDataFileName) {
    vector<int> xrawValues;
    vector<int> yrawValues;

    // Parse the x value file
    ifstream xInputFile(xDataFileName);
    if (!xInputFile) {
        cerr << "Error opening the x value file." << endl;
        return make_pair(xrawValues, yrawValues); // Return empty vectors
    }

    string line;
    while (getline(xInputFile, line)) {
        try {
            // Convert the line to an integer and store it in the xraw vector
            int xValue = stoi(line);
            xrawValues.push_back(xValue);
        } catch (const invalid_argument& e) {
            cerr << "Invalid data found in x value file: " << line << endl;
            // Skip this line and continue parsing
        }
    }

    xInputFile.close();

    // Parse the y value file
    ifstream yInputFile(yDataFileName);
    if (!yInputFile) {
        cerr << "Error opening the y value file." << endl;
        return make_pair(xrawValues, yrawValues); // Return empty vectors
    }

    while (getline(yInputFile, line)) {
        try {
            // Convert the line to an integer and store it in the yraw vector
            int yValue = stoi(line);
            yrawValues.push_back(yValue);
        } catch (const invalid_argument& e) {
            cerr << "Invalid data found in y value file: " << line << endl;
            // Skip this line and continue parsing
        }
    }

    yInputFile.close();

    return make_pair(xrawValues, yrawValues);
}

void normCrossCorr(const vector<int>& xrawValues, const vector<int>& yrawValues) {
    // Calculate cross-correlation using xrawValues and yrawValues
    // Implement your cross-correlation logic here
}

int main(int argc, char* argv[]) {
    cout << "please call the program in the format \n > xcorr [xdata] [ydata] [outputfile] \n where each of the bracketed terms are the respective file names." << endl;
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

    pair<vector<int>, vector<int>> rawValues = parseFromFiles(xDataFileName, yDataFileName);

    vector<int> xrawValues = rawValues.first;
    vector<int> yrawValues = rawValues.second;

    // Now, 'xrawValues' vector contains the parsed xraw data
    // and 'yrawValues' vector contains the parsed yraw data

    // Implement cross-correlation using 'xrawValues' and 'yrawValues'
    normCrossCorr(xrawValues, yrawValues);

    return 0;
}
