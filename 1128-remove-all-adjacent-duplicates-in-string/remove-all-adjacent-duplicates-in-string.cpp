class Solution {
public:
    void removeDuplicate(string s,string & answer){
        for(int i = 0;i<s.size();i++){
            if(answer.empty()){
                answer.push_back(s[i]);
            }else if(answer[answer.size()-1]!=s[i]){
                answer.push_back(s[i]);
            }else{
                answer.pop_back();
            }
        }
    }
    string removeDuplicates(string s) {
        string answer = "";
        removeDuplicate(s,answer);
        return answer;
        
    }
};