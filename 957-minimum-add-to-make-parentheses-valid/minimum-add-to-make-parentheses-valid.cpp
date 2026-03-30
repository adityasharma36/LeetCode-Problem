class Solution {
public:
    int addToMake(string s){
        stack<char>st;
        for(int i = 0;i<s.size();i++){
            if(s[i]=='('){
                st.push('(');
            }else{
                if(!st.empty() && st.top()=='('){
                    st.pop();
                }else{
                    st.push(s[i]);
                }
            }
        }
        return st.size();
    }
    int minAddToMakeValid(string s) {
     return addToMake(s);
    }
};