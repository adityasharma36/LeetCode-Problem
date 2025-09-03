class Solution {
public:
    bool isPalindrome(string s){
        int start = 0;
        int end = s.size()-1;
        while(start<=end){
            if(s[start]!= s[end]) return false;

            start++;
            end--;
        }
    return true;
    }
    void palindromePartitioning(string s,vector<vector<string>>& palindromePar,int index,string tempString,vector<string>& tempArray){
        if(index == s.size()){
            palindromePar.push_back(tempArray);
            return;
        }

        for(int i = index;i<s.size();i++){

            tempString.push_back(s[i]);
            if(isPalindrome(tempString)){
                tempArray.push_back(tempString);
                palindromePartitioning(s,palindromePar,i+1,"",tempArray);
                tempArray.pop_back();
            }

        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> palindromePar;
        string tempString = "";
        vector<string>tempArray;
        palindromePartitioning(s,palindromePar,0,tempString,tempArray);
        return palindromePar;
    }
};