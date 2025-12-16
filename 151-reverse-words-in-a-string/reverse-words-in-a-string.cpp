class Solution {
public:
    string reverseWords(string s) {
        vector<string> vc;
        string temp = "";
        for(int i = 0;i<s.size();i++){

            char ch = s[i];
            
          if(ch != ' '){
            temp+=ch;
          }else if(temp!= ""){
            vc.push_back(temp);
            temp = "";
          }
        }

      if(temp != ""){
            vc.push_back(temp);
            temp = "";
        }

        for(int i = vc.size()-1;i>= 0;i--){
            temp+=vc[i];
            if(i !=0){
            temp+=" ";
            }
        }
        return temp;
    }
};