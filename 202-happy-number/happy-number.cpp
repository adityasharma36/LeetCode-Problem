class Solution {
public:
    bool isHappy(int n) {
       
       unordered_map<int,bool> um;
       int sum  = 0;

       while(n){

            if(n==1) return true;

            

            while(n){
                
                int front = n% 10;
                sum+= (front* front);


                n = n/10;
            }
            cout<<sum<<endl;
            

            

            if(um[sum]) return false;
            um[sum]= true;
            n = sum;

            sum = 0;
       }
       return false;
    }
};