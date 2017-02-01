#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

char fileName[256];

// checks to see if the file can be written to
bool checkFile()
{
    ofstream fout(fileName);
    if (fout.fail()) {
        return false;
    }

    fout.close();
    return true;
}

// writes user-inputted name to specified file
void writeName(string name)
{
    ofstream fout(fileName);          // declares stream variable and
                                      //    associates it with a file
    fout << name << endl;

    fout.close();
}

// logs number of names entered to log.txt
void logNumNames(float numNames)
{
    ofstream fout;
    fout.open("log.txt");
    fout << numNames;
    fout.close();
}

// gets names from user, sends to writeName()
float getNames()
{
    string name;
    float numNames = 0;
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

    while (checkFile() == false) {
        cout << "Cannot write to that file, please select another: " << endl;
        cin >> fileName;
    }
    cout << "Names will be stored in \"" << fileName << "\".\n";
    float numNames = getNames();
    logNumNames(numNames);

    return 0;
}
