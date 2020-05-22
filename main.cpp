#include <iostream>
#include <vector>
#include "histogram.h"
#include "svg.h"
#include <curl/curl.h>

#include <sys/utsname.h>

using namespace std;


int main(int argc, char* argv[]){

    Input input;

    if (argc > 1) {
        input = download(argv[1]);
    } else {
        input = read_input(cin, true);
    }

    if (check_text_parametr(input.text_decoration) == false){
        cerr << "Text parametr is incorrect. Please rewrite it and restart the program";
        svg_begin(1000,500);
        svg_text(20, 20, "Text parametr is incorrect. Please rewrite it and restart the program");
        svg_end();
    return 1;
    }


    //MAKE HISTOGRAM
    const auto bins = make_histogram(input);

    show_histogram_svg(bins,input.text_decoration);

    return 0;
}
