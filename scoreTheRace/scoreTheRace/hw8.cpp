//
//  HW8.cpp
//  scoreTheRace
//
//  Created by Jon Horn on 3/11/17.
//

#include <iostream>
using namespace std;

int main() {
    string input;
    
    int charCounter[91] = {0};
    int x = 0;
    while (x < 1) {
        bool validInput = true;
        cout << "Enter the race" << endl;
        cin >> input;
        transform(input.begin(), input.end(),input.begin(), ::toupper);
        
        for (int i = 0; i < input.length(); i++) {
            //offset of 65
            // This uses the ascii value as index to a letter map and element value as counter
            int asciiVal = (int)input[i];
            charCounter[asciiVal] += (i + 1);
        }
        x++;
//        if (input == "") {
//            cout << "Done" << endl;
//            break;
//        }
        
    }
    for (int i = 65; i < 91; i++) {
        cout << charCounter[i];
    }
    return 0;
}
