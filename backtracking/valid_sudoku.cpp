/*
                                                          36. Valid Sudoku

            Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

            1) Each row must contain the digits 1-9 without repetition.
            2) Each column must contain the digits 1-9 without repetition.
            3) Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.

            Note:
            -> A Sudoku board (partially filled) could be valid but is not necessarily solvable.
            -> Only the filled cells need to be validated according to the mentioned rules.
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

Input: board = 
[["8","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: false

*/
// Idea: check if the particular cell number has repeated in any of its column ,row and 3*3 box(in which this (i,j) cell resides)

class Solution {
public:
    bool valid(vector<vector<char>>& board,int row,int col,char ch)
    {
        for(int i=0;i<9;i++)
        {
            if(i!=col && board[row][i] == board[row][col]) // check if the number is appeared in the column
                 return false;
            if(i!=row && board[i][col] == board[row][col]) // check if the number is appeared in the row.
                 return false;
            int ii = 3*(row/3)+i/3;
            int jj = 3*(col/3)+i%3;
            if(ii==row && jj==col)continue;
            if(board[ii][jj]==board[row][col])  // check if the number is appeared in 3*3 box in which current cell resides.
                 return false;
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board)   
    {
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j]!='.' && !valid(board,i,j,board[i][j])) 
                    return false;
            } 
        }
        return true;
    }
};