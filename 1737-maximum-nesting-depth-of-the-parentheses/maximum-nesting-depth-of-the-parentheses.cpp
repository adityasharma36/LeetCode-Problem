class Solution {
public:
    int maximumNestingDepth(string s){
        int maxNestDepth = INT_MIN;
        stack<char> st;

        for(int i = 0;i<s.size();i++){
            if(s[i] == '(') st.push(s[i]);
            else if(s[i]== ')') st.pop();

            int stackSize = st.size();
            maxNestDepth = max(maxNestDepth , stackSize);
        }
        return maxNestDepth;
    }
    int maxDepth(string s) {
        return maximumNestingDepth(s);
    }
};