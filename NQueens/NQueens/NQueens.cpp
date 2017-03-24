// Horn, Jonathan
// CS211  Section 52B Homework 5
// Eight Queens - 1 Dimen Array Without GOTO
//  Created by Jon Horn on 2/24/17
//

#include <iostream>
using namespace std;

bool ok(int board[], int column){
    
    // tests
    int board0 = board[0];
    int board1 = board[1];
    int board2 = board[2];
    int board3 = board[3];
    int board4 = board[4];
    int board5 = board[5];
    int board6 = board[6];
    int board7 = board[7];
    
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
    
    int boardSize = 8, numOfSolutions = 0;
    /*board setup */
    int board[8] = {0}, column = 0;

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
