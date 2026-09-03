class Solution {
public:
    bool isFollow(vector<int>&prev,vector<int>&curr){
        if(prev[0]<=curr[0] && prev[1] <= curr[1] && prev[2] <= curr[2]){
            return true;
        }
        return false;
    }
    int solveByRec(vector<vector<int>>& cuboids,int prev,int curr){
        if(curr>=cuboids.size()) return 0;

        int include = 0;
        
        if(prev == -1 || isFollow(cuboids[prev],cuboids[curr])){
            include = cuboids[curr][2] + solveByRec(cuboids,curr , curr+1);
        }
        int excl = solveByRec(cuboids,prev,curr+1);
        return max(include,excl);
    }
    int solveByMemo(vector<vector<int>>& cuboids,int prev,int curr,vector<vector<int>>&dp){
        if(curr>=cuboids.size()) return 0;
        if(dp[prev+1][curr] != -1) return dp[prev+1][curr];
        int incl = 0;
        if(prev == -1  || isFollow(cuboids[prev], cuboids[curr])){
            incl = cuboids[curr][2] + solveByMemo(cuboids,curr,curr+1,dp);
        }
        int excl = solveByMemo(cuboids,prev,curr+1,dp);
        return dp[prev+1][curr] = max(incl,excl);
    }
    int solveByTabu(vector<vector<int>>& cuboids){
        int n = cuboids.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int curr = n-1;curr>=0;curr--){
            for(int prev = curr-1;prev>=-1;prev--){
                int incl = 0;
                if(prev == -1  || isFollow(cuboids[prev], cuboids[curr])){
                    incl = cuboids[curr][2] + dp[curr+1][curr+1];
                }
                int excl = dp[curr+1][prev+1];
                dp[curr][prev+1] = max(incl,excl);
                }
            }
        return dp[0][0];
    }
    int maxHeight(vector<vector<int>>& cuboids) {
        for(auto &cuboid : cuboids){
            sort(begin(cuboid),end(cuboid));
        }
        sort(begin(cuboids),end(cuboids));

        // int ans = solveByRec(cuboids,-1,0);
        int n = cuboids.size();
        // vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        // int ans = solveByMemo(cuboids,-1,0,dp);
        int ans = solveByTabu(cuboids);
        return ans;
    }
};