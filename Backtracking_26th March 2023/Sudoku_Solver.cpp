#include<iostream>
#include<vector>
using namespace std;
bool isSafe(int value,int board[][9],int curr_row,int curr_col){
    // row check
    for(int col = 0;col<9;col++){
        if(board[curr_row][col] == value){
            return false; // Not safe
        }
    }
    // column check
    for(int row = 0;row<9;row++){
        if(board[row][curr_col] == value){
            return false; // Not safe
        }
    }
    // check 3x3 box
    for(int i = 0;i<9;i++){
        if(board[3*(curr_row/3) + (i/3)][3*(curr_col/3) + (i%3)] == value){
            return false;
        }
    }

    return true;
}
// No need of base case in this question
// Tweek done-> make it bool
bool solve(int board[9][9],int n){
    
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            // Check for empty cell
            if(board[i][j] == 0){
                for(int value = 1;value<=9;value++){
                    // Check for safety 
                    if(isSafe(value,board,i,j)){
                        // insert if safe
                        board[i][j] = value;
                        // Recursion will handle
                        bool aagekaSolution = solve(board,n);
                        // Found solution or not?
                        // This if condition is the reason we dont need base case
                        if(aagekaSolution == true){
                            return true;
                        }
                        // Backtracking if solution not found
                        else
                            board[i][j] = 0;

                    }
                }
                return false; // If no solution from 1 to 9, then that means previous placement has some fault
            }

        }
    }
    return true;  // All cells are filled
}
int main(){
    int board[9][9] = {
        {4,5,0,0,0,0,0,0,0},
        {0,0,2,0,7,0,6,3,0},
        {0,0,0,0,0,0,0,2,8},
        {0,0,0,9,5,0,0,0,0},
        {0,8,6,0,0,0,2,0,0},
        {0,2,0,6,0,0,7,5,0},
        {0,0,0,0,0,0,4,7,6},
        {0,7,0,0,4,5,0,0,0},
        {0,0,8,0,0,9,0,0,0}
    };

    int n = 9;
    solve(board,n);
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}