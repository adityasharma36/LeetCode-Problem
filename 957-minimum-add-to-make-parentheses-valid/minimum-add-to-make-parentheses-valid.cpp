class Solution {
public:
    int bruteForce(string s){
        stack<char>st;

        for(auto i: s){
            if(i=='('){
                st.push(i);
            }else{
                if(!st.empty() && st.top()=='('){
                    st.pop();
                }else{
                    st.push(i);
                }
            }
        }
        return st.size();
    }
    int minAddToMakeValid(string s) {
        return bruteForce(s);
    }
};