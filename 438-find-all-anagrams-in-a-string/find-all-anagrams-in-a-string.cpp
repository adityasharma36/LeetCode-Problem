class Solution {
public:
    bool isZero(vector<int>&count){
        for(auto &i: count){
            if(i!=0) return false;
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        vector<int>ans;
        int n = s.size();
        int m = p.size();

        vector<int>count(26,0);
        for(auto i:  p){
            count[i-'a']++;
        }

        int index = 0;
        int j = 0;
        while(j<n){
            count[s[j]-'a']--;
            if(j-index + 1 == m){
                if(isZero(count)){
                    ans.push_back(index);
                }
                count[s[index]-'a']++;
                index++;
            }
            j++;
        }
        return ans;
    }
};