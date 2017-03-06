// Horn, Jonathan
// CS211  Section 52B Homework 4
// Eight Queens - Single-Dimen Array
//
//  Created by Jon Horn on 2/21/17.
//

#include <iostream>

using namespace std;

void findAllSolutions() {
    
    int board[8], column = 0, i = 0, solutionsFound = 0;
    board[0] = 0;
nextColumn:
    column++;
    if (column == 8)
        goto print;
    board[column] = -1;
nextRow:
    board[column]++;
    if (board[column] == 8)
        goto backtrack;
    // tests
    for (i = 0; i < column; i++) {
        int deltaX = column - i;
        int deltaY = board[column] - board[i];
        if (board[i] == board[column] || deltaX == abs(deltaY))
            goto nextRow;
    }
    goto nextColumn;
backtrack:
    column--;
    if (column == -1)
        return;
    goto nextRow;
print:
    cout << "Solution number " << ++solutionsFound << " is: " << endl;
    for(i = 0; i < 4; i++)
        cout << board[i] << " ";
    cout << endl << endl;
    for (i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (i == board[j])
                cout << "1 ";
            else cout << "0 ";
        }
        cout << endl;
    }
    cout << endl;
    goto backtrack;
}

int main() {
//    int input = 8;
//    cout << "Enter the board size you want to display: ";
//    cin >> input;
    findAllSolutions();
}





