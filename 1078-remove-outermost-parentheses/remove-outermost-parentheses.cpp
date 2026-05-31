class Solution {
public:
    string removerParenthese(string s){
        int cnt = 0;
        string newString;
        for(auto ch: s){
            if(ch == '('){
                if(cnt>=1){
                    newString.push_back(ch);
                }
                cnt++;
            }else{
                if(cnt>1){
                    newString.push_back(ch);
                    
                }
                cnt--;
            }
        }
        return newString;
    }
    string removeParent(string s){
        stack<char>st;
        string newparen;
        for(auto i: s){
            if(i == '('){
                if( !st.empty() && st.top()== '('){
                    newparen.push_back(i);
                }
                st.push(i);
            }else{
                if(st.size()>1){
                    newparen.push_back(i);
                    
                }
                st.pop();
            }
        }
        return newparen;

    }
    string removeOuterParentheses(string s) {
        // string removeOuter = removerParenthese(s);
        string stackMethod = removeParent(s);
        return stackMethod;
    }
};