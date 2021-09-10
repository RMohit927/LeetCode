/*
Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:
  Each row must contain the digits 1-9 without repetition.
  Each column must contain the digits 1-9 without repetition.
  Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
Note:
  A Sudoku board (partially filled) could be valid but is not necessarily solvable.
  Only the filled cells need to be validated according to the mentioned rules.

Example 1:
  Input: board = 
  [["5","3",".",".","7",".",".",".","."]
  ,["6",".",".","1","9","5",".",".","."]
  ,[".","9","8",".",".",".",".","6","."]
  ,["8",".",".",".","6",".",".",".","3"]
  ,["4",".",".","8",".","3",".",".","1"]
  ,["7",".",".",".","2",".",".",".","6"]
  ,[".","6",".",".",".",".","2","8","."]
  ,[".",".",".","4","1","9",".",".","5"]
  ,[".",".",".",".","8",".",".","7","9"]]
  Output: true
*/

/* Approach: Complexity - O(N^2) - 15% Faster */

class Solution {
public:
    bool isBoxesValid(vector<vector<char>>& board){
        int frec[9];
        for(int i = 0;i < 9; i += 3){
            for(int j = 0;j < 9; j += 3){
                for(int w = 0;w < 9;w++) 
                    frec[w] = 0;
                for(int row = i; row < i+3; row ++)
                for(int col = j; col < j+3; col ++)
                    if( board[row][col] != '.' && frec[board[row][col] - '1']++) return false;
            }
        }
        return true;
    }
    bool isRowesValid(vector<vector<char>>& board){     //check rows
        int frec[9];

        for(int row = 0;row < 9; row++){
            for(int w = 0;w < 9;w++)
                frec[w] = 0;
            for(int col = 0;col < 9; col++)
                if( board[row][col] != '.' && frec[board[row][col] - '1']++) return false;
        } 
        return true;
    }
    bool isColumnesValid(vector<vector<char>>& board){   //check columnes
        int frec[9];
        for(int col = 0;col < 9; col++){
            for(int w = 0;w < 9;w++) frec[w] = 0;
            for(int row = 0;row < 9; row++)
                if( board[row][col] != '.' && frec[board[row][col] - '1']++) return false;
        }
        return true;
    }
  
    bool isValidSudoku(vector<vector<char>>& board) {
        return isRowesValid(board) && isColumnesValid(board) && isBoxesValid(board);
    }
};

/* Approach: Complexity - O(N^2) - 74% Faster*/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<string,bool> hashmap;
        for(int row = 0;row < 9;row++)
        {
            for(int column = 0;column < 9;column++)
            {            
                if(board[row][column] != '.')
                {
                    // Forming String sequences of each value in the array
                    string Row = "R" + to_string(row) + to_string(board[row][column]);
                    string Column = "C" + to_string(column) + to_string(board[row][column]);
                    int boxNumber = (row/3) * 3 + (column/3);
                    string Box = "B" + to_string(boxNumber) + to_string(board[row][column]);
                    
                    // If any of the string already exists the sudoku board is not valid
                    if(!hashmap.insert({ Row, true}).second || 
                       !hashmap.insert({ Column, true}).second || 
                       !hashmap.insert({ Box,true}).second)    
                        return false;
                }
            }
        }
        return true;
    }
};
