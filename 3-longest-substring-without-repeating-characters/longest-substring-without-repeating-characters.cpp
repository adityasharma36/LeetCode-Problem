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

    int lengthOfLongestSubstring(string s) {
        return longestSub(s);
    }
};