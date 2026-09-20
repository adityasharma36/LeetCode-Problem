class Solution {
public:
    set<string>st;
    vector<string>solveByRec(string s,int i){
        if(i== s.size()) return {""};
        vector<string>ans;
        string word;
        for(int j = i;j<s.size();j++){
            word.push_back(s[j]);
            if(st.find(word) == st.end()) continue;

            auto rightSolve = solveByRec(s,j+1);
            for(auto eachPart : rightSolve){
                string endPart;
                if(eachPart.size() >0) endPart = " " + eachPart;
                ans.push_back(word + endPart);
            }
        }
        return ans;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for(auto i:wordDict){
            st.insert(i);
        }
        vector<string>ans = solveByRec(s,0);
        return ans;
    }
};