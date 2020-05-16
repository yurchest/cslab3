#include <iostream>
#include <vector>
#include "histogram.h"
#include "svg.h"

using namespace std;

struct Input {
    vector<double> numbers;
    size_t bin_count;
};

Input
read_input(istream& in) {
    Input data;

    cerr << "Enter number count: ";
    size_t number_count;
    cin >> number_count;

    cerr << "Enter numbers: ";
    data.numbers = input_numbers(in, number_count);

    cerr << "Enter bin count ";
    in >> data.bin_count;

/*
    cerr << "Enter text decoration parametr";
    string text_decoration;
    cin >> text_decoration;
*/

    return data;
}

int main()
{
    string text_decoration;

    const auto input = read_input(cin);

/*
    if (check_text_parametr(text_decoration) == false){
        cerr << "Text parametr is incorrect. Please rewrite it and restart the program";
        svg_begin(1000,500);
        svg_text(20, 20, "Text parametr is incorrect. Please rewrite it and restart the program");
        svg_end();
    return 1;
    }
*/

    //MAKE HISTOGRAM
    const auto bins = make_histogram(input.numbers, input.bin_count);

    show_histogram_svg(bins,text_decoration);

    return 0;
}
