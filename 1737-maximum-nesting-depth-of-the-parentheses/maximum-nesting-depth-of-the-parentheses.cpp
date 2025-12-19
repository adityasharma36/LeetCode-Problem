class Solution {
public:
    int countMethod(string s){
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
    int stackMethod(string s){
    stack<char> st;
    int cnt = 0;

    for(int i = 0; i < s.size(); i++){
        if(s[i] == '('){
            st.push(s[i]);
            cnt = max(cnt, (int)st.size());
        }
        else if(s[i] == ')'){
            if(!st.empty()){
                st.pop();
            }
        }
    }
    return cnt;
}

    int maxDepth(string s) {
    //    return countMethod(s);
    return stackMethod(s);
    }
};