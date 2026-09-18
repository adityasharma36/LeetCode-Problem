class Solution {
public:
    int solveByRec(vector<int>&days,vector<int>&costs,int i){
        if(i>=days.size()){
            return 0;
        }
        int day1 = costs[0] + solveByRec(days,costs,i+1);

        int presentDay = days[i] + 7 -1;
        int j = i;
        while(j<days.size() && days[j] <= presentDay){
            j++;
        }
        int day7 = costs[1] + solveByRec(days,costs,j);

         j = i;
        presentDay = days[i] + 30 -1;

        while(j<days.size() && days[j] <= presentDay){
            j++;
        }
        int day30 = costs[2] + solveByRec(days,costs,j);

        int ans= min({day1,day7,day30});
        return ans;

    }
    int solveByMemo(vector<int>& days,vector<int>& costs,vector<int>&dp,int i){
        if(i>=days.size()) return 0;
        if(dp[i] != -1) return dp[i];

        int day1 = costs[0] + solveByMemo(days,costs,dp,i+1);

        int presentDays = 7 + days[i] -1;
        int j = i;
        while(j<days.size() && days[j] <= presentDays){
            j++;
        }
        int day7 = costs[1] + solveByMemo(days,costs,dp,j);
        j = i;
        presentDays = days[i] + 30 -1;
        while(j<days.size() && days[j] <= presentDays){
            j++;
        }
        int day30 = costs[2] + solveByMemo(days,costs,dp,j);

        return dp[i] = min({day1,day7,day30});
    }
    int solveByTabu(vector<int>& days,vector<int>& costs){
        int n = days.size();
        vector<int>dp(n+1,0);

        for(int i = n-1;i>=0;i--){
            int day1 = costs[0] + dp[i+1];

            int presentDays = 7 + days[i] -1;
            int j = i;
            while(j<days.size() && days[j] <= presentDays){
                j++;
            }
            int day7 = costs[1] + dp[j];
            j = i;
            presentDays = days[i] + 30 -1;
            while(j<days.size() && days[j] <= presentDays){
                j++;
            }
            int day30 = costs[2] + dp[j];

             dp[i] = min({day1,day7,day30});
        }
        return dp[0];
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        // int ans = solveByRec(days,costs,0);
        // int n = days.size();
        // vector<int>dp(n+1,-1);
        // int ans = solveByMemo(days,costs,dp,0);
        int ans = solveByTabu(days,costs);
        return ans;

    }
};