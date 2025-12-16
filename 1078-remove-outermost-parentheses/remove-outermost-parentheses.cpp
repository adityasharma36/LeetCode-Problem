class Solution {
public:
    string outerParent(string s){
        int cnt = 0;
        string ans = "";
        for(int i = 0;i<s.size();i++){
            
            char ch = s[i];

            if(ch == '('){
                if(cnt>0){
                    ans+=ch;
                }
                cnt++;
            }else{
                cnt--;
                if(cnt>0){
                    ans+=ch;
                }
            }
        }
        return ans;
    }
    string stackMethod(string s){
        stack<char> st;
        string ans = "";
        for(int i = 0;i<s.size();i++){
            char ch = s[i];

            if(ch == '('){
                if(!st.empty()){
                    ans+=ch;
                }
                st.push(ch);
            }else{
                st.pop();
                if(!st.empty()){
                    ans+=ch;
                }
            }
        }
        return ans;
    }
    string removeOuterParentheses(string s) {
        // string ans = outerParent(s);
        string ans = stackMethod(s);
        return ans;
    }
};