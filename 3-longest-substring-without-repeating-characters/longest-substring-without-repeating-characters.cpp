class Solution {
public:
    int longestSub(string s){
        int maxSub = 0;

        for(int i = 0; i < s.size(); i++){
            string temp = "";
            int j = i;

            while(j < s.size()){
                if(temp.find(s[j]) != string::npos){
                    maxSub = max(maxSub, (int)temp.length());
                    break; // stop this substring
                } else {
                    temp += s[j];
                    j++;
                }
            }

            maxSub = max(maxSub, (int)temp.length());
        }

        return maxSub;
    }
    int longestSubWind(string s){
        vector<int>temp(256,-1);
        int longestSub = 0;
        int left = 0;
        for(int right = 0;right<s.size();right++){
            if(temp[s[right]]>=left){
                left = temp[s[right]] +1;
            }
            temp[s[right]]=right;
            longestSub= max(longestSub,right-left+1);
        }
        return longestSub;
    }
    int lengthOfLongestSubstring(string s) {
        return longestSubWind(s);
    }
};