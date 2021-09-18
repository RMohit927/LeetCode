/*
Given an m x n matrix, return all elements of the matrix in spiral order.

Example 1:
  Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
  Output: [1,2,3,6,9,8,7,4,5]
*/

/* Approach: Complexity - O(N) - Clockwise Direction */

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> v;
        int n = matrix.size(), m = matrix[0].size();
        int top=0,bottom=n-1,left=0,right=m-1;
        while(top<=bottom && left<=right && v.size()<n*m){
            for(int i=left;i<=right;i++){
                v.push_back(matrix[top][i]);
            }
            top++;
            for(int i=top;i<=bottom;i++){
                v.push_back(matrix[i][right]);
            }
            right--;
            for(int i=right;top<=bottom && i>=left;i--){
                v.push_back(matrix[bottom][i]);
            }
            bottom--;
            for(int i=bottom;left<=right && i>=top;i--){
                v.push_back(matrix[i][left]);
            }
            left++;
        }
        return v;
    }
};

/* Approach: Complexity - O(N) - Anticlockwise Direction */

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> v;
        int n = matrix.size(), m = matrix[0].size();
        int top=0,bottom=n-1,left=0,right=m-1;
        while(top<=bottom && left<=right && v.size()<n*m){
            for(int i=right; i>=left; i--){
                v.push_back(matrix[top][i]);
            }
            top++;
            for(int i=top; i<=bottom; i++){
                v.push_back(matrix[i][left]);
            }
            left++;
            for(int i=left; i<=right; i++){
                v.push_back(matrix[bottom][i]);
            }
            bottom--;
            for(int i=bottom; i>= top; i--){
                v.push_back(matrix[i][right]);
            }
            right--;
            
        }
        return v;
    }
};
