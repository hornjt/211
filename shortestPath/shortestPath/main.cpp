//
//  main.cpp
//  shortestPath
//
//  Created by Jon Horn on 4/26/17.
//

#include<iostream>
#include <algorithm>

using namespace std;
const int rows = 5;
const int cols = 6;

int findShortest(int array[5][6], int row, int col) {
    int above = array[(row + 4) % 5][col];
    int left = array[row][col];
    int below = array[(row + 6) % 5][col];
    return min(above, min(left, below));
}

int main(){
    int weight[rows][cols]={
        {3,4,1,2,8,6},
        {6,1,8,2,7,4},
        {5,9,3,9,9,5},
        {8,4,1,3,2,6},
        {3,7,2,8,6,4}
    };
    
    int memo_cost[rows][cols]={0};
    
    //initialize first colum of memo_cost[][]
    
    for (int i = 0; i < rows; i++)
        memo_cost[i][0] = weight[i][0];
    
    
//    fill in rest colum of memo_cost[][]
    for (int i = 0; i < cols - 1; i++) {
        for (int j = 0; j < rows; j++) {
            int shortest = findShortest(memo_cost, j, i);
            
            // now find the smallest of them
            memo_cost[j][i + 1] = weight[j][i + 1] + shortest;
        }
    }
    
    
    
    int route[cols]={-1};
    
    int min = memo_cost[0][cols - 1];
    
    for (int i = 1; i < rows; i++) {
        if (memo_cost[i][cols - 1] < memo_cost[i - 1][cols - 1])
            min = i;
    }
    
    route[cols-1]= memo_cost[min][cols - 1]; //find final step route.
    
    
    for(int c=cols-1;c>=0;c--){// go backward to find route
        route[c]= findShortest(memo_cost, );
    }
    
    //print route
    for(int i=0;i<cols;i++){
//        cout<<"route "<<i<<" is: "<<route[i]<<" row."<<endl;
    }
//    cout<<"the shortest path is of length "<<min<<endl;
    return 0;
}
