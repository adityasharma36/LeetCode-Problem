class Solution {
public:
    int maxVowels(string s, int k) {
        set<char>mp={'a','e','i','o','u'};

        int i = 0;
        int cnt = 0;
        int total = 0;
        int j = 0;
        int n = s.size();
        while(j<n){
         
               
            if(mp.find(s[j]) != mp.end()){
                cnt++;
            }
            if(j-i+1 >=k){
                total= max(cnt,total);
                if(mp.find(s[i]) != mp.end()){
                    cnt--;
                }
                i++;
            }
            j++;
        }
        return total;
    }
};