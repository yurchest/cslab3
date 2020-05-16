#include <iostream>
#include <vector>
#include "histogram.h"
#include "svg.h"
#include <curl/curl.h>

using namespace std;



int main(int argc, char* argv[])
{
    curl_global_init(CURL_GLOBAL_ALL);

    if (argc > 1){
        CURL *curl = curl_easy_init();
        if(curl) {
          CURLcode res;
          curl_easy_setopt(curl, CURLOPT_URL, argv[1]);
          res = curl_easy_perform(curl);
          if (res) {
                cerr << curl_easy_strerror(res) << endl;
                exit(1);
            }
          curl_easy_cleanup(curl);
        }

        return 0;
    }

    string text_decoration;

    const auto input = read_input(cin, true);

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
    const auto bins = make_histogram(input);

    show_histogram_svg(bins,text_decoration);

    return 0;
}
