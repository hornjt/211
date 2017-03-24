//
//  stableMarriage.cpp
//  stableMarriage
//  HW 11
//
//  Created by Jon Horn on 3/21/17.
//

#include <iostream>
using namespace std;

bool ok(int board[], int column){
    
    static int manPref[3][3] = {
        {0,2,1},  // Man#0's preferences
        //so man#0 likes woman0 most, woman2 next,and woman1 least
        {0,2,1},  // Man#1's preferences
        {1,2,0}}; // Man#2's preferences
    
    static int womanPref[3][3] = {
        {2,1,0},  // Woman#0's preferences
        //so woman#0 likes man2 most, man1 next,and man2 least
        {0,1,2},  // Woman#1's preferences
        {2,0,1}}; // Woman#2's preferences
    
    int newMan = column, newWoman = board[column];

    for (int i = 0; i < column; ++i) {
        int currentMan = i, currentWoman = board[i];
        if (currentWoman == newWoman) // woman already married
            return false;
        
        // current man prefers the new woman to his partner
        if (manPref[currentMan][newWoman] < manPref[currentMan][currentWoman] &&
            // new woman prefers the current man to her partner
            womanPref[newWoman][currentMan] < womanPref[newWoman][newMan])
            return false;
        
        // new man prefers the current woman to his partner
        if (manPref[newMan][currentWoman] < manPref[newMan][newWoman] &&
            // current woman prefers the new man to her partner
            womanPref[currentWoman][newMan] < womanPref[currentWoman][currentMan])
            return false;
    }
    return true;
}

void backtrack(int &col){
    //decrease col
    col--;
    if (col == -1) {
        //set stop point
        exit(0);
    }
}
void print(int board[], int numOfColumns, int numOfSolutions) {
    static int count = 0;
    cout << "Solution " << ++count << endl << endl;
    cout << "man  -  woman" << endl;
    for(int i = 0; i < 3; i++)
        cout << i << "    ---    " << board[i] << endl;
    cout << endl <<endl;
}

int main(){
    
    int boardSize = 3, numOfSolutions = 0;
    /*board setup */
    int board[8] = {0}, column = 0;
    
    board[0] = 0;
    
    bool from_backtrack = false;
    while (true) {
        while (column < boardSize) {
            if (!from_backtrack) {
                
                /*column section*/
                board[column] = -1;
                from_backtrack = true;
                
            }
            while (board[column] < boardSize){
                /*row section*/
                board[column]++;
                if (board[column] == boardSize) {
                    from_backtrack = true;
                    backtrack(column);
                    break;
                }
                
                if (ok(board, column)) {    // test rows and columns
                    from_backtrack = false;
                    column++;
                    break;
                }
            }
        }
        print(board, boardSize, ++numOfSolutions) ;/*print section*/
        from_backtrack = true;
        backtrack(column);
    }
}
