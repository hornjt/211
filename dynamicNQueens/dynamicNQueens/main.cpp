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
        exit(0);
    }
    
}
void print(int board[], int numOfColumns, int numOfSolutions) {
    int i = 0, j = 0;
    cout << "Solution number " << numOfSolutions << " is: " << endl;
    for(int i = 0; i < numOfColumns; i++)
        cout << board[i] << " ";
    cout << endl << endl;
    for (i = 0; i < numOfColumns; i++) {
        for (j = 0; j < numOfColumns; j++) {
            if (i == board[j])
                cout << "1 ";
            else cout << "0 ";
        }
        cout << endl;
    }
    cout << endl;
}
int main(){
    int boardSize;
    cout << "Enter board size";
    cin >> boardSize;
    int board[boardSize];
    int numOfSolutions = 0;
    int column = 0;
    
    //int boardSize = 8;
    /*board setup */
    // int board[8] = {0};
    
    //board[0] = 0;
    
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
