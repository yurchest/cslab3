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



void
svg_text(double left, double baseline, string text) {
    cout << "<text x='" << left << "' y='" << baseline << "' >"<< text <<"</text>";
}

void
svg_rect(double x, double y, double width, double height,
        string stroke, string fil){
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

void
show_histogram_svg(const vector<size_t>& bins) {

    const auto IMAGE_WIDTH = 400;
    const auto IMAGE_HEIGHT = 300;
    const auto TEXT_LEFT = 20;
    const auto TEXT_BASELINE = 20;
    const auto TEXT_WIDTH = 50;
    const auto BIN_HEIGHT = 30;
    const auto BLOCK_WIDTH = 10;

    svg_begin(IMAGE_WIDTH, IMAGE_HEIGHT);

    double top = 0;

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
        svg_text(TEXT_LEFT, top + TEXT_BASELINE, to_string(bin));
        svg_rect(TEXT_WIDTH, top, bin_width, BIN_HEIGHT, "green", "#ffeeee");
        top += BIN_HEIGHT;
    }

   // svg_text(TEXT_LEFT, TEXT_BASELINE, to_string(bins[0]));
   // svg_rect(TEXT_WIDTH, 0, bins[0] * BLOCK_WIDTH, BIN_HEIGHT);
    svg_end();
}


