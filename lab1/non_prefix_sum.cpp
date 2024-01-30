#include "prefix_sum.h"
#include <iostream>

bool non_negative_prefix(int ary[], int length) {
    bool non_negative = true;
    int sum = 0;
    
    for (int index = 0; index < length; index++) {
        sum += ary[index];
        if (sum < 0) {
            non_negative = false;
            break;
        }
    }
    return non_negative;
}

bool non_positive_prefix(int ary[], int length) {
    bool non_positive = true;
    int sum = 0;

    for (int index = 0; index < length; index++) {
        sum += ary[index];
        if (sum > 0) {
            non_positive = false;
            break;
        }
    }
    return non_positive;
}

int prefix_sum(int ary[], int length) {
    int sum = 0;
    for (int i = 0; i < length; i++) {
        sum += ary[i];
    }
    return sum;
}
