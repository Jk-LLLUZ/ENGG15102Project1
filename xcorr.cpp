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
vector<double> signalData1;
vector<double> signalData2;
int index1;
int index2;
size_t duration1;
size_t duration2;

void parseFromFile(string inputfile1, string inputfile2)
{
    //parse and input validate first line
    ifstream fileToParse1(inputfile1);

    if(!fileToParse1)
    {
     cout << "could not open " << inputfile1 << " to be parsed" << endl;
    } else
    {
    
    
     //first line parsing
     string firstLine1;

     getline(fileToParse1, firstLine1);

     cout << "first line: \t" << firstLine1 << endl;

     

     bool isThereIndex1 = firstLineInputValidation(firstLine1);

     if (isThereIndex1 == 1)
     {
      cout << "yes there's index" << endl;

      istringstream divideFirstLine(firstLine1);
      
      string strIndex1, strFirstValue1;
      divideFirstLine >> strIndex1 >> strFirstValue1;

      cout << "index: " << strIndex1 << "\t first: " << strFirstValue1 << endl;

      this->index1 = stoi(strIndex1);
      signalData1.push_back(stod(strFirstValue1));

      cout << "index int works: " << this->index1 << "\t first value in vector works: " << signalData1[0] << endl;

     } 
     if (isThereIndex1 == 0)
     {
      cout << "there's no index therefore index = 0" <<  endl;
      this->index1 = 0;

      cout << "index = " << index1 <<endl;

      signalData1.push_back(stod(firstLine1));

      

     }
    }




      //parse and input validate first line
      ifstream fileToParse2(inputfile2);

      if(!fileToParse2)
      {
          cout << "could not open " << inputfile2 << " to be parsed" << endl;
      } else
      {
          //first line parsing
          string firstLine2;

          getline(fileToParse2, firstLine2);

          cout << "first line: \t" << firstLine2 << endl;

          bool isThereIndex2 = firstLineInputValidation(firstLine2);

          if (isThereIndex2 == 1)
          {
              cout << "yes theres index" << endl;

              istringstream divideFirstLine(firstLine2);

              string strIndex2, strFirstValue2;
              divideFirstLine >> strIndex2 >> strFirstValue2;

              cout << "index: " << strIndex2 << "\t first: " << strFirstValue2 << endl;

              this->index2 = stoi(strIndex2);
              signalData2.push_back(stod(strFirstValue2));

              cout << "index int works: " << this->index2 << "\t first value in vector works: " << signalData2[0] << endl;

          } if (isThereIndex2 == 0)
          {
              cout << "there is no index therefore index = 0" << endl;
              this->index2 = 0;

              cout << "index =" << index2 << endl;

              signalData2.push_back(stod(firstLine2));
          }
      }



    //parse the rest into signalData
        string line1;
        while (getline(fileToParse1, line1))
        {
        try {
        double value = stod(line1);
        signalData1.push_back(value);
        } catch (const std::invalid_argument& e) {
        // Handle invalid argument exception (e.g., log an error, skip the line, etc.)
        cerr << "Error parsing line as double: " << line1 << endl;
        } catch (const std::out_of_range& e) {
        // Handle out of range exception (e.g., log an error, skip the line, etc.)
        cerr << "Value out of range: " << line1 << endl;
        }


        }

        string line2;
        while (getline(fileToParse2, line2))
        {
            try {
                double value = stod(line2);
                signalData2.push_back(value);
            } catch (const std::invalid_argument& e) {
                // Handle invalid argument exception (e.g., log an error, skip the line, etc.)
                cerr << "Error parsing line as double: " << line2 << endl;
            } catch (const std::out_of_range& e) {
                // Handle out of range exception (e.g., log an error, skip the line, etc.)
                cerr << "Value out of range: " << line2 << endl;
            }
        }

        // Calculate durations
        duration1 = signalData1.size();
        duration2 = signalData2.size();
        cout << "Duration of the first signal is " << duration1 << endl;
        cout << "Duration of the second signal is " << duration2 << endl;

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

   

    




return 0;
}



