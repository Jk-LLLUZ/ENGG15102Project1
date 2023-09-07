#include <iostream>
#include <fstream>  //Needed to use files.
#include <string>
#include <sstream>
using namespace std;

void process_lines(istream &src);

int main()
{
    //This declares the input and output files.
    ifstream input;
    ofstream output;
    string filename;
    string word;





    int value, total = 0;

    cout << "Enter the file name: " << endl;
    cin >> filename;


    //This function opens file.
    input.open(filename.c_str());
    process_lines(input);

    //This checks to see if the file can be opened,
    //if yes, then it will calculate sum.
    if(input)
    {
        string ch;

		while (1)
        {
			input >> ch;
			if (input.eof())




        cout << input << endl;
        cout << "line: " << ch  << endl;

        break;

        }
    }
    else
    {
        cout << "file not available" << endl;
    }

    //This closes the input file.
    input.close();



cout << "code reached here" << endl;



return 0;
}
//------------------------------------------------------------------------------------------------------------------------------------
void process_lines(istream &src)
{

    string s;
    stringstream ss;
    stringstream ss2;
    string word;
    int linecount = 0;
    int test_int;
    double test_double;




    while ( !src.eof())
    {
        if (getline( src, s) )
    {

    linecount++;

    cout << "line " << linecount << ":\"" << s << "\"\n";

    ss << s;

    while ( ss >> word)
    {
        stringstream ss2;
        stringstream ss3;
        cout << word << endl;


        // testing for int

        ss2 << word;
        if ( ss2 >> test_int)
        {
            if ( ss2.eof())

            cout << "Obtained integer "
            << test_int << ss2 <<" from " << word << endl;

            else

            cout << "invalid int: "
            << test_int << " with extra characters from "
            << word << endl;
        }

        else
        {
            cout << word << " is not an integer\n";
        }
        ss2.clear();
        //test for a double
        ss3 << word;
        if ( ss3 >> test_double)
        {
            if ( ss3.eof())
            {

                cout << "Obtained floating pt number " << test_double << " from " << word << endl;
            }

            else
                cout << "invalid floating pt number: " << test_double << " with extra characters from " << word << endl; break;
        }

        else
        {
            cout << word << " INPUT IS INVALID\n";
        }
        ss3.clear();
    }
    ss.clear();
    }
    }
    }
