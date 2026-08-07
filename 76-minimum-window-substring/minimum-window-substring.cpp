class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int minCount = t.size();

        if(minCount>n) return "";

        int i = 0,j = 0;
        int minSizeWindow = INT_MAX;
        int start_i = 0;
        unordered_map<char,int>um;
        for(auto i: t){
            um[i]++;
        }

        while(j<n){
            char ch = s[j];
            if(um[ch] > 0) minCount--;
            um[ch]--;

            while(minCount==0){
                int size = j-i+1;
                if(minSizeWindow > size){
                    minSizeWindow = size;
                    start_i = i;
                }

                char ch_i = s[i];
                um[ch_i]++;
                if(um[ch_i] > 0){
                    minCount++;
                    }
            
                i++;
            }
            j++;
        }
        return minSizeWindow == INT_MAX ? "": s.substr(start_i,minSizeWindow);
    }
};