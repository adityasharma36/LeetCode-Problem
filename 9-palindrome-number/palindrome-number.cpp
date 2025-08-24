class Solution {
public:
    bool answer(int x){
        if(x<0) return false;

        long long rem = 0;
        long long revNum = x;
        while(revNum != 0){
            rem = rem * 10 + revNum % 10;
            revNum/=10;
        }
        return x == rem;
    }
    bool isPalindrome(int x) {
        return answer(x);
    }
};