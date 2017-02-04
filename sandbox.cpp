#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

char fileName[256];

// checks to see if the file can be written to
bool checkFile()
{
    ofstream fout(fileName, ios::app);
    if (fout.fail()) {
        return false;
    }

    fout.close();
    return true;
}

// writes user-inputted name to specified file
void writeName(string name)
{
    ofstream fout(fileName, ios::app);          // declares stream variable and
                                                //    associates it with a file
    fout << name << endl;

    fout.close();
}

// logs number of names entered to log.txt
void logNumNames(float numNames)
{
    ofstream fout;
    fout.open("log.txt", ios::app);
    fout << numNames << "\n";
    fout.close();
}

// gets names from user, sends to writeName()
float getNames()
{
    string name;
    float numNames;
    string ans = "y";

    for (numNames = 0; ans != "n"; numNames++) {
        if (ans == "y" || ans == "yes") {
            cout << "Enter a name: ";
            cin >> name;
            writeName(name);
            cout << "Do you want to enter another name? (y/n) ";
            cin >> ans;
        }
        else {
            cout << "Please enter a valid answer: ";
            cin >> ans;
        }
    }

    return numNames;
}

void readLog(string fileName)
{
    ifstream fin("log.txt");

    if (!fin.fail()) {
        int value = 0;
        fin >> value;
        cout << value << " names were saved to \"" << fileName << "\"." << endl;
    }

    fin.close();
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
    logNumNames(getNames());
    readLog(fileName);

    return 0;
}
