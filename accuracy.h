#include <iostream>
#include <vector>

using namespace std; 

double crossValidation(vector< vector<double> > &data);
void print(std::vector <double> const &a);
vector <vector<double> >& modified(vector<vector<double> > &data, vector<int> add_features);