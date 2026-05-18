class Solution {
public:
    string stackMethod(string s){
           stack<char> st;
        for(auto i : s){
            if(st.empty()){
                st.push(i);
            }
            else if(st.top() == i){
                st.pop();
            } else {
                st.push(i);
            }
        }

        string ans = "";
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    string optimseMethod(string s){
        string ans = "";
        for(auto i : s){
            if(!ans.empty() && ans.back()== i){
                ans.pop_back();
            }else{
                ans.push_back(i);
            }
        }
        return ans;
    }
    string removeDuplicates(string s) {
     
        // return stackMethod(s);
        return optimseMethod(s);
    }
};