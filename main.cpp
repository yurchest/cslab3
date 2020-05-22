#include <iostream>
#include <vector>
#include "histogram.h"
#include "svg.h"

#include <sys/utsname.h>

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

    string text_decoration;
    cerr << "Enter text decoration parametr";
    cin >> text_decoration;

   if (check_text_parametr(text_decoration) == false){
        cerr << "Text parametr is incorrect. Please rewrite it and restart the program";
        svg_begin(1000,500);
        svg_text(20, 20, "Text parametr is incorrect. Please rewrite it and restart the program");
        svg_end();
    return 1;
    }

    //MAKE HISTOGRAM
    const auto bins = make_histogram(numbers, bin_count);

    show_histogram_svg(bins,text_decoration);

    return 0;
}
