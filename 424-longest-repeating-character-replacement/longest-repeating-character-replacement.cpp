class Solution {
public:
    int replacementChar(string s,int k){
        int start = 0;
        int ans = 0;
        int fre = 0;

        unordered_map<char,int> freq;

        for(int right = 0;right<s.size();right++){
            char ch = s[right];

            freq[ch]++;
            fre = max(fre, freq[ch]);

            while((right-start+1)-fre> k){
                freq[s[start]]--;
                start++;
            }
            ans = max(ans,right-start+1);
        }
        return ans;
    }
    int characterReplacement(string s, int k) {
        return replacementChar(s,k);
    }
};