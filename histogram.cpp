#include "histogram.h"
#include <iostream>
#include <vector>

using namespace std;



vector<double>
input_numbers(size_t count) {
    vector<double> result(count);
    for (size_t i = 0; i < count; i++) {
        cin >> result[i];
    }
    return result;
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
make_histogram(const vector<double>& numbers, size_t& bin_count){

    vector<size_t> bins(bin_count, 0);
    double min, max;
    find_minmax(numbers, min, max);
    for (double x : numbers){
        size_t bin_index = (size_t)((x - min)/(max - min) * bin_count);
        if (bin_index == bin_count){
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





