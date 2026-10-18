class Solution {
public:
    int n ;
    int m ;
    void dfs(vector<vector<char>>& grid,int i,int j){
        if(i>=n || i<0 || j>=m || j<0 || grid[i][j] == '0' ){
            return;
        }
        if(grid[i][j] != '1') return;
        grid[i][j] = '&';
        dfs(grid,i,j+1);
        dfs(grid,i,j-1);
        dfs(grid,i+1,j);
        dfs(grid,i-1,j);
    }
    int numIslands(vector<vector<char>>& grid) {
      
        int count = 0;
        n = grid.size();
        m = grid[0].size();

        for(int i = 0;i<n;i++){
           for(int j = 0;j<m;j++){
            if(grid[i][j] == '1'){
                count++;
                dfs(grid,i,j);
            }
           }
        }
        return count;
    }
};