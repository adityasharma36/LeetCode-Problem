class Solution {
public:
    int subString(string s){
        int left = 0;
        int right = 0;
        int cnt = 0;
        unordered_map<char,int>um;
        while(right<s.size()){
            um[s[right]]++;
            while(um['a']>=1 && um['b']>=1 && um['c']>=1){
                cnt +=s.size()-right;
                um[s[left]]--;
                left++;
            }
            right++;
        }
        return cnt;
    }
    int numberOfSubstrings(string s) {
        return subString(s);
    }
};