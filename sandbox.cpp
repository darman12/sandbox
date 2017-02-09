#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

bool getFileName (char fileName[])
{
    cout << "Enter the name of the file you wish to store the names in: ";
    cin >> fileName;

    ofstream fout(fileName, ios::app);
    if (fout.fail()) {
        cout << "Unable to save to \"" << fileName << "\"." << endl;
        return false;
    }
    else {
        return true;
    }
}

// writes user-inputted name to specified file
void writeName(string name, char fileName[])
{
    ofstream fout(fileName, ios::app);          // declares stream variable and
                                                //    associates it with a file
    fout << name << endl;

    fout.close();
}
/*
// logs number of names entered to log.txt
void logNumNames(float numNames)
{
    ofstream fout;
    fout.open("log.txt", ios::app);
    fout << numNames << "\n";
    fout.close();
}
*/
// gets names from user, sends to writeName()
float getNames(char fileName[])
{
    string name;
    float numNames;
    string ans = "y";

    for (numNames = 0; ans != "n"; numNames++) {
        if (ans == "y" || ans == "yes") {
            cout << "Enter a name: ";
            cin >> name;
            writeName(name, fileName);
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

/*
void readLog(char fileName[])
{
    ifstream fin("log.txt");
    if (!fin.fail()) {
        int value = 0;
        fin >> value;
        cout << value << " names were saved to \"" << fileName << "\"." << endl;
    }

    cout << "The following names are stored in \"" << fileName << "\"." << endl;

    ifstream finNames("names.txt");
    while (!finNames.eof()) {
        char name[256];
        finNames >> name;
        cout << name << endl;
    }
    fin.close();
}
*/

int main()
{
    char fileName[256];
    //float numNames = 0;


    getFileName(fileName);
    //numNames = getNames(fileName);
    //logNumNames(getNames());
    //readLog(fileName);

    return 0;
}
