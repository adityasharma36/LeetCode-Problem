class Solution {
public:
    bool firstMethod(string s,string t){
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
    bool secondMethod(string s,string t){
        int hashMap[256]= {0};
        bool isVisited[256] = {0};

        for(int i = 0;i<s.size();i++){

            if(hashMap[s[i]] == 0 && isVisited[t[i]] == 0){
                hashMap[s[i]]= t[i];
                isVisited[t[i]] = true;
            }
        }
         for(int i = 0;i<s.size();i++){
                if(char(hashMap[s[i]]) != t[i]) return false;
            }
        return true;
    }
    bool isIsomorphic(string s, string t) {
        // return firstMethod(s,t);

        return secondMethod(s,t);
    }
};