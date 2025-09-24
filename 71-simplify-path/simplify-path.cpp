class Solution {
public:
    void reverseString(stack<string>& st,string& ans){
        if(st.empty()){
            return;
        }
        string tempAns = st.top();st.pop();
        reverseString(st,ans);
        ans+=tempAns;
    }
    string simpfyPath(string  path){
        stack<string> st;
        int i = 0;
        while(i<path.size()){
            int start = i;
            int end = i+1;

            while(end<path.size() && path[end]!= '/'){
                end++;
            }
            string tempString = path.substr(start,end-start);
            i = end;

            if(tempString == "/" || tempString == "/."){
                continue;
            }
            if(tempString!= "/.."){
                st.push(tempString);
            }else if(!st.empty()){
                st.pop();
            }
        }
        string ans = st.empty() ? "/" :"";

        reverseString(st,ans);
        return ans;
    }
    string simplifyPath(string path) {

        return simpfyPath(path);
        
    }
};