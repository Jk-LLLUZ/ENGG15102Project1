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
#include <cmath>

using namespace std;

void FileLineReader(string inputfile1);

bool firstLineInputValidation(string lineToCheck) {
    int spaceCount = 0; // Initialize spaceCount to 0
    bool firstC = false;

    for (char c : lineToCheck) {
        if (!firstC && isspace(c)) {
            // Skip leading spaces
        } else if (firstC && isspace(c)) {
            spaceCount++;
        } else {
            firstC = true;
        }
    }

    cout << "space count: " << spaceCount << endl;

    if (spaceCount > 0) {
        return true; // Yes, there are spaces in the input
    } else {
        return false; // No, there are no spaces in the input
    }
}

class Signal {
public:
    vector<double> signalData;
    int index;
    size_t duration;

    void parseFromFile(string inputfile) {
        ifstream fileToParse(inputfile);

        if (!fileToParse) {
            cout << "could not open " << inputfile << " to be parsed" << endl;
        } else {
            // Parse and input validate first line
            string firstLine;
            getline(fileToParse, firstLine);
            cout << "first line: \t" << firstLine << endl;

            bool isThereIndex = firstLineInputValidation(firstLine);

            if (isThereIndex == 1) {
                cout << "yes, there's an index" << endl;
                istringstream divideFirstLine(firstLine);
                string strIndex, strFirstValue;
                divideFirstLine >> strIndex >> strFirstValue;
                cout << "index: " << strIndex << "\t first: " << strFirstValue << endl;
                this->index = stoi(strIndex);
                signalData.push_back(stod(strFirstValue));
                cout << "index int works: " << this->index << "\t first value in vector works: " << signalData[0] << endl;
            }
            if (isThereIndex == 0) {
                cout << "there's no index, therefore index = 0" <<  endl;
                this->index = 0;
                cout << "index = " << index <<endl;
                signalData.push_back(stod(firstLine));
            }
        }

        // Parse the rest into signalData
        string line;
        while (getline(fileToParse, line)) {
            try {
                double value = stod(line);
                signalData.push_back(value);
            } catch (const std::invalid_argument& e) {
                cerr << "Error parsing line as double: " << line << endl;
            } catch (const std::out_of_range& e) {
                cerr << "Value out of range: " << line << endl;
            }
        }

        // Calculate durations
        duration = signalData.size();
        cout << "Duration of the first signal is " << duration << endl;
    }
};

bool readFile(const string& filename, vector<string>& lines) {
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Error: Could not open file '" << filename << "'" << endl;
        return false;
    }

    string line;
    while (getline(file, line)) {
        lines.push_back(line);
        cout << line << endl;
    }

    file.close();
    return true;
}

