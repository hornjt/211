//
//  main.cpp
//  shortestPathRecursive
//
//  Created by Jon Horn on 4/27/17.
//  Copyright © 2017 Jon Horn. All rights reserved.
//

#include<iostream>
using namespace std;
const int rows = 5;
const int cols = 6;

int cost(int i, int j){ // i is the row, j is the column
    int weight[rows][cols]={
        {3,4,1,2,8,6},
        {6,1,8,2,7,4},
        {5,9,3,9,9,5},
        {8,4,1,3,2,6},
        {3,7,2,8,6,4}};
    
    //base case
    if(j==0)
        return weight[i][0];
    
    // recursive call
    int left = weight[i][j] + cost(i, j - 1);
    int up = weight[i][j] + cost((i + 4) % rows, j - 1);
    int down = weight[i][j] + cost((i + 6) % rows, j - 1);
    
    // find the value of the shortest path through cell (i,j)
    int min = _________
    
    …some code goes here
    
    return min;
}

int main(){
    int ex[rows];
    
    // get the shortest path out of each cell on the right
    for( int i=0; i<rows; i++)
        ex[i]=cost(i,cols-1);
    
    // now find the smallest of them
    int min= ;
    
    …some code goes here
    
    cout<<"the sortest path is of length "<<min<<endl;
    system("PAUSE");
    return EXIT_SUCCESS;
    
}
