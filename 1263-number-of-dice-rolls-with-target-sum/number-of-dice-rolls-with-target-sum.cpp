class Solution {
public:
    int Modulo = 1e9+7;

    int recursiveApp(int n ,int k ,int target ){

    if(n == 0 && target == 0) return 1;

        if(n!= 0 && target == 0) return 0;

        if(n== 0 && target!= 0) return 0;
        if(target<0) return 0;

        int find = 0;
        for(int i = 0;i<=k;i++){
            find = (find+ numRollsToTarget(n-1,k,target-i))% Modulo;
        }

        return find%Modulo;
        
    }
    long long solveByMemo(int n,int k ,int target,vector<vector<int>>& ans){

         if(n == 0 && target == 0) return 1;

        if(n!= 0 && target == 0) return 0;

        if(n== 0 && target!= 0) return 0;

        if(target<0) return 0;

        if(ans[n][target] != -1) return ans[n][target];

        long long find = 0;

        for(int i = 1;i<=k;i++){

            find = (find+ solveByMemo(n-1,k,target-i,ans))% Modulo;

        }

        ans[n][target] = find%Modulo;

        return ans[n][target];
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>>ans(n+1,vector<int>(target+1,-1));
        return (int)solveByMemo(n,k,target,ans);
    }
};