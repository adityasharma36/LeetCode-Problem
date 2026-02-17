class Solution {
public:
    int maxSubArrayFnc(vector<int>& nums){
        int maximumSum = INT_MIN;
        int tempSum = 0;
        for(int i = 0;i<nums.size();i++){
            tempSum+=nums[i];

            if(tempSum> maximumSum){
                maximumSum = tempSum;
            }
            if(tempSum<0){
                tempSum = 0;
            }
        }
        return maximumSum;
    }
    int maxSubArray(vector<int>& nums) {
        return maxSubArrayFnc(nums);
    }
};