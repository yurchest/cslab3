#ifndef HISTOGRAM_H_INCLUDED
#define HISTOGRAM_H_INCLUDED

#include <iostream>
#include <vector>
#include <sstream>
#include <string>


using namespace std;

struct Input {
    vector<double> numbers;
    size_t bin_count;
    string text_decoration;
};

void find_minmax(const vector<double>& numbers, double& min, double& max);
vector<double> input_numbers(istream& in, size_t count);
Input read_input(istream& in, bool prompt);
size_t write_data(void* items, size_t item_size, size_t item_count, void* ctx);
Input download(const string& address);
bool check_text_parametr(string text_decoration);
void find_minmax(const vector<double>& numbers, double& min, double& max);
vector<size_t> make_histogram(const Input input);
void show_histogram_text(const vector<size_t>& bins);




#endif // HISTOGRAM_H_INCLUDED
