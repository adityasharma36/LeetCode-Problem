class Solution {
public:
    bool powerOfTwo(int n){

        if(n<=0) return false;
        if(n==1){
            return true;
        }
        int cnt = 0;
        while(n != 0){

            cnt++;
            n = n& n-1;
        }
        return cnt==1 ? true:false;
    }
    bool isPowerOfTwo(int n) {
        return powerOfTwo(n);
    }
};