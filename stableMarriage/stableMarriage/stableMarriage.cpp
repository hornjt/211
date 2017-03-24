//
//  main.cpp
//  stableMarriage
//
//  Created by Jon Horn on 3/21/17.
//  Copyright © 2017 Jon Horn. All rights reserved.
//

#include <iostream>
using namespace std;

bool ok(int board[], int column){
    
    int board0 = board[0];
    int board1 = board[1];
    int board2 = board[2];
    int board3 = board[3];
    int board4 = board[4];
    int board5 = board[5];
    int board6 = board[6];
    int board7 = board[7];
    
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
