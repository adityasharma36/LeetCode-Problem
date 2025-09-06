class Solution {
public:
    bool findString(string s, vector<string>& wordDict){
        for(auto i : wordDict){
            if(i == s){
                return true;
            }
        }
        return false;
    }
    bool solveByRec(string s, vector<string>& wordDict,int start){

        if(start == s.size()){

            return true;

        }

        string ans = "";

        bool isPossible = false;

        for(int i = start;i<s.size();i++){

            ans+=s[i];

            if(findString(ans,wordDict)){

                // sabse main line h 
                isPossible = isPossible ||  solveByRec(s,wordDict,i+1);

            }
        }
        return isPossible;
    }


    bool solveByMemo(string s,vector<string>& wordDict,vector<int>& dp,int start){


        if(start == s.size()){

            return true;

        }

        if(dp[start] != -1){

            return dp[start];

        }

        string ans = "";

        bool isPossible = false;

        for(int i = start;i<s.size();i++){

            ans+=s[i];

            if(findString(ans,wordDict)){

                // sabse main line h 
                isPossible = isPossible ||  solveByMemo(s,wordDict,dp,i+1);

            }
        }
        dp[start] = isPossible;
        return dp[start];
    }

    bool solveByTab(string s, vector<string>& wordDict){

        vector<int>dp(s.size()+1,true);

        for(int i = s.size()-1;i>= 0;i--){


            
            string ans = "";

            bool isPossible = false;

            for(int j = i;j<s.size();j++){

                ans+=s[j];

                if(findString(ans,wordDict)){

                // sabse main line h 
                    isPossible = isPossible ||  dp[j+1];

                }
            }
        dp[i] = isPossible;

        }

        return dp[0];


    }
    bool wordBreak(string s, vector<string>& wordDict) {
        // bool solve = solveByRec(s,wordDict,0) ;
        // vector<int>dp(s.size()+1,-1);
        // bool solve = solveByMemo(s,wordDict,dp,0);
        bool solve = solveByTab(s,wordDict);
        return solve;

    }
};