#ifndef HISTOGRAM_H_INCLUDED
#define HISTOGRAM_H_INCLUDED

#include <iostream>
#include <vector>



using namespace std;


void find_minmax(const vector<double>& numbers, double& min, double& max);
vector<double> input_numbers(size_t count);
void find_minmax(const vector<double>& numbers, double& min, double& max);
vector<size_t> make_histogram(const vector<double>& numbers, size_t& bin_count);
void show_histogram_text(const vector<size_t>& bins);




#endif // HISTOGRAM_H_INCLUDED
