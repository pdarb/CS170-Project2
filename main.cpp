#include <iostream>
#include "search.h"
#include "accuracy.h"

#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>
#include <stdio.h>
//#include <list>
#include <cmath>

using namespace std;

void featureSearch(vector<vector<double> > &data);

int crossValidation(vector<vector<double> > &data) {

    int accuracy = 0;
    vector <double> obj_to_classify;
    double nearest_neighbor_distance;
    double nearest_neighbor_location;

    double dist = 0.0;
    vector<double> diff;


    //accuracy = rand() % 101;

    for (int i = 0; i < data.size(); i++) {

        double label_obj_to_classify = data[i][0];

        for (int k = 1; k < data[i].size(); k++) {
            obj_to_classify.push_back(data[i][k]);
        }
        
        //https://stackoverflow.com/questions/8690567/setting-an-int-to-infinity-in-c

        nearest_neighbor_distance = numeric_limits<double>::infinity();
        nearest_neighbor_location = numeric_limits<double>::infinity();

        for (int j = 0; j < data.size(); j++) {

            if (j != i) {
                //cout << "Ask if " << i+1 << " is nearest neighbor with " << j+1 << endl;
                vector<double> temp;
                for (int t = 1; t < data[j].size(); t++) {
                    temp.push_back(data[i][j]);
                }

                vector<double>::iterator it = obj_to_classify.begin();
                vector<double>::iterator it1 = temp.begin();
                
                for (; it1 != temp.end() && it != obj_to_classify.end(); it1++, it++) {
                    double diffVal = (*it) - (*it1);
                    diff.push_back(diffVal);
                    cout << "Differences in row " << j << " is " << diffVal << endl;
                }
                
                
                set_difference(obj_to_classify.begin(), obj_to_classify.end(), temp.begin(), temp.end(), std::back_inserter(diff));
                //transform(obj_to_classify.begin(), obj_to_classify.end(), temp.begin(), diff.begin(), std::minus<double>());
                // for(int i = 0; i < diff.size(); i ++) {
                //     cout << diff.at(i) << endl;
                // }
                // for (vector <double> :: iterator it = diff.begin(); it != diff.end(); it++) {
                //     cout << (*it) << endl;
                // }


                
            }
        }



        // cout << "Looping over i, at the " << i+1 << " location" << endl;
        // cout << "The " << i+1 << "th object is in the class " << label_obj_to_classify << endl;
        // cout << endl;
    }


    return accuracy;
};

// double distance () {

// }


int main() {

    ifstream dataFile;

    vector< vector<double> > f;

    dataFile.open("Xsmall.txt");

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

        //featureSearch(f);
        crossValidation(f);

    }

    dataFile.close();







    return 0;
}



// -----------test code (DELETE LATER)-----------

// for (list <double> :: iterator it = obj_to_classify.begin(); it != obj_to_classify.end(); it++) {
    //     cout << (*it) << endl;
    // }

    // for (int v = 0; v < obj_to_classify.size(); v++) {
    //     cout << obj_to_classify.at(v) << endl;
    // }