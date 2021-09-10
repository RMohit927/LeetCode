/*
Write a program to solve a Sudoku puzzle by filling the empty cells.
A sudoku solution must satisfy all of the following rules:

  Each of the digits 1-9 must occur exactly once in each row.
  Each of the digits 1-9 must occur exactly once in each column.
  Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
  The '.' character indicates empty cells.

Input: board = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
Output: [["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]]

*/

/* Approach: Complexity - O(N^2) - DFS & Backtracking Algorithm */

const char DIGITS[9] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };

class Solution {
public:
    /* Initialize rows, cols, and boxes. 
    rows[5], for instance, is a bitvector telling which digits are in row 5 (0-indexed). 
    boxes has two indices, both from 0 to 2 inclusive. */
    int rows[9] = {0};
    int cols[9] = {0};
    int boxes[3][3] = {0}; 
    char myBoard[9][9];
    
    /* Copy inputted board to myBoard */
    void copyBoard(vector<vector<char>>& board) {
        for (int i=0;i<9;i++) {
            for (int j=0;j<9;j++) {
                myBoard[i][j] = board[i][j];
            }
        }
    }
    
    /* Function to read board, i.e. set rows, cols, and boxes to what they should be. */
    void readBoard() {
        for (int i=0;i<9;i++) {
            for (int j=0;j<9;j++) {
                if (myBoard[i][j]!='.') {
                    int digit = myBoard[i][j] - '1';
                    int binary = (1<<digit);
                    rows[i] |= binary;
                    cols[j] |= binary;
                    boxes[i/3][j/3] |= binary;
                }
            }
        }
    }
    
    /* Function that checks if we can write digit in square, even if square currently not empty. */
    bool validToWrite(int i, int j, char charDigit) {
        int binary = (1<<(charDigit - '1'));
        return ((rows[i]&binary)==0) && ((cols[j]&binary)==0) && ((boxes[i/3][j/3]&binary)==0);
    }
    
    /* Function to write digit to square (i,j) and change rows, cols, and boxes appropriately. */
    void writeToSquare(int i, int j, char charDigit) {
        myBoard[i][j] = charDigit;
        int binary = (1<<(charDigit - '1'));
        rows[i] |= binary;
        cols[j] |= binary;
        boxes[i/3][j/3] |= binary;
    }
    
    /* Function to backtrack on the digit we just wrote in square (i,j). */
    void backtrack(int i, int j) {
        int binary = (1<<(myBoard[i][j] - '1'));
        rows[i] ^= binary;
        cols[j] ^= binary;
        boxes[i/3][j/3] ^= binary;
        myBoard[i][j] = '.';
    }
    
    /* DFS to solve the sudoku. */
    bool dfs(int i, int j) {
        if (j==9) return true;
        if (i==9) return dfs(0, j+1);
        if (myBoard[i][j] != '.') return dfs(i+1,j);
        for (int d=0; d<9; d++) {
            char charDigit = DIGITS[d];
            if (!validToWrite(i,j,charDigit)) continue;
            writeToSquare(i,j,charDigit);
            if (dfs(i+1,j)) return true;
            backtrack(i,j);
        }
        return false;
    }
    
    /* Assumes unique solution. */
    void solveSudoku(vector<vector<char>>& board) {
        copyBoard(board);
        readBoard();
        dfs(0,0);
        for (int i=0;i<9;i++) {
            for (int j=0;j<9;j++) {
                board[i][j] = myBoard[i][j];
            }
        }
    }
};
