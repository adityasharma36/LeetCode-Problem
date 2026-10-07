class Solution {
public:
    int m;
    int n;
    void dfs(vector<vector<int>>& image,vector<vector<int>>&ans,int sr,int sc,int color,int curr){
        if(sr<0 || sr>=m || sc <0 || sc >=n || image[sr][sc] != curr){
            return;
        }
      
        ans[sr][sc] = color;
        image[sr][sc]= -1;
        dfs(image,ans,sr-1,sc,color,curr);
        dfs(image,ans,sr+1,sc,color,curr);
        dfs(image,ans,sr,sc-1,color,curr);
        dfs(image,ans,sr,sc+1,color,curr);


    }
    vector<vector<int>> solveByDFS(vector<vector<int>>& image,int sr,int sc,int color){
        m = image.size();
        n = image[0].size();
        vector<vector<int>>ans(image.begin(),image.end());
        int curr = image[sr][sc];
        if(curr == color){
            return ans;
        }
        dfs(image,ans,sr,sc,color,curr);
        return ans;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> fill = solveByDFS(image,sr,sc,color);
        return fill;
    }
};