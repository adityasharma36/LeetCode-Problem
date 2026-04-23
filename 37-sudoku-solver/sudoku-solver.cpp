class Solution {
public:
bool isSafe(vector<vector<char>>&board,int row,int col , char digit){

    int n = board.size();
    // row check
    for(int i = 0;i<n;i++){
        if(board[row][i]== digit){
            return false;
        }
    }
    // col check
    for(int i = 0;i<n;i++){

        if(board[i][col]==digit){

            return false;

        }
    }
    // 3*3 row*col check;

    for(int i = 0;i<n;i++){
        if(board[3*(row/3)+i/3][3*(col/3)+i%3] == digit){
            return false;
        }
    }
    return true;
}
    bool solve(vector<vector<char>>&board){

        // sabse phele find karo usnke place mein '.' hai
        for(int i = 0;i<board.size();i++){
            for(int j = 0;j<board[0].size();j++){

                if(board[i][j]=='.'){

                    for(int k = '1';k<='9';k++){

                        if(isSafe(board,i,j,k)){

                            board[i][j]=k;

                            bool aageKaSol = solve(board);

                            if(aageKaSol){

                                return true;

                            }else{

                                board[i][j]= '.';
                            }

                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};