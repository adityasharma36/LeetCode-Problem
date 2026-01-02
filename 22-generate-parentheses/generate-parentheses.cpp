class Solution {
public:
    void genParen(vector<string>&ans,string& st,int open,int close,int n){
        if(open == n && close == n){
            ans.push_back(st);
            return;
        }
        if(open<n){
            st.push_back('(');
            genParen(ans,st,open+1,close,n);
            st.pop_back();
        }
        if(close< open){
            st.push_back(')');
            genParen(ans,st,open,close+1,n);
            st.pop_back();
        }
        
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string st = "";
        genParen(ans,st,0,0,n);
        return ans;
    }
};