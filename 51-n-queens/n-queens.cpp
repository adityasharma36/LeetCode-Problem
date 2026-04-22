class Solution {
public:
    unordered_map<int,bool> rowCheck;
    unordered_map<int,bool> lowerDiagonalCheck;
    unordered_map<int,bool> upperDiagonalCheck;

    bool isPossible(int row, int col) {
        if(rowCheck[row]) return false;
        if(lowerDiagonalCheck[row + col]) return false;
        if(upperDiagonalCheck[row - col]) return false;
        return true;
    }

    void storeAnswer(vector<vector<string>>& ans, vector<vector<char>>& board, int n) {
        vector<string> temp;
        for(int i = 0; i < n; i++) {
            string row = "";
            for(int j = 0; j < n; j++) {
                row += board[i][j];
            }
            temp.push_back(row);
        }
        ans.push_back(temp);
    }

    void solve(int n, vector<vector<string>>& ans, vector<vector<char>>& board, int col) {
        if(col >= n) {
            storeAnswer(ans, board, n);
            return;
        }

        for(int row = 0; row < n; row++) {
            if(isPossible(row, col)) {

                board[row][col] = 'Q';
                rowCheck[row] = true;
                lowerDiagonalCheck[row + col] = true;
                upperDiagonalCheck[row - col] = true;

                solve(n, ans, board, col + 1);

                board[row][col] = '.';
                rowCheck[row] = false;
                lowerDiagonalCheck[row + col] = false;
                upperDiagonalCheck[row - col] = false;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<vector<char>> board(n, vector<char>(n, '.'));

        solve(n, ans, board, 0);
        return ans;
    }
};