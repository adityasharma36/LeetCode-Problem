class Solution {
public:
    int calculate(string s) {
        stack<int>st;
        long curr = 0;
        int res = 0;
        int sign = 1;

        for(auto i : s){

            // what if there is only digit 

            if(isdigit(i)){
                curr= curr*10 + (i-'0');

            }
            else if(i == '+'){
                res+=sign*curr;
                curr = 0;
                sign = 1;
            }else if(i=='('){
                st.push(res);
                st.push(sign);
                sign = 1;
                res = 0;
            }else if(i=='-'){
                res+=sign*curr;
                sign = -1;
                curr = 0;
            }else if(i == ')'){
                res+=sign*curr;
                curr = 0;
                res*=st.top();st.pop();
                res+=st.top();st.pop();
            }
        }
        res+=curr*sign;

        return res;
    }
};