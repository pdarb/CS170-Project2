#include <iostream>
#include <vector>
#include <list>
#include <stdio.h>


#include "accuracy.h"

using namespace std;

void featureSearch(vector<vector<double> > &data) {

    list <int> current_set_of_features; 
    

    for (int i = 0; i < data[0].size(); i++) {
        //cout << i+1 << endl;

        cout << "On the " << i+1 << "th level of the search tree" << endl;
        int feature_to_add_at_level = 0;
        double best_so_far = 0;

        for (int k = 0; k < data[0].size(); k++) {
            if (find(current_set_of_features.begin(), current_set_of_features.end(), (k+1)) == current_set_of_features.end()) {
                //current_set_of_features.push_back(k+1);
            
                cout << "Consider adding feature " << k+1 << endl;
                int accuracy = crossValidation(data);
                cout << accuracy << endl;

                if (accuracy > best_so_far) {
                    best_so_far = accuracy;
                    feature_to_add_at_level = k+1;
                //cout << "feature:" << feature_to_add_at_level << endl;
                }
            }
        }
        current_set_of_features.push_back(feature_to_add_at_level);
        cout << "On level " << i+1 << " I added feature " << feature_to_add_at_level << " to current set" << endl;
        
    }
};
