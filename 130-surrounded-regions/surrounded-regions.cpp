class Solution {
public:
    int n;
    int m;

    vector<vector<int>>dir{{-1,0},{1,0},{0,-1},{0,1}};

    void dfs(vector<vector<int>>& isVis,vector<vector<char>>& board,int i,int j){
        isVis[i][j] = 1;

        for(auto di : dir){
            int newX = di[0] + i;
            int newY = di[1] + j;
            if(newX <n && newX>0 && newY >0 && newY<m && board[newX][newY] == 'O' 
            && !isVis[newX][newY]){
                dfs(isVis,board,newX,newY);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        n = board.size();
        m = board[0].size();
        vector<vector<int>>isVis(n+1,vector<int>(m+1,0));
        for(int i = 0;i<n;i++){
            if(!isVis[i][0] && board[i][0] == 'O'){
                dfs(isVis,board,i,0);
            }

            if(!isVis[i][m-1] && board[i][m-1]== 'O'){
                dfs(isVis,board,i,m-1);
            }
        }
        for(int j = 0;j<m;j++){
            if(!isVis[0][j] && board[0][j] == 'O'){
                dfs(isVis,board,0,j);
            }

            if(!isVis[n-1][j] && board[n-1][j] == 'O'){

                dfs(isVis,board,n-1,j);

            }
        }
        for(int i =0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(board[i][j] == 'O' && !isVis[i][j]){
                    board[i][j] = 'X';
                }
            }
        }
    }
};