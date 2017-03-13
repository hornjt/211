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
    
    while (true) {
        cout << "Enter the race" << endl;
        cin >> input;
        transform(input.begin(), input.end(),input.begin(), ::toupper);
        char stringArray[input.length()];
        
        for (int i = 0; i < length; i++) {
            stringArray[i] = input[i];
            cout << stringArray[i];
        }
        if (input == "done") {
            cout << "Done" << endl;
            break;
        }
    }
    return 0;
}
