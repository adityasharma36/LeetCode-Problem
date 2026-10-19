class Solution {
public:
    typedef pair<int,int>p;
    vector<vector<int>>dir{{-1,0},{0,-1},{1,0},{0,1}};
    int rottenOranges(vector<vector<int>>&grid){
        queue<p>q;
        int m = grid.size();
        int n = grid[0].size();
        int oranges = 0;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
                else if(grid[i][j] == 1){
                    oranges++;
                }
            }
        }
        if(oranges ==0) return 0;

        int cnt = 0;
        while(!q.empty()){
            int N = q.size();
            if(oranges == 0) return cnt;
            while(N--){
                auto front = q.front();
                int i = front.first;
                int j = front.second;
                q.pop();
                for(auto di : dir){
                    int new_i = i+ di[0];
                    int new_y = j+ di[1];
                    if(new_i >=0 && new_i<m && new_y >=0 && new_y<n && grid[new_i][new_y] == 1){
                        q.push({new_i,new_y});
                        grid[new_i][new_y]= 2;
                        oranges--;
                    }
                }
            }
            cnt++;
        }

        return oranges == 0 ? cnt : -1;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        return rottenOranges(grid);
    }
};