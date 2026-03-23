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
    string removeOuterParentheses(string s) {
        string removeOuter = removerParenthese(s);
        return removeOuter;
    }
};