//
//  HW8.cpp
//  scoreTheRace
//
//  Created by Jon Horn on 3/11/17.
//

#include <iostream>
using namespace std;

//bool greaterThan(int a, int b) {
//    return a < b;
//}
//
//bool lessThan(int a, int b) {
//    return a < b;
//}
//
//typedef int (*FUNC)(int, int);
//
//int findDifference(int array[26][2], int column,  *FUNC) {
//    int min = 0;
//    
//    // find the first non zero
//    if (array[0][column] == 0)
//        while (array[min][0] == 0)
//            min++;
//    
//    // find smallest non zero
//    for (int i = 0; i < 26; i++)
//        if (array[i][column] != 0 && *func(array[i][column], array[min][column]))
//            min = i;
//    
//    return min;
//}

// return smallest team size != 0
// column represents whether we are testing the team score or number of team members
int findSmallest(int array[26][2], int column) {
    int min = 0;
    
    // find the first non zero
    if (array[0][column] == 0)
        while (array[min][0] == 0)
            min++;
    
    // find smallest non zero
    for (int i = 0; i < 26; i++)
        if (array[i][column] != 0 && array[i][column] < array[min][column])
            min = i;
    
    return min;
}

// return largest team size != 0
int findLargest(int array[26][2]) {
    int max = 0;
    
    for (int i = 0; i < 26; i++)
        if (array[i][0] != 0 && array[i][0] > array[max][0])
            max = i;
    
    return max;
}

int main() {
    string input;
    
    // array to track the score each runner generates
    bool validInput = true;
    
    while (input != "DONE") {
        
        // scoringTable = { [number of runners per team], [team score] }
        
        int scoringTable[26][2] = {0}, asciiVal = 0, numOfTeams = 0, minTeamSize = 0, maxTeamSize = 0;
        
        cout << "Enter the race" << endl;
        cin >> input;
        transform(input.begin(), input.end(),input.begin(), ::toupper);
        if (input == "DONE")
            return 0;

        for (int i = 0; i < input.length(); i++) {
            
            //convert each char to ascii
            asciiVal = (int)input[i] - 65;
            
            // increment number of runners
            scoringTable[asciiVal][0] += 1;
            
            // add score to team based on position in race
            scoringTable[asciiVal][1] += (i + 1);
        }
        
        // counts the number of teammates per race
        for (int i = 0; i < 26; i++)
            if (scoringTable[i][0] != 0)
                numOfTeams++;
        
        int indexOfSmallestTeam = findSmallest(scoringTable, 0);
        int indexOfLargestTeam = findLargest(scoringTable);

        // test if both teams are equal size
        minTeamSize = scoringTable[indexOfSmallestTeam][0];
        maxTeamSize = scoringTable[indexOfLargestTeam][0];
        
        if (!(maxTeamSize == minTeamSize)) {
            validInput = false;
            cout << "Teams must be of equal size" << endl;
        } else {
            cout << "There are " << numOfTeams << " teams." << endl;
            cout << "Each team has " << maxTeamSize << " runners." << endl;
            cout << "Team       Score" << endl;
            
            for (int i = 0; i < 26; i++) {
                // if team ran in race, convert to char and print their team name
                if (scoringTable[i][1] != 0) {
                    // use the index of array to get char ascii code
                    char team = (char)i + 65;
                    double score = (double)scoringTable[i][1] / (double)scoringTable[i][0];
                    cout << team << "          " << score << endl;
                }
            }
            char winningTeam = (char)findSmallest(scoringTable, 1) + 65;
            cout << "The winning team is team " << winningTeam << endl;
        }
    }
    return 0;
}
