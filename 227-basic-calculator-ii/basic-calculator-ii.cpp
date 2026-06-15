class Solution {
public:
    int calculate(string s) {
        stack<int>st;

        s+='+';
        char ch = '+';
        int n = 0;

        for(auto i:s){
            if(i==' ') continue;

            else if(isdigit(i)){
                n = n*10 + (i-'0');
                continue;
            }
            else if(ch =='+'){
                st.push(n);
            }else if(ch =='-'){
                st.push(-n);
            }else if(ch =='*'){
                int top = st.top();st.pop();
                st.push(top*n);
            }else{
                int top = st.top();st.pop();
                st.push(top/n);
            }
            ch = i;
            n =0;
        }

        int res = 0;
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        return res;
    }
};