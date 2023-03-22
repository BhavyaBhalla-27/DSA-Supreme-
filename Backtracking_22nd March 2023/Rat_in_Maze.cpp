#include<iostream>
#include<vector>
using namespace std;
bool isSafe(int x,int y,int row,int col,int arr[][3],vector<vector<bool>>&visited){
    // 3 conditions should be satisified 
    if( (x>=0 && x<row) && (y>=0 && y<col) && (arr[x][y] == 1) && (visited[x][y] == false)){
       return true; 
    }
    else{
        return false;
    }
}
void solveMaze(int arr[3][3],int row,int col,int i,int j,vector<vector<bool>>&visited,vector<string>&path,string output){
    // Base Case
    if(i == row-1 && j == col-1){
        // One Answer found
        path.push_back(output);
        return;
    }
    // Now just solve one case 
    // Down
    if(isSafe(i+1,j,row,col,arr,visited)){
        visited[i+1][j] = true;
        solveMaze(arr,row,col,i+1,j,visited,path,output + 'D');
        // Now backtracking bro
        visited[i+1][j] = false;
    }
    // Left
    if(isSafe(i,j-1,row,col,arr,visited)){
        visited[i][j-1] = true;
        solveMaze(arr,row,col,i,j-1,visited,path,output + 'L');
        // Now backtracking bro
        visited[i][j-1] = false;
    }
    // Right
    if(isSafe(i,j+1,row,col,arr,visited)){
        visited[i][j+1] = true;
        solveMaze(arr,row,col,i,j+1,visited,path,output + 'R');
        // Now backtracking bro
        visited[i][j+1] = false;
    }
    // Up
    if(isSafe(i-1,j,row,col,arr,visited)){
        visited[i-1][j] = true;
        solveMaze(arr,row,col,i-1,j,visited,path,output + 'U');
        // Now backtracking bro
        visited[i-1][j] = false;
    }
    
}
int main(){
    int maze[3][3] = {{1,0,0},{1,1,0},{1,1,1}};
    int row = 3;
    int col = 3;
    if(maze[0][0] == 0){
        cout<<"No Path exists";
        return 0;
    }
    // Creating a 2D array for visited array
    vector<vector<bool>>visited(row,vector<bool>(col,false));
    // Source value should be 1 as rat is standing on it only
    visited[0][0] = true;
    // Create string which stores all the paths
    vector<string>path;
    string output = "";
    solveMaze(maze,row,col,0,0,visited,path,output);
    
    for(auto i:path){
        cout<<i<<" ";
    }
    cout<<endl;

    if(path.size() == 0){ // Destination is only blocked
        cout<<"No path exists";
    }
    return 0;
}