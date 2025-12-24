class Solution {
public:
    int recursiveOp(int n){
        if(n==0) return 0;
        if(n==1) return 1;

        int ans = recursiveOp(n-1)+ recursiveOp(n-2);
        return ans;
    }
    int fib(int n) {
        return recursiveOp(n);
    }
};