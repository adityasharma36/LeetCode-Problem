class Solution {
public:
    int m;
    int n;
    void dfs(vector<vector<int>>& grid,int i,int j){
        if(i<0 || j<0 || i>=m || j>=n || grid[i][j] ==0 ){
            return;
        }
        if(grid[i][j] != 1){
            return;
        }
        grid[i][j]=0;
        dfs(grid,i,j+1);
        dfs(grid,i,j-1);
        dfs(grid,i+1,j);
        dfs(grid,i-1,j);
    }
    int solveByDFS(vector<vector<int>>& grid){
        m  = grid.size() ;
        n = grid[0].size();
        int ans = 0;
        for(int i = 0;i<m;i++){
            if(grid[i][0] ==1){
                dfs(grid,i,0);
            }
            if(grid[i][n-1] == 1){
                dfs(grid,i,n-1);
            }
        }
        for(int j = 0;j<n;j++){
            if(grid[0][j] == 1){
                dfs(grid,0,j);
            }
            if(grid[m-1][j] == 1){
                dfs(grid,m-1,j);
            }
        }
        for(auto i: grid){
            for(auto j: i){
                if(j == 1){
                    ans++;
                }
            }
        }
        return ans;
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int enclaves = solveByDFS(grid);
        return enclaves;
    }
};