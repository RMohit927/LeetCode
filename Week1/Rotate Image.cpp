/*
You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).
You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

Approach: Complexity - O(N^2) - 90 Clockwise
*/

/*
Example 1: 90 Degree Clockwise
  Input: matrix = [[1,2,3],      -> complement all edge element except diagonal element.
                   [4,5,6],      -> Replace column 1 with 3rd
                   [7,8,9]]
  Output: [[7,4,1],
           [8,5,2],
           [9,6,3]]
*/
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        for(int i=0; i<matrix.size(); i++)
        {
            for(int j=i; j<matrix.size(); j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for(int i=0; i<matrix.size(); i++)
        {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};

/*
Example 1: 180 Degree Clockwise
  Input: matrix = [[1,2,3],      -> Replace column 1 with 3rd using two pointer
                   [4,5,6],      -> Replace row 1 with 3rd using two pointer
                   [7,8,9]]
  Output: [[9,8,7],
           [6,5,4],
           [3,2,1]]
*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        for(int i=0; i<matrix.size(); i++)
        {
            reverse(matrix[i].begin(), matrix[i].end());
        }
        int r = matrix.size(), c = matrix[0].size();
        for (int i = 0; i < c; i++)
        {
            for (int j = 0, k = c - 1; j < k; j++, k--)
            { 
                swap(matrix[j][i], matrix[k][i]);
            }
        }
    }
};

/*
Example 1: 270 Degree Clockwise
  Input: matrix = [[1,2,3],      -> complement
                   [4,5,6],      -> Replace row 1 with 3rd using two pointer
                   [7,8,9]]
  Output: [[3,6,9],
           [2,5,8],
           [1,4,7]]
*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for(int i=0; i<matrix.size(); i++)
        {
            for(int j=i; j<matrix.size(); j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        int r = matrix.size(), c = matrix[0].size();
        for (int i = 0; i < c; i++)
        {
            for (int j = 0, k = c - 1; j < k; j++, k--)
            { 
                swap(matrix[j][i], matrix[k][i]);
            }
        }
    }
};
