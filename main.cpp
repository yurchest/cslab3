#include <iostream>
#include <vector>
#include "histogram.h"


using namespace std;

int main()
{

    size_t number_count;
    cerr<<"Enter number count ";
    cin>>number_count;

    cerr<<"Enter massive"<<endl;
    const auto numbers = input_numbers(number_count);

    size_t bin_count;
    cerr<<"Enter bin count ";
    cin>>bin_count;

    //MAKE HISTOGRAM
    const auto bins = make_histogram(numbers, bin_count);

    //SHOW HISTOGRAM
    // show_histogram_text(bins);
    show_histogram_svg(bins);

    return 0;
}
