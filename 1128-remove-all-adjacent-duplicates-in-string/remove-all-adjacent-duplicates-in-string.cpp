class Solution {
public:
    string removeDuplicates(string s) {
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
        
        // Pop elements out of the stack into a string
        string ans = "";
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        
        // Since stack is LIFO, the string is reversed. Reverse it back.
        reverse(ans.begin(), ans.end());
        return ans;
    }
};