#ifndef SVG_H_INCLUDED
#define SVG_H_INCLUDED

#include <iostream>
#include <vector>



void svg_text(double left, double baseline, string text);
void svg_rect(double x, double y, double width, double height,
        string stroke = "black", string fil = "black");
void svg_begin(double width, double height);
void svg_end();
void show_histogram_svg(const vector<size_t>& bins);



#endif
