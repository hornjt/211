//
//  crossNumbers.cpp
//  HW7 crossNumbers - Section 52B
//
//  Created by Jon Horn on 3/8/17.
//

#include <iostream>
using namespace std;

bool ok(int board[], int column){
    
    /* 
     board layout
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

    int testBoardIterator = 0;
    while (testingBoard[column][testBoardIterator] != -1) {
        int boardIndexToCheck = testingBoard[column][testBoardIterator];
        int currIndexValue = board[column];
        
        // tests neighboring boxes + - 1 for current column value
        if (board[boardIndexToCheck] ==  currIndexValue - 1 ||
            board[boardIndexToCheck] ==  currIndexValue + 1) {
            return false;
        }
        testBoardIterator++;
    }
    
    // check for duplicates; might be a better way
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
    
    /*
     board layout
     -------
     | 1 | 4 |
 | 0 | 2 | 5 | 7 |
     | 3 | 6 |
     -------
     */
    
    cout << "    -----" << endl;
    cout << "    |" << board[1] << "|"  << board[4] << "|" << endl;
    cout << "  ---------" << endl;
    cout <<"  |" << board[0] << "|" << board[2] << "|"  << board[5] << "|" << board[7] << "|" << endl;
    cout << "  ---------" << endl;
    cout << "    |" << board[3] << "|"  << board[6] << "|" << endl;
    cout << "    -----" << endl << endl;
}

int main(){
    
//    int numOfSolutions = 0;
    /*board setup */
    int board[8] = {0,0,0,0,0,0,0,0};
    int column = 0;
    
    bool from_backtrack = false;
    while (true) {
        while (column < 8) {
            if (!from_backtrack)
                board[column] = -1;
            
            while (board[column] < 8){
                /*row section*/
                board[column]++;
                if (board[column] == 8) {
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
        
        print(board);
        from_backtrack = true;
        backtrack(column);
    }
}
