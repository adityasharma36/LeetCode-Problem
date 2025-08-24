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
    void addTwoStringByRec(string& num1,int num1Len,string& num2,int num2Len,int carry,string &ans){


        // base case pata nhiii
        if(num1Len<0 && num2Len <0 && carry == 0){
           
            return;
        }

        // main logic 

        int num1Digit = num1Len >= 0 ? (num1[num1Len]-'0') : 0;

            int num2Digit = num2Len >= 0 ? (num2[num2Len]-'0') : 0;

            int twoDigitSum = num1Digit + num2Digit;

            twoDigitSum+=carry;

            int pushDigit = twoDigitSum% 10;

            ans+=(pushDigit + '0');

            carry = twoDigitSum/10;

            addTwoStringByRec(num1,num1Len-1,num2,num2Len-1,carry,ans);


    
    }
    string addStrings(string num1, string num2) {
        // return addTwoString(num1,num2);
        string ans = "";
         addTwoStringByRec(num1,num1.size()-1,num2,num2.size()-1,0,ans);
            reverse(ans.begin(),ans.end());
        return ans;
    }
};