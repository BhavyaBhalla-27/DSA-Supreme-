#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
unordered_map<int,bool>rowCheck;
unordered_map<int,bool>upperLeftDiagonalCheck;
unordered_map<int,bool>lowerLeftDiagonalCheck;
void printSolution(vector<vector<int>>&board,int n){
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl<<endl;
}
bool isSafe(int row,int col,vector<vector<int>>&board,int n){
    if(rowCheck[row] == true)
        return false;
    if(upperLeftDiagonalCheck[n-1+col-row] == true){
        return false;
    }
    if(lowerLeftDiagonalCheck[row+col] == true){
        return false;
    }
    return true;
}
void solve(vector<vector<int>>&board,int col,int n){
    // Base Case -> When we have placed queens in all the columns then col will go to n
    if(col >= n){
        printSolution(board,n);
        return;
    }
    // Just Solve one case 
    // In every row, place the queen
    for(int row = 0;row<n;row++){
        if(isSafe(row,col,board,n)){
            // Place it then
            board[row][col] = 1; // 1 means queen, 0 means no queen
            // Map modification
            rowCheck[row] = true;
            upperLeftDiagonalCheck[n-1+col-row] = true;
            lowerLeftDiagonalCheck[row+col] = true;
            // Recursive call for col + 1
            solve(board,col+1,n);
            // Backtracking -> Create original state
            board[row][col] = 0; // Queen removed 
            // Map modification -> recreate original state
            rowCheck[row] = false;
            upperLeftDiagonalCheck[n-1+col-row] = false;
            lowerLeftDiagonalCheck[row+col] = false;
        }
    }
}
int main(){
    int n = 4;
    // Initially all are zeroes in the nxn chessboard
    vector<vector<int>>board(n,vector<int>(n,0)); 
    int col = 0;
    solve(board,col,n);
    return 0;
}