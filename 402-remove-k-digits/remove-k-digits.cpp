class Solution {
public:
    string removeKdigits(string num, int k) {
        
        stack<char>st;
        for(auto i : num){
            if(k>0){
                while(!st.empty() &&  k>0 && i< st.top()){
                    st.pop();
                
                k--;
                if(k==0) break;
            }
            }
            st.push(i);
        }

        if(k>0){
            while(!st.empty() && k){
                st.pop();
                k--;
                if(k==0) break;
            }
        }

        string ans = "";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }

        while(ans.size() > 0 && ans.back() == '0'){
            ans.pop_back();
        }
        reverse(ans.begin(),ans.end());
        return ans== "" ? "0" : ans;
    }
};