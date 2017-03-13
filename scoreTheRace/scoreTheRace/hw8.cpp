//
//  HW8.cpp
//  scoreTheRace
//
//  Created by Jon Horn on 3/11/17.
//

#include <iostream>
using namespace std;

// return smallest value != 0
bool minValueNotZero(int a, int b) {
    return a != 0 && a < b;
}

int main() {
    string input;
    
    // array to track the score each runner generates
    int scoreKeeper[91] = {0}, teamSize[26], asciiVal = 0;
    bool validInput = true, teamSizesEqual = true;
    
    while (validInput || input != "DONE") {
        cout << "Enter the race" << endl;
        cin >> input;
        transform(input.begin(), input.end(),input.begin(), ::toupper);
        if (input == "DONE")
            break;
        
        for (int i = 0; i < input.length(); i++) {
            asciiVal = (int)input[i];
            teamSize[asciiVal - 65]++;
        
            // This uses the ascii value as index and weighted positioning as score for each runner
            scoreKeeper[asciiVal] += (i + 1);
        }
        
        // check if teams are of equal size
        teamSizesEqual =
            (*max_element(teamSize, teamSize + 26)) ==
            (*min_element(teamSize, teamSize + 26, minValueNotZero));
        cout << teamSizesEqual;
        if (!teamSizesEqual) {
            validInput = false;
            cout << "Teams must be of equal size" << endl;
        }
    }
    return 0;
}
