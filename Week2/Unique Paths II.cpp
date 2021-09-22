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

/* Approach: Complexity - O(R*C) - Dynamic Programming - Memoization*/

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

/* Approach: Complexity - O(N*M) - DP - Tabular Method */

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n = grid.size() , m = grid[0].size();
        
		//if the source or destination contains an obstacle , then answer is 0.
        if(grid[n-1][m-1] == 1 or grid[0][0] == 1) return 0;
        
        int dp[n+1][m+1];
		//initialise dp table with 0.
        memset(dp,0,sizeof(dp));
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
				//1 way from source to source is to stay (we have checked earlier for obstacle at source)
                if(i == 1 and j == 1) dp[i][j] = 1;
				
				//if curr sqaure doesn't contain obstacle
                else if(grid[i-1][j-1] != 1)
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
				
				//if the curr square conatins obstacle
                else dp[i][j] = 0;
            }
        }
        
        return dp[n][m];
    }
};
