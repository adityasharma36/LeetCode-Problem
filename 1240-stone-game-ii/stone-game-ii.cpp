class Solution {
public:
    int solveByRec(vector<int>&piles,int i,int M,bool Alice){
        if(i == piles.size()) return 0;

        int ans = Alice ? INT_MIN:INT_MAX;
        int total= 0;

        for(int x = 1;x<=2*M;x++){
            if(i+x-1 >=piles.size()) break;
            total+=piles[i+x-1];
            if(Alice){
                ans = max(ans,total+solveByRec(piles,i+x, max(M,x),!Alice));
            }else{
                ans = min(ans,solveByRec(piles,i+x,max(M,x),!Alice));
            }
        }
        return ans;
    }
    int solveByMemo(vector<int>& piles,int i,int M,bool alice,vector<vector<vector<int>>>&dp){
        if(i>= piles.size()) return 0;
        if(dp[i][M][alice]!= -1) return dp[i][M][alice];
         int ans = alice ? INT_MIN:INT_MAX;
        int total= 0;

        for(int x = 1;x<=2*M;x++){
            if(i+x-1 >=piles.size()) break;
            total+=piles[i+x-1];
            if(alice){
                ans = max(ans,total+solveByMemo(piles,i+x, max(M,x),!alice,dp));
            }else{
                ans = min(ans,solveByMemo(piles,i+x,max(M,x),!alice,dp));
            }
        }
        return dp[i][M][alice]= ans;
    }
    int solveByTabu(vector<int>& piles){
        int n = piles.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(n+1,vector<int>(2,0)));
        for(int i = n-1;i>=0;i--){
            for(int M = n-1;M>=1;M--){
                for(int alice = 0;alice<=1;alice++){
                        int ans = alice ? INT_MIN:INT_MAX;
                        int total= 0;

                        for(int x = 1;x<=2*M;x++){
                            if(i+x-1 >=piles.size()) break;
                            total+=piles[i+x-1];
                        if(alice){
                            ans = max(ans,total+dp[i+x][max(M,x)][!alice]);
                        }else{
                            ans = min(ans,dp[i+x][max(M,x)][!alice]);
                        }           
                    }
                    dp[i][M][alice]= ans;
                }
            }
        }
        return dp[0][1][1];
    }
    int stoneGameII(vector<int>& piles) {
        // int ans = solveByRec(piles,0,1,true);
        int n = piles.size();
        if(n == 1) return piles[0];
        // vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(n+1,vector<int>(2,-1)));
        // int ans = solveByMemo(piles,0,1,true,dp);
        int ans = solveByTabu(piles);
        return ans;
    }
};