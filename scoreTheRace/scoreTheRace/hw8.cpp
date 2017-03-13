//
//  HW8.cpp
//  scoreTheRace
//
//  Created by Jon Horn on 3/11/17.
//

#include <iostream>
using namespace std;

// return smallest value != 0
int minIndexNotEqualZero(int array[]) {
    int min = 0;
    
    // find the first non zero
    if (array[0] == 0)
        while (array[min] == 0)
            min++;
    
    for (int i = 0; i < 26; i++)
        if (array[i] != 0 && array[i] < array[min])
                min = i;

    return min;
}

// return smallest team size != 0
int smallestTeamSize(int array[26][2]) {
    int min = 0;
    
    // find the first non zero
    int aZeroZero = array[0][0];
    if (array[0][0] == 0)
        while (array[min][0] == 0)
            min++;
    
    for (int i = 0; i < 26; i++)
        if (array[i][0] != 0 && array[i][0] < array[min][0])
            min = i;
    
    return min;
}

// return lowest team score != 0
int lowestTeamScore(int array[26][2]) {
    int min = 0;
    
    // find the first non zero
//    int aZeroZero = array[0][0];
    if (array[0][1] == 0)
        while (array[min][0] == 0)
            min++;
    
    for (int i = 0; i < 26; i++)
        if (array[i][1] != 0 && array[i][1] < array[min][1])
            min = i;
    
    return min;
}

// return largest team size != 0
int largestTeamSize(int array[26][2]) {
    int max = 0;
    
    for (int i = 0; i < 26; i++)
        if (array[i][0] != 0 && array[i][0] > array[max][0])
            max = i;
    
    return max;
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
            return 0;
        
        int twoDScoring[26][2] = {0};
        
        
        
        
        for (int i = 0; i < input.length(); i++) {
            
            //convert each char to ascii
            asciiVal = (int)input[i] - 65;
            
            // set 'A' = index 0
            teamSize[asciiVal - 65]++;
            // This uses the ascii value as index and weighted positioning as score for each runner
            scoreKeeper[asciiVal] += (i + 1);
            
            twoDScoring[asciiVal][0] += 1;
            twoDScoring[asciiVal][1] += (i + 1);
        
            
        }
//        cout << twoDScoring[1][0];
//        cout << twoDScoring[1][1];
        
        // counts the number of teammates per race
        for (int i = 0; i < 26; i++)
            if (teamSize[i] != 0)
                numOfTeams++;
        
        // counts the number of teammates per race TEST CODE
        for (int i = 0; i < 26; i++)
            if (twoDScoring[i][0] != 0)
                numOfTeams++;
        
//        minTeamSize = teamSize[minIndexNotEqualZero(teamSize)];        // test if both teams are equal size
//        teamSizesEqual = (*max_element(teamSize, teamSize + 26)) == minTeamSize;
        
        //TEST CODE
        int indexOfSmallestTeam = smallestTeamSize(twoDScoring);
        int indexOfLargestTeam = largestTeamSize(twoDScoring);

        minTeamSize = twoDScoring[smallestTeamSize(twoDScoring)][0];
        int maxTeamSize = twoDScoring[largestTeamSize(twoDScoring)][0];// test if both teams are equal size
        teamSizesEqual = (maxTeamSize == minTeamSize);
        
        if (!teamSizesEqual) {
            validInput = false;
            cout << "Teams must be of equal size" << endl;
        } else {
            cout << "There are " << numOfTeams << " teams." << endl;
            cout << "Each team has " << maxTeamSize << " runners." << endl;
            cout << "Team       Score" << endl;
            
            for (int i = 0; i < 26; i++) {

                if (twoDScoring[i][1] != 0) {
//                    // use the index of teamSize array to get char ascii code
                    char team = (char)i + 65;
                    double score = (double)twoDScoring[i][1] / (double)twoDScoring[i][0];
                    cout << team << "          " << score << endl;
                }
            }
            
            int indexOfWinning = lowestTeamScore(twoDScoring);
            int valAtIndex = twoDScoring[indexOfWinning][1];

            char winningTeam = (char)lowestTeamScore(twoDScoring) + 65;
//            char winningTeam = (char)minIndexNotEqualZero(scoreKeeper);
            cout << "The winning team is team " << winningTeam << endl;
        }
    }
    return 0;
}
