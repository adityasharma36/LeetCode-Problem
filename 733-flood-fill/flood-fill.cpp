class Solution {
public:
    int n;
    int m ;
    void dfs(vector<vector<int>>& image,int sr,int sc,int color,int curr){
        if(sr>=n || sr<0 || sc >=m || sc<0 || image[sr][sc] != curr){
            return;
        }
   

        image[sr][sc]= color;

        dfs(image,sr-1,sc,color,curr);
        dfs(image,sr+1,sc,color,curr);
        dfs(image,sr,sc+1,color,curr);
        dfs(image,sr,sc-1,color,curr);

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        n = image.size();
        m = image[0].size();
        int curr = image[sr][sc];
        if( curr == color) return image;
        
        dfs(image,sr,sc,color,curr);
        return image;
    }
};