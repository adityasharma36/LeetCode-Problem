class Solution {
public:
    double findPower(double x, long long n){
        double answer = 1.0;

        long long checkSign = n;
        if(checkSign<0) checkSign = n*-1;

        while(checkSign){
            if(checkSign%2==1){
                answer = answer*x;
                checkSign = checkSign-1;
            }else{
                x= x * x;
                checkSign  = checkSign/2;
            }
        }
        if(n<0)  return (double)(1.0)/ (double)(answer);
        return answer;
    }
    double myPow(double x, int n) {
        double answer = findPower(x,n);
        return answer;
    }
};