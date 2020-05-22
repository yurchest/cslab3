#include "histogram.h"
#include <iostream>
#include <vector>
#include <sstream>
#include <string>

#include <sys/utsname.h>

using namespace std;


void
svg_text(double left, double baseline, string text, string text_decoration) {
    cout << "<text x='" << left << "' y='" << baseline << "' text-decoration='" << text_decoration << "' >" << text <<"</text>";
}

void
svg_rect(double x, double y, double width, double height,
        string stroke , string fil){
    cout << "<rect x='" << x <<"' y='" << y << "' width='" << width << "' height='" << height
    << "' stroke='" << stroke << "' fill='" << fil << "' />";
}


void
svg_begin(double width, double height) {
    cout << "<?xml version='1.0' encoding='UTF-8'?>\n";
    cout << "<svg ";
    cout << "width='" << width << "' ";
    cout << "height='" << height << "' ";
    cout << "viewBox='0 0 " << width << " " << height << "' ";
    cout << "xmlns='http://www.w3.org/2000/svg'>\n";
}

void
svg_end() {
    cout << "</svg>\n";
}

string
make_info_text() {

//Windows v5.1 (build 1234)
//Computer name: My-Comp

    stringstream buffer;
    struct utsname namesys;
    uname(&namesys);
    buffer << namesys.sysname << " ( " << namesys.version << " ) | ";
    buffer << "Computer name: " << namesys.nodename;

    return buffer.str();
}


void
show_histogram_svg(const vector<size_t>& bins,string text_decoration) {

    const auto IMAGE_WIDTH = 1000;
    const auto IMAGE_HEIGHT = 300;
    const auto TEXT_LEFT = 20;
    const auto TEXT_BASELINE = 20;
    const auto TEXT_WIDTH = 50;
    const auto BIN_HEIGHT = 30;
    const auto BLOCK_WIDTH = 10;

    svg_begin(IMAGE_WIDTH, IMAGE_HEIGHT);

    double top = 20;

       size_t max_count = bins[0];
    for(size_t bin : bins){
        if (bin > max_count) {
            max_count = bin;
        }
     }
     const size_t SCREEN_WIDTH = 100;
     const size_t MAX_ASTERISK = SCREEN_WIDTH - 50 - 20;


    for (size_t bin : bins) {


     const bool scaling_needed = max_count < MAX_ASTERISK;

     size_t binkoeff = bin;

         if (scaling_needed) {
            const double koeff = (double)MAX_ASTERISK / max_count;
            binkoeff= (size_t)(bin * koeff);
        }


        const double bin_width = BLOCK_WIDTH * binkoeff;
        svg_text(TEXT_LEFT, top + TEXT_BASELINE, to_string(bin), text_decoration);
        svg_rect(TEXT_WIDTH, top, bin_width, BIN_HEIGHT, "green", "#ffeeee");
        top += BIN_HEIGHT;

    }
    svg_text(TEXT_LEFT, top + TEXT_BASELINE, make_info_text(), text_decoration);

   // svg_text(TEXT_LEFT, TEXT_BASELINE, to_string(bins[0]));
   // svg_rect(TEXT_WIDTH, 0, bins[0] * BLOCK_WIDTH, BIN_HEIGHT);
    svg_end();
}
