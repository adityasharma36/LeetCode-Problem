class Solution {
public:
    unordered_map<int,bool>rowCheck;
    unordered_map<int,bool> upperDiagonalCheck;
    unordered_map<int,bool> lowerDiagonalCheck;
    void storeValue(vector<vector<string>>& ans,vector<vector<char>>& board,int n){
        vector<string> check;
        for(int i = 0;i<n;i++){
            string output = "";
            for(int j = 0;j<n;j++){
                output.push_back(board[i][j]);
            }
            check.push_back(output);
        }
        ans.push_back(check);
    }
    bool isPossible(vector<vector<char>>board,int col,int row){
        if(rowCheck[row]== true){
            return false;
        }
        if(lowerDiagonalCheck[col+row]==true){
            return false;
        }
        if(upperDiagonalCheck[row-col]==true){
            return false;
        }
        return true;
    }
    void solve(vector<vector<string>>& ans,vector<vector<char>>& board,int col,int n){
        if(col>=n){
            // all queen is palced we have to arrage it
            // store in ans array
            storeValue(ans,board,n);
            return;
        }
         for(int row = 0;row<n;row++){
            if(isPossible(board , col , row)){
                board[row][col]= 'Q';
                rowCheck[row] = true;
                upperDiagonalCheck[row-col] = true;
                lowerDiagonalCheck[row+col]= true;
                solve(ans,board,col+1,n);
                board[row][col]= '.';
                rowCheck[row] = false;
                upperDiagonalCheck[row-col] = false;
                lowerDiagonalCheck[row+col]= false;
            }
         }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<vector<char>> board(n,vector<char>(n,'.'));
        int col = 0;
        solve(ans,board,col,n);
        return ans;
    }
};