class Solution {
public:
    string processStr(string s) {
        string ans = "";

        int n = s.size();
        for(auto i: s){
            if('a'<=i && i<='z'){
                ans+=i;
            }else if(i == '*'){
                if(!ans.empty()){
                    ans.pop_back();
                }
            }else if(i== '#'){
                if(!ans.empty()){
                    ans+=ans;
                }
            }else{
                if(!ans.empty()){
                    reverse(ans.begin(),ans.end());
                }
            }
        }   


        return ans;
    }
};