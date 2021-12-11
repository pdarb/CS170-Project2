#include <iostream>
#include <vector>

using namespace std; 

// Computes Euclidean Distance to get accureacy for feature subsets
double crossValidation(vector< vector<double> > &data);
void print(std::vector <double> const &a);
void modified(vector<vector<double> > &data, vector<int> add_features, vector<vector<double> > &mod);