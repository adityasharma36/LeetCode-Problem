class Solution {
public:
    vector<vector<int>>directions{{0,-1},{0,1},{-1,0},{1,0}};
    int dfs(vector<vector<char>>& maze,vector<int>& entrance){

        queue<pair<int,int>>q;
     
        q.push({entrance[0],entrance[1]});

        maze[entrance[0]][entrance[1]] = '+';

        int level = 0;
        int n = maze.size();
        int m = maze[0].size();
        while(!q.empty()){
            int N = q.size();
           while(N--){
            auto front = q.front();
            int i = front.first;
            int j = front.second;
            q.pop();
             if((i ==0 || j == 0 || i ==n-1 || j ==m-1 ) && !(i == entrance[0] && j == entrance[1])){
                return level;
                }
            for(auto &dir : directions){
                    int x = i+ dir[0];
                    int y = j+ dir[1];

                    if(x>=0 && y>=0 && x<n && y<m && maze[x][y] != '+' ){
                        maze[x][y] = '+';
                        q.push({x,y});
                    }
                }
           }
           level++;
        }
        return -1;
    }
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int exit = dfs(maze,entrance);
        return exit;
    }
};