#include "histogram.h"

#include <cassert>

void
test_positive() {
    double min = 0;
    double max = 0;
    find_minmax({1, 2, 3}, min, max);
    assert(min == 1);
    assert(max == 3);
}

void
test_negative(){
    double min;
    double max;
    find_minmax({-3, -7,-125}, min, max);
    assert(min == -125);
    assert(max == -3);
}

void
test_one_number(){
    double min;
    double max;
    find_minmax({532}, min, max);
    assert(min == 532);
    assert(max == 532);
}

void
test_empty_vector(){
    double min;
    double max;
    find_minmax({}, min, max);
    assert(min == 0);
    assert(max == 0);
}

int main() {
    test_positive();
    test_negative();
}
