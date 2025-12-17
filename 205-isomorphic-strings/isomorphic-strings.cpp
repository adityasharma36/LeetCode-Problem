class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> freq;
        unordered_map<char,char>fr;

        for(int i = 0;i< s.size();i++){
            char st = s[i];
            char ct = t[i];

            if(freq.count(st) && freq[st] != ct) return false;
            if(fr.count(ct) && fr[ct] != st) return false;

            freq[st] = ct;
            fr[ct] = st;

        }
      return true;
    }
};