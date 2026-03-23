class Solution {
public:
    string reverseString(string s){
        vector<string>ch;
        string temp ;
        for(int i = 0;i<s.size();i++){
            if(s[i]!= ' '){
                temp+=s[i];
            }else if(temp!= ""){
                cout<<temp<<endl;
                ch.push_back(temp);
                temp = "";
            }
        }
        if(temp!=""){
            ch.push_back(temp);
            temp= "";
        }
        temp = "";
        for(int i = ch.size()-1;i>=0;i--){

            temp+=ch[i];
            
            if(i!=0){
                 
                temp+=" ";

            }
        }
        return temp;
    }
    string reverseWords(string s) {
        string reverWor= reverseString(s);
        return reverWor;
    }
};