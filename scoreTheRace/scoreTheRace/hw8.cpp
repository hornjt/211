//
//  HW8.cpp
//  scoreTheRace
//
//  Created by Jon Horn on 3/11/17.
//

#include <iostream>
using namespace std;

// return smallest value != 0
int minElementNotEqualZero(int array[]) {
    int min = 0;
    
    // find the first non zero
    if (array[0] == 0)
        while (array[min] == 0)
            min++;
    
    for (int i = 0; i < 92; i++)
        if (array[i] != 0 && array[i] < array[min])
                min = i;

    return min;
}

int main() {
    string input;
    
    // array to track the score each runner generates
    bool validInput = true, teamSizesEqual = true;
    
    while (input != "DONE") {
        int scoreKeeper[91] = {0}, teamSize[26] = {0}, asciiVal = 0, numOfTeams = 0, minTeamSize = 0;
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
        
        // counts the number of teammates per race
        for (int i = 0; i < 26; i++)
            if (teamSize[i] != 0)
                numOfTeams++;
        
        minTeamSize = teamSize[minElementNotEqualZero(teamSize)];        // test if both teams are equal size
        teamSizesEqual = (*max_element(teamSize, teamSize + 26)) == minTeamSize;
        
        if (!teamSizesEqual) {
            validInput = false;
            cout << "Teams must be of equal size" << endl;
        } else {
            cout << "There are " << numOfTeams << " teams." << endl;
            cout << "Each team has " << teamSize[0] << " runners." << endl;
            cout << "Team       Score" << endl;
            
            for (int i = 0; i < 91; i++) {

                if (teamSize[i] != 0) {
//                    // use the index of teamSize array to get char ascii code
                    char team = (char)i + 65;
                    double score = (double)scoreKeeper[i + 65] / (double)teamSize[i];
                    cout << team << "          " << score << endl;
                }
            }

            char winningTeam = (char)minElementNotEqualZero(scoreKeeper);
//            cout << winningTeam;
            cout << "The winning team is team " << winningTeam << endl;
        }
    }
    return 0;
}
