class Solution {
public:
    int solveByRec(vector<int>& arr, map<pair<int,int>,int>& maxi, int s, int e){
        if(s >= e) return 0;

        int ans = INT_MAX;

        for(int i = s; i < e; i++){
            int leftProd = maxi[{s,i}];
            int rightPro = maxi[{i+1,e}];

            int product = leftProd * rightPro;

            ans = min(ans, product 
                + solveByRec(arr, maxi, s, i) 
                + solveByRec(arr, maxi, i+1, e));
        }

        return ans;
    }
    int solveByMemo(vector<int>& arr,map<pair<int,int>,int>& maxi,int s,int e , vector<vector<int>>&dp){
        if(s>=e) return 0;
        if(dp[s][e] != -1) return dp[s][e];

        int ans = INT_MAX;
        for(int i = s;i<e;i++){
            int leftProd = maxi[{s,i}];
            int rightPro = maxi[{i+1,e}];
            int prod = leftProd * rightPro;

            ans = min(ans,prod+ solveByMemo(arr,maxi,s,i,dp) + solveByMemo(arr,maxi,i+1,e,dp));

            dp[s][e]= ans;
        }

        return dp[s][e];
    }
    int mctFromLeafValues(vector<int>& arr) {
        map<pair<int,int>,int> maxi;

        int n = arr.size();

        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                if(i == j){
                    maxi[{i,j}] = arr[j];
                }
                else{
                    maxi[{i,j}] = max(arr[j], maxi[{i,j-1}]);
                }
            }
        }

        // int ans = solveByRec(arr, maxi, 0, n-1);
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        int ans = solveByMemo(arr,maxi,0,n-1,dp);

        return ans;
    }
};