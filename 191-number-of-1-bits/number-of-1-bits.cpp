class Solution {
public:
    int weightHamming(int n){
        int cnt = 0;
        while(n){
            cnt++;
            n = n & (n-1);
        }
        return cnt;
    }

    int hammingWeight(int n) {
        return weightHamming(n);
    }
};