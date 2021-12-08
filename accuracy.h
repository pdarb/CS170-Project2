#include <iostream>
#include <vector>

using namespace std; 

double crossValidation(vector< vector<double> > &data);
void print(std::vector <double> const &a);
void modified(vector<vector<double> > &data, vector<int> add_features, vector<vector<double> > &mod);