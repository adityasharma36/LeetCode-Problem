class Solution {
public:
    string organizeString(string s){
        int hash[26] = {0};

        for(int i = 0;i<s.size();i++){
            hash[s[i]-'a']++;
        }
        int maxCount = INT_MIN;
        char maxEle;
        for(int i = 0;i<26;i++){
            if(hash[i]> maxCount){
                maxCount = hash[i];
                maxEle = i+'a';
            }
        }

        int index = 0;

        while(maxCount > 0 && index<s.size()){
            s[index]= maxEle;
            index+=2;
            maxCount--;
        }

        if(maxCount != 0) return "";

        hash[maxEle-'a'] = 0;

        for(int i = 0;i<26;i++){
            while(hash[i]>0){
                index = index >=s.size() ? 1: index;
                s[index]= i + 'a';
                hash[i]--;
                index +=2;
            }
        }
        return s;
    }
    string reorganizeString(string s) {
        return organizeString(s);
    }
};