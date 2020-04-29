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
    double min =5;
    double max =5 ;
    find_minmax({}, min, max);
    assert(min == 5);
    assert(max == 5 );
}

void
test_same_numbers(){
    double min;
    double max;
    find_minmax({2,2,2}, min, max);
    assert(min == 2);
    assert(max == 2);
}

void
test_text_parametr_true(){
    assert(check_text_parametr("underline") == true);

}

void
test_text_parametr_false(){
    assert(check_text_parametr("podcherknuto") == false);

}


int main() {
    test_positive();
    test_negative();
    test_one_number();
    test_empty_vector();
    test_same_numbers();

    test_text_parametr_true();
    test_text_parametr_false();
}
