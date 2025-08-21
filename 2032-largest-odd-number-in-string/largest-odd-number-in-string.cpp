class Solution {
public:
    string largestNumber(string numb){
       for(int i = numb.size()-1;i>=0;i--){
            if((numb[i]-'0') % 2 ==1){
                return numb.substr(0,i+1);
            }
       }
       return "";
        
    }
    string largestOddNumber(string numb) {
        string answer = largestNumber(numb);
        return answer;
    }
};