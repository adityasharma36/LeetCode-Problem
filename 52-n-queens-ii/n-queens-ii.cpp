class Solution {
public:
    unordered_map<int,bool> rowCheck;
    unordered_map<int,bool> lowerDiagonalCheck;
    unordered_map<int,bool> upperDiagonalCheck;

    int count = 0;

    bool isPossible(int row, int col) {
        if(rowCheck[row]) return false;
        if(lowerDiagonalCheck[row + col]) return false;
        if(upperDiagonalCheck[row - col]) return false;
        return true;
    }

    void solve(int n, int col) {
        if(col >= n) {
            count++;
            return;
        }

        for(int row = 0; row < n; row++) {
            if(isPossible(row, col)) {

                rowCheck[row] = true;
                lowerDiagonalCheck[row + col] = true;
                upperDiagonalCheck[row - col] = true;

                solve(n, col + 1);

                rowCheck[row] = false;
                lowerDiagonalCheck[row + col] = false;
                upperDiagonalCheck[row - col] = false;
            }
        }
    }

    int totalNQueens(int n) {
        solve(n, 0);
        return count;
    }
};