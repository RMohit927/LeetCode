/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
Now consider if some obstacles are added to the grids. How many unique paths would there be?
An obstacle and space is marked as 1 and 0 respectively in the grid.

Example 1:
  Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
  Output: 2
  Explanation: There is one obstacle in the middle of the 3x3 grid above.
    There are two ways to reach the bottom-right corner:
    1. Right -> Right -> Down -> Down
    2. Down -> Down -> Right -> Right
*/

/* Approach: Complexity - O(R*C) - Dynamic Programming*/

class Solution {
public:
    int dp[102][102]; 
    
    int solve (vector<vector<int>> &m, int Y, int X, int y, int x) {  
        if (x > X || y > Y || m[y][x]) { 
            return 0;
        }  
        else if (x == X && y == Y) { 
            return 1;
        } 
        else if (dp[y][x] != -1) { 
            return dp[y][x]; 
        } 
        return  dp[y][x] = solve (m, Y, X, y+1, x) + solve (m, Y, X, y, x+1);
    } 
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        memset(dp, -1, sizeof dp);
        return solve (obstacleGrid, obstacleGrid.size()-1, obstacleGrid[0].size()-1, 0 , 0);
    }
};
/*
0,0,0,0
0,1,0,0
0,0,1,0
0,0,0,0
*/

