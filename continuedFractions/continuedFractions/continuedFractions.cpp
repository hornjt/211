//
//  main.cpp
//  continuedFractions
//
//  Created by Jon Horn on 5/10/17.
//  Copyright © 2017 Jon Horn. All rights reserved.
//

#include <iostream>
using namespace std;

double continuedFractionDouble(int array[]) {
    double total = array[0];
    int iterator = 1;
    while (array[iterator] != -1)
        total += (1.0 / array[iterator++]);
    return total;
    
}

int main(int argc, const char * argv[]) {
    int array[] = {1, 2, 3, 4, -1};
    cout << continuedFractionDouble(array) << endl;
}

