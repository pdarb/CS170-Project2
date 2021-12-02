#include <iostream>
#include <search.h>
//#include <accuracy.h>

#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>

using namespace std;


int main() {

    string read;
    vector< vector<float> > f; 

    ifstream dataFile;
    dataFile.open("Small_data_60.txt");

    if (!dataFile) {
        cout << "Unable to open file" << endl;
        exit(1);
    }

    if (dataFile.is_open()) {

        int i = 0;
        while (getline(dataFile, read)) {
            cout << read << '\n';
            // stringstream line(read);
            // float val;
            // vector<float> curr;
            // while (line >> val) {
            //     f.push_back(curr);
            //     for (int j = 0; j < f.size(); j++) {
            //         cout << "On the " << f.at(j) << "th level of the search tree" << endl;
            //     }
            // }

        }
    }

    dataFile.close();



    return 0;

}