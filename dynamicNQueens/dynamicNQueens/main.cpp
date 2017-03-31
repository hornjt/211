//
//  main.cpp
//  dynamicNQueens
//
//  Created by Jon Horn on 3/30/17.
//  Copyright © 2017 Jon Horn. All rights reserved.
//

#include <iostream>
using namespace std;

bool ok(int board[], int column){
    
    for (int i = 0; i < column; i++) {
        int deltaX = column - i;
        int deltaY = board[column] - board[i];
        if (board[i] == board[column] || deltaX == abs(deltaY))
            return false;
    }
    return true;
}

void backtrack(int &col){
    //decrease col
    col--;
    if (col == -1) {
        //set stop point
        return;
    }
}

int solveBoard(int boardSize) {
    int * board = new int[boardSize];
    int numOfSolutions = 0, column = 0;
    
    bool from_backtrack = false;
    while (true) {
        while (column < boardSize) {
            if (column == -1) // no more solutions for this size board
                return numOfSolutions;
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
        numOfSolutions++;
        from_backtrack = true;
        backtrack(column);
    }
}


int main(){
    int boardSize;
    cout << "Enter board size you want to solve: " << endl;
    cin >> boardSize;
    for (int i = 1; i <= boardSize; i++) {
        int solutions = solveBoard(i);
        cout << "There are " << solutions << " solutions to the " << i << " queens problem" << endl;
    }
}
