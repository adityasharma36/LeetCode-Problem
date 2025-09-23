class Solution {
public:
    string decoString(string s){
        stack<string>st;
        for(int i = 0;i<s.size();i++){
            char ch = s[i];
            string collectWord = "";
            if(ch == ']'){
                while(!st.empty() && st.top() != "["){
                    collectWord+=st.top();
                    st.pop();
                }

                st.pop();

                string reverseNumber = "";

                while(!st.empty() && isdigit(st.top()[0])){
                    reverseNumber+=st.top();
                    st.pop();
                }

                reverse(reverseNumber.begin(),reverseNumber.end());
                int n = stoi(reverseNumber);

                string newString = "";
                while(n--){
                    newString+=collectWord;
                }
                st.push(newString);
            }else{
                string temp(1,ch);
                st.push(temp);
            }
        }
        string ans = "";
        while(!st.empty()){
            string temp = st.top();
            st.pop();
            ans+=temp;
        }
     reverse(ans.begin(),ans.end());
     return ans;
    }
    string decodeString(string s) {
        return decoString(s);
    }
};