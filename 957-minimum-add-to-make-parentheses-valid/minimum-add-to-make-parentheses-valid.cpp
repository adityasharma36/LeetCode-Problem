class Solution {
public:
    int minMakeValid(string s){
        stack<char>st;
        for(int i = 0;i<s.size();i++){
            char ch = s[i];

            if(ch == '('){
                st.push(ch);
            }else if(!st.empty() && ch == ')' && st.top() == '('){
                st.pop();
            }else{
                st.push(ch);
            }
        }
        return st.size();
    }
    int minAddToMakeValid(string s) {
        return minMakeValid(s);
    }
};