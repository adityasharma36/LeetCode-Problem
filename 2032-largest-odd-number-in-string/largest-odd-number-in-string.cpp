class Solution {
public:
    string largestOddNumber(string num) {
        int i = num.size()-1;
        while(i>=0){
            int in = num[i]-'0';
            if(in%2==1)return num.substr(0,i+1);
            i--;
        }
        return "";
    }
};