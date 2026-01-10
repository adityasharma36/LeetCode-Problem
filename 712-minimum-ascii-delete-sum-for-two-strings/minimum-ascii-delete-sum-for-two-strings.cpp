class Solution {
public:

    int solveByMemo(string& s1,string& s2 , int i ,int j ,vector<vector<int>>&dp){


        if(dp[i][j]!=-1){

            return dp[i][j];

        }
         int minAns = 0;
        // base case ;
        if(i == s1.size() || j == s2.size()){
            // remaing ASIIC value k sum print karna h 

            for(int x = i;x<s1.size();x++) minAns+=s1[x];
            for(int x = j;x<s2.size();x++) minAns+=s2[x];

        }

        // ek case solve karn h mujhe


        else if(s1[i] == s2[j]){

            minAns =  solveByMemo(s1,s2,i+1,j+1,dp);

        }
        else{

            int el1 = s1[i] + solveByMemo(s1,s2,i+1,j,dp);
            int el2 = s2[j]  + solveByMemo(s1,s2,i,j+1,dp);
            minAns = min(el1,el2);
        }
        dp[i][j]= minAns;
        

        return dp[i][j];

    }
    int solveByRec(string& s1,string& s2 , int i ,int j ){

        int minAns = 0;
        // base case ;
        if(i == s1.size() || j == s2.size()){
            // remaing ASIIC value k sum print karna h 

            for(int x = i;x<s1.size();x++) minAns+=s1[x];
            for(int x = j;x<s2.size();x++) minAns+=s2[x];

        }

        // ek case solve karn h mujhe


        else if(s1[i] == s2[j]){

            minAns =  solveByRec(s1,s2,i+1,j+1);

        }
        else{

            int el1 = s1[i] + solveByRec(s1,s2,i+1,j);
            int el2 = s2[j]  + solveByRec(s1,s2,i,j+1);
            minAns = min(el1,el2);
        }

        return minAns;
        
    }
    int solveByTab(string& s1,string& s2){
        vector<vector<int>>dp(s1.size()+1,vector<int>(s2.size()+1,0));

        // iniliase base case

        for(int i = s1.size()-1;i>=0;i--){
            dp[i][s2.size()] = s1[i] + dp[i+1][s2.size()];
        }

        
        for(int i = s2.size()-1;i>=0;i--){
            dp[s1.size()][i] = s2[i] + dp[s1.size()][i+1];
        }


        for(int i = s1.size()-1;i>= 0 ;i--){

            for(int j = s2.size()-1;j>=0;j--){

                int minAns = 0;
    
          

        // ek case solve karn h mujhe


        if(s1[i] == s2[j]){

                minAns = dp[i+1][j+1];

            }
            else{

                int el1 = s1[i] + dp[i+1][j];
                int el2 = s2[j]  + dp[i][j+1];
                minAns = min(el1,el2);
            }

            dp[i][j]= minAns;

            }
        }
        return dp[0][0];

    }
    int minimumDeleteSum(string s1, string s2) {
        // int solve = solveByRec(s1,s2,0,0);
        // vector<vector<int>>dp(s1.size()+1,vector<int>(s2.size()+1,-1));
        // int solve = solveByMemo(s1,s2,0,0,dp);
        int solve = solveByTab(s1,s2);
        return solve;

    }
};