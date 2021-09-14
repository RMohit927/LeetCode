/*
The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.
Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

Example 1:
  Input: n = 4
  Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
  Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above
*/

/* Approach: Complexity - O(N^N) - BackTracking Algorithm */

class Solution {
public:
    vector<vector<string>> res;
    bool isSafe(vector<string> &board, int row, int col){
        int n = board.size();
        // 1. checking if there's any queen placed at the same row
        for(int i = col; i >= 0; --i)
            if(board[row][i] == 'Q')
                return false;

        // 2. check if there is any other queen placed at upper left diagonal
        for(int i = row, j = col; i >= 0 && j >= 0; --i, --j)
            if(board[i][j] == 'Q')
                return false;

        // 3. checking if there's any placed at the bottom left diagonal
        for(int i = row, j = col; i < n && j >= 0; ++i, --j)
            if(board[i][j] == 'Q')
                return false;

        return true;
    }
    void dfs(vector<string> &board, int col){   
        int n = board.size();
        if(col >= n)
            res.push_back(board);

        for(int row = 0; row < n; ++row){       // traversing in row while putting a queen at single place(col).
            if(isSafe(board, row, col)){
                board[row][col] = 'Q';          // Placing Queen if the cell pass the safty checks
                dfs(board, col + 1);            // recur for next column 
                board[row][col] = '.';          // BACKTRACK, to check other possible solutions
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
       vector<string> board(n, string(n, '.'));
       dfs(board, 0);                            // passing starting 0th column
       return res;
    }
};
