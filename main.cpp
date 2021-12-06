#include <iostream>
#include "search.h"

#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>
#include <stdio.h>

using namespace std;
void featureSearch(vector<vector<double> > &data);

int main() {

    ifstream dataFile;

    vector< vector<double> > f;

    dataFile.open("Small_data_60.txt");

    if (!dataFile) {
        cout << "Unable to open file" << endl;
        exit(1);
    }

    if (dataFile.is_open()) {
        int i = 0;
        string read;
        while (getline(dataFile, read)) {
            vector<double> cols;
            //cout << read << '\n';
            char *dup = strdup(read.c_str());
            char *field = strtok(dup ," ");
            while (field != NULL ) {
                //cout << field << endl;
                cols.push_back(atof(field));    
                field = strtok(NULL," ");
            }
            free(dup);

            f.push_back(cols);
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

        // for (int i = 0; i < f.size(); i++) {
        //     for (int k = 0; k < f[i].size(); k++) {
        //         cout << f[i][k] << endl;
        //     }
        // }

        featureSearch(f);

    }

    dataFile.close();







    return 0;
}
