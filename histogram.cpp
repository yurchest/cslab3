#include "histogram.h"
#include <iostream>
#include <vector>

using namespace std;

/*
vector<double>
input_numbers(size_t count) {
    vector<double> result(count);
    for (size_t i = 0; i < count; i++) {
        cin >> result[i];
    }
    return result;
}

*/


vector<double>
input_numbers(istream& in, size_t count) {
    vector<double> result(count);
    for (size_t i = 0; i < count; i++) {
        in >> result[i];
    }
    return result;
}


Input
read_input(istream& in, bool prompt) {
    Input data;

    if (prompt) cerr << "Enter number count: ";
    size_t number_count;
    cin >> number_count;

    if (prompt) cerr << "Enter numbers: ";
    data.numbers = input_numbers(in, number_count);

    if (prompt) cerr << "Enter bin count ";
    in >> data.bin_count;

/*
    cerr << "Enter text decoration parametr";
    string text_decoration;
    cin >> text_decoration;
*/

    return data;
}


bool check_text_parametr(string text_decoration){

     if((text_decoration != "none") && (text_decoration != "underline") && (text_decoration != "overline") && (text_decoration != "line-through")){
     return false;
     }

    return true;
}

void
find_minmax(const vector<double>& numbers, double& min, double& max){

    if (numbers.size() == 0){
        return;
        }


    min = numbers[0];
    max = numbers[0];
    for (double x : numbers) {
        if (x < min) {
            min = x;
        }
        else if (x > max) {
            max = x;
        }
    }
    return;
}

vector<size_t>
make_histogram(const Input input){


    vector<size_t> bins(input.bin_count, 0);
    double min, max;
    find_minmax(input.numbers, min, max);
    for (double x : input.numbers){
        size_t bin_index = (size_t)((x - min)/(max - min) * input.bin_count);
        if (bin_index == input.bin_count){
            bin_index--;
        }
    bins[bin_index]++;
    }

    return bins;
}

void
show_histogram_text(const vector<size_t>& bins){





    for(size_t bin : bins){

        if (bin < 100) {
            cout << ' ';
        }
        if (bin < 10) {
            cout << ' ';
        }
        cout << bin << "|";




     for(size_t i = 0; i < bin; i++){
            cout << "*";}
        cout << endl;

    }



    return;
}
