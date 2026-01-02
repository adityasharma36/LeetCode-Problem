class Solution {
public:
    vector<int>anagram(string s,string p){
        vector<int> ans;
        if(s.size()<p.size()) return ans;

        int start = 0;
        int right = 0;
        int count = p.size();
        unordered_map<char,int>um;
        for(auto i: p){
            um[i]++;
        }
        for(int i = 0;i<s.size();i++){
            
            char ch = s[i];
            if(um.find(ch)!= um.end()){
                if(um[ch]>0)count--;
                um[ch]--;
            }

            if(i-start+1 == p.size()){
                if(count == 0){
                    ans.push_back(start);
                }

                char leftChar = s[start];
                if(um.find(leftChar)!= um.end()){
                    if(um[leftChar]>=0)count++;
                    um[leftChar]++;
                }

                start++;

            }
        }
        return ans;
    }
    vector<int> findAnagrams(string s, string p) {
        return anagram(s,p);
    }
};