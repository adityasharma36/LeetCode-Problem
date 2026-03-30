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
    int makeToAdd(string s){
        int open = 0;
        int need = 0;
        for(auto i: s){
            if(i == '('){
                open++;
            }else{
                if(open>0){
                    open--;
                }else{
                    need++;
                }
            }
        }
        return open+need;
    }
    int minAddToMakeValid(string s) {
    //  return addToMake(s);
        return makeToAdd(s);
    }
};