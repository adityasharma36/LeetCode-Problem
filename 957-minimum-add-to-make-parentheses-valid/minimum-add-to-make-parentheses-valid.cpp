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
    int optimseSol(string s){
        int close = 0;
        int open = 0;
        for(auto i: s){
            if(i=='('){
                open++;
            }else{
                if(open>0){
                    open--;
                }else{
                    close++;
                }
            }
        }
        return open+close;
    }
    int minAddToMakeValid(string s) {
        // return bruteForce(s);
        return optimseSol(s);
    }
};