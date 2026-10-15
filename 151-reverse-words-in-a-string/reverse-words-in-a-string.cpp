class Solution {
public:
    string bySpace(string s){
        vector<string>reve;
        int n = s.size();
        int i = 0;
        while(i<n){
            while(i < n && s[i] == ' '){
                i++;
            }
            
            string temp = "";
            while(('A' <= s[i] && s[i]<='Z')|| ('a' <= s[i] && s[i]<='z') || 
            ('0'<=s[i] && s[i]<='9')){
                temp.push_back(s[i]);
                i++;
            }
            if(temp != ""){
                reve.push_back(temp);
            }
        }   
        for(auto i: reve){
            cout<<i<<" ";
        }
        string ans = "";

        n = reve.size();

        reverse(reve.begin(),reve.end());

        for(int i = 0;i<n;i++){
            if(i == n-1){
                ans+=reve[i];
            }else{
                ans+=reve[i];
                ans+=" ";
            }
        }
        if( ans != ""){
            return ans;
        }
        return "";
    }   
    string optimiseSol(string s){
        int n = s.size();
        int i = 0;
        int left = 0;
        int right = 0;
        reverse(s.begin(),s.end());

        while(i<n){
            while(i < n && s[i] == ' ') i++;
            if(i == n) break;
            while(i<n && s[i] != ' '){
                s[right++] = s[i++];
            }
            reverse(s.begin() + left , s.begin()+ right);
            s[right++] = ' ';
            left = right;
            i++;
        }
        s.resize(right-1);
        return s;
    }
    string reverseWords(string s) {
        // return bySpace(s);
        return optimiseSol(s);
        
    }
};