class Solution {
public:
   int helper(int m,int n){
    if(m == 0 && n== 0) return 1;
    if(m<0 || n<0) return 0;
    int up = helper(m-1,n);
    int down = helper(m,n-1);

    return up+down;
   }
   int memo(int m,int n,vector<vector<int>>&ans){

        if(m== 0 && n==0) return 1;
        if(m<0 || n<0) return 0;
        if(ans[m][n] != -1) return ans[m][n];

        int up = helper(m-1,n);
        int down= helper(m,n-1);

        ans[m][n]= up+down;
        return ans[m][n];
   }
   int tabu(int m,int n){

    vector<vector<int>> ans(m, vector<int>(n,0));

    // base cases
    for(int i = 0; i < m; i++) ans[i][0] = 1;
    for(int j = 0; j < n; j++) ans[0][j] = 1;

    for(int i = 1; i < m; i++){
        for(int j = 1; j < n; j++){
            ans[i][j] = ans[i-1][j] + ans[i][j-1];
        }
    }

    return ans[m-1][n-1];
}
    int uniquePaths(int m, int n) {

        if(m==1 && n==1) return 1;

        // return helper(m-1,n-1);

        // vector<vector<int>>ans(m,vector<int>(n,-1));

        // return memo(m-1,n-1,ans);
        return tabu(m,n);
    }
};