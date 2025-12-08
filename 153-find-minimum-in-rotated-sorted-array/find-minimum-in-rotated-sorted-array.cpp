class Solution {
public:
    int minFind(vector<int>& nums){
        int minVal = INT_MAX;

        int start = 0;
        int end = nums.size()-1;
        while(start<=end){
            int mid = (end-start)/2 + start;

            if(nums[start]<=nums[mid]){
                minVal = min(minVal, nums[start]);
                start = mid+1;
            }else{
                end = mid;
            }
        }
        return minVal;
    }
    int findMin(vector<int>& nums) {
        return minFind(nums);
    }
};