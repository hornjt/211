// Horn, Jonathan
// CS211  Section 52B Homework 3
// Eight Queens - Two-Dimen Array
//  Created by Jon Horn on 2/17/17.
//

#include <iostream>
using namespace std;

void findEightQueens() {
    int board[8][8] = {0}, row, column, i, solutionsCounter = 1;
    
    board[0][0] = 1;
next_col:
    column++;
    row = -1;
    if (column == 8)
        goto print;
next_row:
    row++;
    if (row == 8)
        goto backtrack;
    for (i = 0; i < column; i++) { // row test
        if (board[row][i])
            goto next_row;
    }
    for (i = 1; row - i >= 0 && column - i >= 0; i++) { // up diagonal
        if (board[row - i][column - i])
            goto next_row;
    }
    for (i = 1; row + i <= 7 && column - i >= 0; i++) { // down diagonal
        if (board[row + i][column - i])
            goto next_row;
    }
    board[row][column] = 1;
    goto next_col;
backtrack:
    column--;
    if (column == -1)
        return;
    row = 0;
    while (board[row][column] != 1)
        row++;
    board[row][column] = 0;
    goto next_row;
print:
    cout << "Solution number " << solutionsCounter++ << " is " << endl;
    for (int j = 0; j < 8; j++) {
        for(int k = 0; k < 8; k++) {
            cout << board[j][k] << " ";
        }
        cout << endl;
    }
    cout << endl;
    goto backtrack;
}

int main() {
    findEightQueens();
}
