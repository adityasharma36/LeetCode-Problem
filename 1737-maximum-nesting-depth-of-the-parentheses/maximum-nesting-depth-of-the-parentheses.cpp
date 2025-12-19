class Solution {
public:
    int maxDepth(string s) {
        int cnt = 0;
        int temp = 0;
        for(int i= 0;i<s.size();i++){
            if(s[i] == '('){
                temp++;
            }else if(s[i]== ')'){
                cnt = max(cnt,temp);
                temp--;
            }
        }
        cnt = max(cnt, temp);
        return cnt;
    }
};