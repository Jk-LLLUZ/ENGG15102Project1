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


void FileLineReader(string inputfile1);

bool firstLineInputValidation(string lineToCheck)
{
    int spaceCount = 0; // Initialize spaceCount to 0
    bool firstC = false;

    for (char c : lineToCheck)
    {
        if (!firstC && isspace(c))
        {
            // Skip leading spaces
        }
        else if (firstC && isspace(c))
        {
            spaceCount++;
        }
        else
        {
            firstC = true;
        }
    }

    cout << "space count: " << spaceCount << endl;

    if (spaceCount > 0)
    {
        return true; // Yes, there are spaces in the input
    }
    else
    {
        return false; // No, there are no spaces in the input
    }
}




class Signal
{
public:
vector<double> signalData;
int index;
size_t duration;

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
      cout << "yes there's index" << endl;

      istringstream divideFirstLine(firstLine);
      
      string strIndex, strFirstValue;
      divideFirstLine >> strIndex >> strFirstValue;

      cout << "index: " << strIndex << "\t first: " << strFirstValue << endl;

      this->index = stoi(strIndex);
      signalData.push_back(stod(strFirstValue));

      cout << "index int works: " << this->index << "\t first value in vector works: " << signalData[0] << endl;

     } 
     if (isThereIndex == 0)
     {
      cout << "there's no index therefore index = 0" <<  endl;
      this->index = 0;

      cout << "index = " << index <<endl;

      signalData.push_back(stod(firstLine));

      

     }
    }







    //parse the rest into signalData
        string line;
        while (getline(fileToParse, line))
        {
        try {
        double value = stod(line);
        signalData.push_back(value);
        } catch (const std::invalid_argument& e) {
        // Handle invalid argument exception (e.g., log an error, skip the line, etc.)
        cerr << "Error parsing line as double: " << line << endl;
        } catch (const std::out_of_range& e) {
        // Handle out of range exception (e.g., log an error, skip the line, etc.)
        cerr << "Value out of range: " << line << endl;
        }


        }


        // Calculate durations
        duration = signalData.size();

        cout << "Duration of the first signal is " << duration << endl;


}

   

};



bool readFile(const string& filename, vector<string>& amazing) {
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Error: Could not open file '" << filename << "'" << endl;
        return false;
    }

    string line;
    while (getline(file, line)) {
        amazing.push_back(line); 
        cout << line << endl; 
    }

    file.close();
    return true;
}



void normCrossCorr()
{
    //calculations go here
}
/*void Average()
{
    void Ave(double xraw[], double yraw[], int xsize, int ysize, double &xaverage, double &yaverage)
    {
        for (int i = 0; i < xsize; i++)
        {
            xaverage += xraw[i];
        }
        xaverage = xaverage / xsize;

        for (int i = 0; i < ysize; i++)
        {
            yaverage += yraw[i];
        }
        yaverage = yaverage / ysize;
    }
}*/

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

 xData.parseFromFile(xDataFileName);
 xData.parseFromFile(yDataFileName);
 
    string filename = xDataFileName;
    vector<string> amazing; // Change "lines" to "amazing"

    if (readFile(filename, amazing)) { // Change "lines" to "amazing"
        cout << "File '" << filename << "' successfully read." << endl;
    }

        string filename2 = yDataFileName;
    vector<string> amazing2; // Change "lines" to "amazing"

    if (readFile(filename2, amazing)) { // Change "lines" to "amazing"
        cout << "File '" << filename2 << "' successfully read." << endl;
    }
    double xaverage;
    double yaverage;
    double xn[xData.duration];
    double yn[yData.duration];
    //Average(xData,yData,xData.duration,yData.duration,xaverage,yaverage);
    for (int i = 0; i < xData.duration; i++)
    {
        xaverage += xData.signalData[i];
    }
    xaverage = xaverage / xData.duration;

    for (int i = 0; i < yData.duration; i++)
    {
        yaverage += yData.signalData[i];
    }
    yaverage = yaverage / yData.duration;
    cout<<"Average of x: "<< xaverage << endl;
    cout<<"Average of y: "<< yaverage << endl;
    //getting xn and yn
    for (int i = 0; i < xData.duration; i++)
    {
        xn[i] = xData.signalData[i] - xaverage;
    }

    for (int i = 0; i < yData.duration; i++)
    {
        yn[i] = yData.signalData[i] - yaverage;
    }
    for (int i = 0; i < 10; ++i) {
        cout <<i<< xn[i] <<" "<<yn[i]<< endl;

    }
    //shift
    //x shift
    double elementx;
    if (xData.index<0)
    {
        for (int i = 0; i > xData.index; --i)
        {
            elementx = xn[0];
            for (int j = 0; j < xData.duration - 1; ++j)
            {
                xn[i]=xn[i+1];
            }
            xn[xData.duration-1=elementx];
        }
    }
    else
    {
        for (int i = 0; i < xData.index; ++i)
        {
            elementx = xn[i - 1];
            for (int i = xData.duration - 1; i > 0; --i)
            {
                xn[i] = xn[i - 1];
            }
            xn[0] = elementx;
        }
    }
    //shift y pretty much same code
    double elementy;
    if (yData.index<0)
    {
        for (int i = 0; i > yData.index; --i)
        {
            elementy = yn[0];
            for (int j = 0; j < yData.duration - 1; ++j)
            {
                yn[i]=yn[i+1];
            }
            yn[yData.duration-1=elementy];
        }
    }
    else
    {
        for (int i = 0; i < yData.index; ++i)
        {
            elementy = yn[i - 1];
            for (int i = yData.duration - 1; i > 0; --i)
            {
                yn[i] = yn[i - 1];
            }
            yn[0] = elementy;
        }
    }
    //autocorrelation for denomin

    //cross corr

    // normalize




return 0;
}



