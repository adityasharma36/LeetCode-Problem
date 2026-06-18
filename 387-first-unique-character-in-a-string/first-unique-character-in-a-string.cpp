class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int>um;
        for(auto i: s){
            um[i]++;
        }

        for(int i = 0;i<s.size();i++){
            int cnt = um[s[i]];
            if(cnt == 1) return i;
        }
        return -1;
    }
};