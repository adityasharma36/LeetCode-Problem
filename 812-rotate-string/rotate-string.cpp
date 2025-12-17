class Solution {
public:
    // bool uniqeCheck(string s,string g){
    //     unordered_map<char,int> freq;

    //     for(int i = 0;i<s.size();i++){
    //         freq[s[i]]++;
    //     }
    //     for(int j= 0;j<g.size() ;j++){
    //         freq[g[j]]--;
    //     }

    //     return (freq.size()==0);
    // }
    // bool findEle(string s,string goal){
    //      int cnt = 0;
    //     string temp ;
        
    //     for(int i = 0;i<s.size();i++){
    //         temp+=s[i];

    //         if(goal.find(temp)==string::npos){
    //             cnt++;
    //             temp = s[i];
    //         }
    //     }

    //     if(cnt>1) return false;
    //     return true;
    // }
  
    bool rotateString(string s, string goal) {
        
        if(s.size() != goal.size()) return false;

        string newString = s+ s;

        if(newString.find(goal) == string::npos) return false;

        return true;
    }
};