class Solution {
public:
    int depthMax(string s){
        int cnt = 0;
        int temp = 0;
        for(auto i: s){
            if(i =='('){
                temp++;
                cnt = max(cnt,temp);
            }else if(i == ')'){
                temp--;
            }
        }
        cnt = max(cnt,temp);
        return cnt;
    }
    int maxDepth(string s) {
        return depthMax(s);
    }
};