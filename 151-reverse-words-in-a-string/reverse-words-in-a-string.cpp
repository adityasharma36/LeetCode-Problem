class Solution {
public:
    string reverseString(string s){
        string answer = "";
        stack<string> st;
        for(int i = 0;i<s.size();i++){
            char ch = s[i];

            if(ch == ' '){
                if(!answer.empty()){
                st.push(answer);
                answer = "";
                }
            }else{
                answer+=ch;
            }
        }
         if(!answer.empty()) st.push(answer);
        answer = "";
        while(st.size()!=1){
            answer+=st.top()+" ";
            st.pop();
        }
        answer+=st.top();
        st.pop();
        return answer;
    }
    string reverseWords(string s) {
        string answer = reverseString(s);
        return answer;
    }
};