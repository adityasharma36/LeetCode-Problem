class Solution {
public:
    void genParenthesis(int n,vector<string>&ans, int open,int close ,string answer){
        if(open == 0 && close == 0)
         {
            ans.push_back(answer);
            return ;
        } 

        if(open>0){
            genParenthesis(n,ans,open-1, close ,answer+"(");
        }

        if(close >0  && close > open){
            genParenthesis(n,ans,open,close-1,answer+")");
        }

    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string answer;
         genParenthesis(n,ans,n,n,answer);
         return ans;
    }
};