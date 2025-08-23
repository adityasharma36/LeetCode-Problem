class Solution {
public:

    // wrong approach 

    string longCommonPref(vector<string>& strs){
        string answer = "";
        if(strs.size()==1) return strs[0];
        string temp = strs[0];

        for(int i = 1;i<strs.size();i++){
            string ans = strs[i];
            string chara ;
            for(auto an: ans){
                chara+=an;
                if(temp.find(chara)!= string::npos){
                    answer = chara;
                }
            }
            temp = answer;
        }
        return answer;
    }
    

    // prefix chaiye  
    // ek string ko fix karke baki ko iterate karege
    // and prefix string and itereate stirng k start common part find karege
    // and uske badd prefix stirng me uska substr find kara lenge
    
    string longestCommonPref(vector<string>& strs){
    
        string ans = strs[0];

        for(int i= 1;i<strs.size();i++){

            string secondStr = strs[i];

            int j = 0;
            while(j<ans.size() && j<secondStr.size() && ans[j]== secondStr[j]){
                j++;
            }
            ans = ans.substr(0,j);

            if(ans.empty()) return "";
        }
        return ans;
    }
    string longestCommonPrefix(vector<string>& strs) {
        // return  longCommonPref(strs);
        return longestCommonPref(strs);

    }
};