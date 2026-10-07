class Solution {
public:
    int m;
    int n;
    void dfs(vector<vector<char>>& grid,int i,int j){
        if(i<0 || j>=m || i>=n || j<0 || grid[i][j] == '0'){
            return;
        }

        if(grid[i][j] != '1'){
            return;
        }

        grid[i][j]= '$';
        dfs(grid,i+1,j);
        dfs(grid,i-1,j);
        dfs(grid,i,j+1);
        dfs(grid,i,j-1);
    }
    int solveByDFS(vector<vector<char>>&grid){
         n = grid.size();
         m= grid[0].size();
        int island = 0;
        for(int i  = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j]== '1'){
                    dfs(grid,i,j);
                    island++;
                }
            }
        }
        return island;
    }
    int numIslands(vector<vector<char>>& grid) {
        int island = solveByDFS(grid);
        return island;
    }
};