class Solution {
public:
    int largestAltitude(vector<int>& gain) {
         int larAlt = 0;
         int temp = 0;
         for(auto i : gain){
            temp+=i;
            if(temp>0){

            larAlt = max(larAlt, temp);
            }
         }
         return larAlt;
    }
};