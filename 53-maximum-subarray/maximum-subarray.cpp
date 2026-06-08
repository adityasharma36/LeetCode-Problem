class Solution {
public:
    int kadaneAlgo(vector<int>& nums){
        int maxSub = INT_MIN;
        int tempSum = 0;

        for(auto i: nums){
            tempSum+=i;
            maxSub = max(maxSub,tempSum);
            if(tempSum<0){
                tempSum =0;
            }
        }
        return maxSub;
    }
    int maxSubArray(vector<int>& nums) {
        return kadaneAlgo(nums);
    }
};