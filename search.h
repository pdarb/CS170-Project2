#include <iostream>
#include <vector>
#include <list>
#include <stdio.h>
#include <algorithm>
#include <numeric>


#include "accuracy.h"

using namespace std;

void forwardSelection(vector<vector<double> > &data) {

    vector <int> current_set_of_features; 
    vector<int> final_set_features;
    
    double accuracy = 0.0;
    double finalAcc = 0.0;

    for (int i = 1; i < data[0].size(); i++) {

        cout << "On the " << i << "th level of the search tree" << endl;
        int feature_to_add_at_level = 0;
        double best_so_far = 0.0;

        for (int k = 1; k < data[0].size(); k++) {

            if (find(current_set_of_features.begin(), current_set_of_features.end(), (k)) == current_set_of_features.end()) {
            
                vector<int> feature = current_set_of_features;
                feature.push_back(k);

                cout << "Consider adding feature " << k << endl;
                vector< vector <double> > temp(data.size(), vector<double>(data[0].size(), 0));
                modified(data, feature, temp);
                accuracy = crossValidation(temp);

                if (accuracy > best_so_far) {
                    best_so_far = accuracy;
                    feature_to_add_at_level = k;
                }
            }
        }
        current_set_of_features.push_back(feature_to_add_at_level);

        if (best_so_far > finalAcc) {
            finalAcc = best_so_far;
            final_set_features = current_set_of_features;
        } 

        cout << "On level " << i << " I added feature " << feature_to_add_at_level << " to current set" << endl;
        cout << "Accuracy for feature " << feature_to_add_at_level << " is " << best_so_far << endl;
        
    }
    
    for ( int a : final_set_features ) cout << a << ' ';
    cout << endl;
    cout << "Accuracy: " << finalAcc << endl; 
    
};


void backwardElimination(vector<vector<double> > &data) {

    vector <int> current_set_of_features; 
    vector<int> final_set_features;
    
    double accuracy = 0.0;
    double finalAcc = 0.0;

    // Loads all features into current set vector
    for (int input = 1; input < data[0].size(); input++) {
        current_set_of_features.push_back(input);
    }

    for (int i = 1; i < data[0].size(); i++) {

        cout << "On the " << i << "th level of the search tree" << endl;
        int feature_to_remove_at_level = 0;
        double best_so_far = 0.0;

        for (int k = 1; k < data[0].size(); k++) {

            if (find(current_set_of_features.begin(), current_set_of_features.end(), (k)) != current_set_of_features.end()) {
                
                vector<int> feature = current_set_of_features;
        
                feature.erase(remove(feature.begin(), feature.end(), k), feature.end());

                cout << "Consider removing feature " << k << endl;
                
                vector< vector <double> > temp(data.size(), vector<double>(data[0].size(), 0));
                modified(data, feature, temp);
                accuracy = crossValidation(temp);

                if (accuracy > best_so_far) {
                    best_so_far = accuracy;
                    feature_to_remove_at_level = k;
                }
            }
        }
        current_set_of_features.erase(remove(current_set_of_features.begin(), current_set_of_features.end(), feature_to_remove_at_level), current_set_of_features.end());

        if (best_so_far > finalAcc) {
            finalAcc = best_so_far;
            final_set_features = current_set_of_features;
        } 

        cout << "On level " << i << " I removed feature " << feature_to_remove_at_level << " to current set" << endl;
        cout << "Accuracy for feature " << feature_to_remove_at_level << " is " << best_so_far << endl;
        
    }
    
    for ( int a : final_set_features ) cout << a << ' ';
    cout << endl;
    cout << "Accuracy: " << finalAcc << endl; 
    
};