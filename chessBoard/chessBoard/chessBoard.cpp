//
//  chessBoard.cpp
//  hw9 - fancy output of chessboard
//
//  Created by Jon Horn on 3/14/17.
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
    const string black = "\u2588";
    typedef string box[5][7];
    box blackBox, whiteBox, *chessBoard[8][8], whiteQueen, blackQueen;
    int i = 0, j = 0, k = 0, l = 0;
    
    for (i = 0; i < 5; ++i){        //for each row
        for (j = 0; j < 7; ++j) {   //for each column
            whiteBox[i][j] = ' ';         //fill white (space char)
            whiteQueen[i][j] = ' ';       //fill white queen initially all white
            blackBox[i][j] = black;   //fill black
            blackQueen[i][j] = black;   //fill black queen initally all black
        }
    }
    
    whiteQueen[1][1] = black;
    whiteQueen[1][3] = black;
    whiteQueen[1][5] = black;
    for (int x = 2; x < 4; x++)
        for (int y = 1; y < 6; y++)
            whiteQueen[x][y] = black;
    
    blackQueen[1][1] = " ";
    blackQueen[1][3] = " ";
    blackQueen[1][5] = " ";
    for (int x = 2; x < 4; x++)
        for (int y = 1; y < 6; y++)
            blackQueen[x][y] = " ";
    
    //fill board with pointers to blackBox and whiteBox in alternate positions
    for (i = 0; i < 8; ++i){        //for each row
        for (j = 0; j < 8; ++j){    //for each column
            if ((i + j) % 2 == 0 && i == board[j])
                chessBoard[i][j] = &whiteQueen;
            else if ((i + j) % 2 == 0)
                chessBoard[i][j] = &whiteBox;
            else if (i == board[j])
                chessBoard[i][j] = &blackQueen;
            else chessBoard[i][j] = &blackBox;
        }
    }
    
    // print the board via the pointers in array board
    // first print upper border
    cout<<" ";
    for (i = 0; i < 7 * 8; i++)
        cout << '_';
    cout << endl;
    
    // now print the board
    for (i = 0; i < 8; ++i){                //for each board row
        for (k = 0; k < 5; ++k) {           //for each box row
            cout<<" "<< string("\u2503"); //print left border
            for (j = 0; j < 8; ++j) {        //for each board column
                for (l = 0; l < 7; ++l) {    //for each box column
                    cout << (*chessBoard[i][j])[k][l]; //k is box row, l is box column
                }
            }
            cout<<string("\u2503")<<endl; // at end of line print bar and then newline
        }
    }
    cout<<" ";
    for(i=0;i<7*8;i++)
        cout<<string("\u2501");
    cout<<endl;
}
//    cout << "Solution number " << numOfSolutions << " is: " << endl;
//    for (int i = 0; i < numOfColumns; i++)
//        cout << board[i] << " ";
//    cout << endl << endl;
//    for (i = 0; i < numOfColumns; i++) {
//        for (j = 0; j < numOfColumns; j++) {
//            if (i == board[j])
//                cout << "1 ";
//            else cout << "0 ";
//        }
//        cout << endl;
//    }
//    cout << endl;

int main() {
    
    int boardSize = 8, numOfSolutions = 0;
    /*board setup */
    int board[boardSize], column = 0;
    
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
        cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' );
    }
}