void normCrossCorr() {
    // Calculations go here
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        cout << "Please call the program in the format:" << endl;
        cout << "> xcorr [xdata] [ydata] [outputfile]" << endl;
        cout << "where each of the bracketed terms are the respective file names." << endl;
        return 1; // Return an error code
    }

    cout << "Received file " << argv[1] << " for use as x values" << endl;
    cout << "Received file " << argv[2] << " for use as y values" << endl;
    cout << "Received file " << argv[3] << " for use as the output file" << endl;

    string xDataFileName = argv[1];
    string yDataFileName = argv[2];
    string outputFileName = argv[3];

    Signal xData;
    Signal yData;

    xData.parseFromFile(xDataFileName);
    yData.parseFromFile(yDataFileName);

    double xaverage = 0.0;
    double yaverage = 0.0;
    int duration = xData.duration + yData.duration - 1;

    for (int i = 0; i < xData.duration; i++) {
        xaverage += xData.signalData[i];
    }
    xaverage /= xData.duration;

    for (int i = 0; i < yData.duration; i++) {
        yaverage += yData.signalData[i];
    }
    yaverage /= yData.duration;

    cout << "Average of x: " << xaverage << endl;
    cout << "Average of y: " << yaverage << endl;

    // Getting xn and yn
    double xn[duration];
    double yn[duration];

    for (int i = 0; i < duration; i++) {
        xn[i] = xData.signalData[i] - xaverage;
    }

    for (int i = 0; i < duration; i++) {
        yn[i] = yData.signalData[i] - yaverage;
    }

    // Test
    for (int i = 0; i < 10; ++i) {
        cout << i << " " << xn[i] << " " << yn[i] << endl;
    }
    //shift
    //x shift
    double elementx;
    if (xData.index < 0) {
        for (int i = 0; i > xData.index; --i) {
            elementx = xn[0];
            for (int j = 0; j < duration - 1; ++j) {
                xn[i] = xn[i + 1];
            }
            xn[duration - 1] = elementx;
        }
    } else {
        for (int i = 0; i < xData.index; ++i) {
            elementx = xn[i - 1];
            for (int i = duration - 1; i > 0; --i) {
                xn[i] = xn[i - 1];
            }
            xn[0] = elementx;
        }
    }
    //shift y pretty much same code
    double elementy;
    if (yData.index < 0) {
        for (int i = 0; i > yData.index; --i) {
            elementy = yn[0];
            for (int j = 0; j < duration - 1; ++j) {
                yn[i] = yn[i + 1];
            }
            yn[duration - 1] = elementy;
        }
    } else {
        for (int i = 0; i < yData.index; ++i) {
            elementy = yn[i - 1];
            for (int i = duration - 1; i > 0; --i) {
                yn[i] = yn[i - 1];
            }
            yn[0] = elementy;
        }
    }
    //autocorrelation for denomin
    double sumsquarex;
    double sumsquarey;
    for (int i = 0; i < xData.duration; ++i)
    {
        sumsquarex += (xn[i] * xn[i]);
    }

    for (int i = 0; i < duration; ++i) {
        sumsquarey += (yn[i] * yn[i]);
    }
    //return sumsquarey;
    //return sumsquarex;
    //cross corr
    double crosscorr[duration];
    for (int i = 0; i < duration; ++i)
    {
        for (int j = 0; j < duration; ++j)
        {
            crosscorr[i] += (xn[j] * yn[j]);
        }
        double hold;
        //placeholder
        hold = yn[duration - 1];
        for (int i = duration - 1; i > 0; --i)
        {
            yn[i] = yn[i - 1];
        }
        yn[0] = hold;
    }

    // normalize
    double *normcorr = new double[duration];
    //double normcorr[duration];
    for (int i = 0; i < duration; i++)
    {
        normcorr[i] = crosscorr[i] / (sqrt(sumsquarex * sumsquarey));
    }
    //Shift
    int indexdiff = abs(xData.index) - abs(yData.index);
    int shift;
    if (xData.duration > yData.duration)
    {
        shift = indexdiff - xData.duration + 1;
    }
    else
    {
        shift = indexdiff - yData.duration + 1;
    }
    //shift normcorr


    for (int i = 0; i > shift; --i)
    {
        double tempvar = normcorr[0];
        for (int j = 0; j < duration - 1; j++)
        {
            normcorr[j] = normcorr[j + 1];
        }
        normcorr[duration - 1] = tempvar;
    }

    //put into output file
    ofstream output(argv[3]);
    if (duration < 20)
    {
        cout << "Output file generated " << argv[3] << " duration: " << duration << endl;
        output << shift << "\t" << normcorr[0] << endl;
        cout << shift << ":\t" << normcorr[0] << endl;
        for (int i = 0; i < duration - 1; ++i)
        {
            cout << shift + i + 1 << ":\t" << normcorr[i + 1] << endl;
            output << "\t" << normcorr[i + 1] << endl;
        }
    }
    else
    {
        cout << "Output file generated " << argv[3] << " duration: " << duration << endl;
        output << shift << "\t" << normcorr[0] << endl;
        cout << shift << "Output duration too long for console file generated instead"<< endl;
        for (int i = 0; i < duration - 1; ++i)
        {
            output << "\t" << normcorr[i + 1] << endl;
        }
    }

    output.close();

return 0;
}



