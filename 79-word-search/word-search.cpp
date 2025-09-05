class Solution {
public:

    bool checking(vector<vector<char>>& board, string word,int i,int j ,int k){
        if(k == word.size()) return true;

        if(i<0 || i>=board.size() || j<0 || j>=board[0].size() || board[i][j] != word[k]) return false;

        board[i][j]= '0';

        bool status = checking(board,word,i+1,j,k+1) ||
                        checking(board,word,i,j+1,k+1) ||
                        checking(board,word,i-1,j,k+1)||
                        checking(board,word,i,j-1,k+1);

        board[i][j]= word[k];

        return status;
    }
    bool exist(vector<vector<char>>& board, string word) {
        
        if(word == "") return false;

        for(int i = 0;i<board.size();i++){
            for(int j = 0;j<board[0].size();j++){
                if(board[i][j] == word[0] && checking(board,word,i,j,0)){
                    return true;
                }
            }
        }

        return false;
    }
};