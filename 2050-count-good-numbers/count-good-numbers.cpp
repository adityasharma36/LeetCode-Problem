class Solution {
public:
    int M = 1e9+7;
    long long powerFun(long long n,long long powers){
        if(powers== 0) return 1;

        long long half = powerFun(n,powers/2);

        long long answer = (half * half) % M;

        if(powers%2 == 1){
            answer = (answer* n) % M;
        }

        return answer;
        
    }
    int countGoodNumbers(long long n) {
        long long evenNumber = (n+1)/2;
        long long oddNumber = n/2;

        return (int)powerFun(5,evenNumber)* powerFun(4,oddNumber) % M;
    }
};