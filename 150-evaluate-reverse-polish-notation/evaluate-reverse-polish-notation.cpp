class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;

        int n = tokens.size();

        for(int i = 0;i<n;i++){
            string ch = tokens[i];

            if(ch =="+"){
                int ele1 = st.top();st.pop();
                int ele2 = st.top();st.pop();
                int sum = ele2 + ele1;
                st.push(sum);
            }else if(ch =="-"){
                int ele1 = st.top();st.pop();
                int ele2 = st.top();st.pop();
                int sub = ele2 - ele1;
                st.push(sub);
            }else if(ch =="*"){
                int ele1 = st.top();st.pop();
                int ele2 = st.top();st.pop();
                int multi = ele2 * ele1;
                st.push(multi);
            }
            else if(ch =="/"){
                int ele1 = st.top();st.pop();
                int ele2 = st.top();st.pop();
                int diff = ele2 / ele1;
                st.push(diff);
            }else{

                int ele = stoi(ch);
                st.push(ele);

            }
        }


        return st.top();
    }
};