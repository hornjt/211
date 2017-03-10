//
//  main.cpp
//  crossNumbers
//
//  Created by Jon Horn on 3/8/17.
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
    
    /* board layout
        -------
       | 1 | 4 |
   | 0 | 2 | 5 | 7 |
       | 3 | 6 |
        -------
     */
    
    int testingBoard[8][5] =
    {
        {-1},               // 0
        {0, -1},            // 1
        {0, 1, -1},         // 2
        {0, 2, -1},         // 3
        {1, 2, -1},         // 4
        {1, 2, 3, 4, -1},   // 5
        {2, 3, 5, -1},      // 6
        {4, 5, 6, -1}       // 7
    };

    int iterator = 0;
    while (testingBoard[column][iterator] != -1) {
        int boardIndexToCheck = testingBoard[column][iterator];
        int testingValue = board[boardIndexToCheck];
        int boardValueAtACurrCol = board[column];
        
        
        if (testingValue == boardValueAtACurrCol ||
            board[boardIndexToCheck] ==  boardValueAtACurrCol - 1 ||
            board[boardIndexToCheck] ==  boardValueAtACurrCol + 1) {
            
//            cout << "match found" << endl;
            return false;
        }
        iterator++;
    }
    
    for (int i = 0; i < column; i++)
        if (board[i] == board[column])
            return false;
    
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

void print(int board[]) {
    for(int i = 0; i < 8; i++)
        cout << board[i] << " ";
    cout << endl;
}

int main(){
    
    int boardSize = 8, numOfSolutions = 0;
    /*board setup */
    int board[8] = {0,0,0,0,0,0,0,0};
    int column = 0;
    
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
//        print(board, boardSize, ++numOfSolutions) ;/*print section*/
        print(board);
        from_backtrack = true;
        backtrack(column);
    }
}
