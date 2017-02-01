#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

char fileName[256];

void writeName(string name)
{
    ofstream fout(fileName);          // declares stream variable and
                                      //    associates it with a file
    fout << name << endl;

    fout.close();
}

void logNumNames(float numNames)
{
    ofstream fout;
    fout.open("log.txt");
    fout << numNames;
    fout.close();
}

float getNames()
{
    string name;
    float numNames;
    string ans = "y";

    while (ans != "n")
        if (ans == "y" || ans == "yes") {
            cout << "Enter a name: ";
            cin >> name;
            writeName(name);
            cout << "Do you want to enter another name? (y/n) ";
            cin >> ans;
            numNames++;
        }
        else {
            cout << "Please enter a valid answer: ";
            cin >> ans;
        }
    cout << "Thank you, names have been saved." << endl;

    return numNames;
}

int main()
{
    cout << "What is the name of the file you wish to store the names in? ";
    cin >> fileName;

    float numNames = getNames();
    logNumNames(numNames);

    return 0;
}
