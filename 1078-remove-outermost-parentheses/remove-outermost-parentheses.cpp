class Solution {
public:
    string removeParentheses(string s){

        int balance = 0;
        
        string ans;
        
        for(int i= 0;i<s.size();i++){
        
            char ch = s[i];

            if(ch == '('){
                
                if(balance > 0){
                
                    ans+=ch;
                
                }
                
                balance++;
            }
            
            else{
            
                balance--;
            
                if(balance >0 ){
            
                        ans+=ch;
            
                    }
            
             }
            
        }
        return ans;
    }
    string removeOuterParentheses(string s) {
        string answer = removeParentheses(s);
        return answer;
    }
};