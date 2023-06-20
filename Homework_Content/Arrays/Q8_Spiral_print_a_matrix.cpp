// https://leetcode.com/problems/spiral-matrix/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>ans;
        // Fetch number of rows
        int m = matrix.size();
        // Fetch number of columns
        int n = matrix[0].size();
        // Calculate total number of elements which will be a terminating condition
        int totalElements = m*n;
        int startingRow = 0;
        int endingCol = n - 1;
        int endingRow = m - 1;
        int startingCol = 0;

        int count = 0;
        // Run a loop until we have not printed all the elements
        while(count < totalElements){
            // Print starting row
            for(int i = startingCol;i<=endingCol && count<totalElements;i++){
                ans.push_back(matrix[startingRow][i]);
                count++;
            }
            // Handling duplicate case
            startingRow++;
            // Print ending col
            for(int i = startingRow;i<=endingRow && count<totalElements;i++){
                ans.push_back(matrix[i][endingCol]);
                count++;
            }
            // Handling duplicate case
            endingCol--;
            // Print ending row
            for(int i = endingCol;i>=startingCol && count<totalElements;i--){
                ans.push_back(matrix[endingRow][i]);
                count++;
            }
            // Handling duplicate case
            endingRow--;
            // Print starting col
            for(int i = endingRow;i>=startingRow && count<totalElements;i--){
                ans.push_back(matrix[i][startingCol]);
                count++;
            }
            // Handling duplicate case
            startingCol++;
        }
        return ans;
    }
};