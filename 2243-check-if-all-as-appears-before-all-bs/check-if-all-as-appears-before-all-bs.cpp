class Solution {
public:
    bool checkString(string s) {
       bool check = true;
       for(auto i: s){
        if(i == 'a'){
            if(!check){
                return false;
            }
        }else{
            check = false;
        }
       } 
       return true;
    }
};