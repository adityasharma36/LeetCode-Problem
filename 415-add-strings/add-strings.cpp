class Solution {
public:
    string addTwoString(string num1,string num2){
        int num1Len = num1.size()-1;
        int num2Len = num2.size()-1;
        int carry = 0;
        string ans = "";
        while(num1Len>=0 ||  num2Len>=0 || carry){

            int num1Digit = num1Len >= 0 ? (num1[num1Len--]-'0') : 0;
            int num2Digit = num2Len >= 0 ? (num2[num2Len--]-'0') : 0;

            int twoDigitSum = num1Digit + num2Digit;

            twoDigitSum+=carry;

            int pushDigit = twoDigitSum% 10;

            ans+=(pushDigit + '0');

            carry = twoDigitSum/10;

        }
        reverse(ans.begin(),ans.end());

        return ans;
    }
    string addStrings(string num1, string num2) {
        return addTwoString(num1,num2);
    }
};