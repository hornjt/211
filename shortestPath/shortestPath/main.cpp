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

int main(){
    int weight[rows][cols]={
        {3,4,1,2,8,6},
        {6,1,8,2,7,4},
        {5,9,3,9,9,5},
        {8,4,1,3,2,6},
        {3,7,2,8,6,4}
    };
    
//    cout << (1 + 5 ) % 5 << endl;
    
    int memo_cost[rows][cols]={0};
    
    //initialize first colum of memo_cost[][]
    
    for (int i = 0; i < rows; i++)
        memo_cost[i][0] = weight[i][0];
    
    
//    fill in rest colum of memo_cost[][]
    for (int i = 0; i < cols - 1; i++) {
        for (int j = 0; j < rows; j++) {
            int above = memo_cost[(j + 4) % 5][i];
            int left = memo_cost[j][i];
            int below = memo_cost[(j + 6) % 5][i];
            
//            if (memo_cost[j][i + 1] == 0)
            memo_cost[j][i + 1] = weight[j][i + 1] + min(above, min(left, below));
//            else memo_cost[j][i + 1] = memo_cost[j][i + 1] + min(above, min(left, below));
    
            int stop = 0;
            
//            memo_cost[j][i + 1] =
            
//            cout << "Row " << i << " column " << j + 1 << " has neighbors of " << above << left << below << endl;
        
        }
    }
    
    // now find the smallest of them
    
    int route[cols]={-1};
//    route[cols-1]=____; //find final step route.
    
    for(int c=cols-2;c>=0;c--){// go backward to find route
        //compare 3 square and find min
        
//        route[c]=___;
    }
    
    //print route
    for(int i=0;i<cols;i++){
//        cout<<"route "<<i<<" is: "<<route[i]<<" row."<<endl;
    }
//    cout<<"the shortest path is of length "<<min<<endl;
    return 0;
}
