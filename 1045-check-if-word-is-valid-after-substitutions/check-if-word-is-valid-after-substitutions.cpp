class Solution {
public:
    bool bruteSol(string s){

        while(s.find("abc")!= string::npos){
            int findIndex = s.find("abc");
            s.erase(findIndex,3);

        }
        return s.empty();
    }
    bool isValid(string s) {
        return bruteSol(s);
    }
};