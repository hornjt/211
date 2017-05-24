//
//  main.cpp
//  continuedFractions
//
//  Created by Jon Horn on 5/10/17.
//  Copyright © 2017 Jon Horn. All rights reserved.
//

#include <iostream>
using namespace std;

void reduce(int &numerator, int &denominator) {
    for (int i = numerator; i > 1; i--) {
        if (numerator % i == 0 && denominator % i == 0) {
            numerator /= i;
            denominator /= i;
            break;
        }
    }
}

double findDouble(int array[]) {
    double total = array[0];
    int iterator = 1;
    while (array[iterator] != -1)
        total += (1.0 / array[iterator++]);
    return total;
}

int* findFraction() {
    int array[] = {2, 3, 4, 5, -1};
    int iterator = 1;
    int fraction[2] = {0};
    
    fraction[0] = array[0]; // 2
    fraction[1] = 1;    // 1
    while (array[iterator] != -1) {
        fraction[0] = (fraction[0] * array[iterator]) + 1;
        fraction[1] = array[iterator];
        iterator++;
    }
    reduce(fraction[0], fraction[1]);
    return fraction;
    
    
}




int main(int argc, const char * argv[]) {
//    int array[] = {1, 2, 3, 4, -1}; // double test
//    cout << findDouble(array) << endl;
    findFraction();
    
}

