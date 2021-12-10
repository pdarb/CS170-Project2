#include <iostream>
#include "search.h"
#include "accuracy.h"

#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>
#include <stdio.h>
#include <algorithm>
#include <numeric>
#include <cmath>

using namespace std;
using namespace std::chrono;

void forwardSelection(vector<vector<double> > &data);
void backwardElimination(vector<vector<double> > &data);

double crossValidation(vector<vector<double> > &data) {

    double accuracy = 0.0;
    double num_correctly_classified = 0.0;

    vector <double> obj_to_classify;
    double NN_distance;
    double NN_location;
    double NN_label = 3.0;

    double dist = 0.0;
    vector<double> diff;

    for (int i = 0; i < data.size(); i++) {

        double label_obj_to_classify = data[i][0];

        for (int k = 1; k < data[i].size(); k++) {
            obj_to_classify.push_back(data[i][k]);
        }
        
        // cout << "There obj to classify vals: " << endl;
        // print(obj_to_classify);
        
        //https://stackoverflow.com/questions/8690567/setting-an-int-to-infinity-in-c

        NN_distance = numeric_limits<double>::infinity();
        NN_location = numeric_limits<double>::infinity();

        for (int j = 0; j < data.size(); j++) {

            if (j != i) {
                //cout << "Ask if " << i+1 << " is nearest neighbor with " << j+1 << endl;
                vector<double> temp;
                for (int t = 1; t < data[j].size(); t++) {
                    temp.push_back(data[j][t]);
                }
                // cout << "Values of temp vector: " << endl;
                // print(temp);

                vector<double>::iterator it = obj_to_classify.begin();
                vector<double>::iterator it1 = temp.begin();
                
                for (; it1 != temp.end() && it != obj_to_classify.end(); it1++, it++) {
                    double diffVal = pow(((*it) - (*it1)), 2);
                    diff.push_back(diffVal);
                    //cout << "Differences in row " << j << " is " << diffVal << endl;
                }
                
                // Finds Euclidean Distance
                double dist = sqrt(std::accumulate(diff.begin(), diff.end(), 0.0));
                //cout << "Euclidean Distance Vals: " << dist << endl;
                
                if (dist < NN_distance) { 
                    NN_distance = dist;
                    NN_location = j+1;
                    NN_label = data[j][0];
                }
    
                diff.clear(); 
            }
            
        }

        if (label_obj_to_classify == NN_label) {
            num_correctly_classified += 1;
        }


        // cout << "Object " << i+1 << " is class " << label_obj_to_classify << endl;
        // cout << "It's nearest_neighbor is " << NN_location << " which is in class " << NN_label << endl;

        // cout << "Looping over i, at the " << i+1 << " location" << endl;
        // cout << "The " << i+1 << "th object is in the class " << label_obj_to_classify << endl;
        // cout << endl;


        obj_to_classify.clear();
    }

    accuracy = num_correctly_classified / data.size();
    //cout << "Accuracy value: " << accuracy << endl;

    return accuracy;
}

// Modifies temp vector to include feature to add
void modified(vector<vector<double> > &data, vector<int> add_features, vector<vector<double> > &mod) {
    for (int row = 0; row < data.size(); row++) {
        mod[row][0] = data[row][0];
        for (int col : add_features) {
            mod[row][col] = data[row][col];
        }
    }
}

// Print function to view vector data
void print(std::vector <double> const &a) {
   std::cout << "The vector elements are : ";

    for (int i=0; i < a.size(); i++)
    std::cout << a.at(i) << ' ';

    cout << endl;

}



int main() {

    ifstream dataFile;

    vector< vector<double> > f;

    //Get starting time
    auto start = high_resolution_clock::now();

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
             
        }

        //forwardSelection(f);

        backwardElimination(f);

        //crossValidation(f);

    }

    dataFile.close();

    //Get ending time
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<seconds>(stop - start);
  
    cout << "Time taken by function: " << duration.count() << " seconds" << endl;


    return 0;
}
