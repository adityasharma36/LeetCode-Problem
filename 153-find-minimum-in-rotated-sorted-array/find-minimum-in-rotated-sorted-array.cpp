class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int start = 0;
        int end = n-1;
        int minEle = INT_MAX;
        while(start<=end){
            int mid = (end-start)/2 + start;
            if(nums[start]<=nums[mid]){
                minEle = min(minEle,nums[start]);
                start = mid+1;
            }else{
                end = mid;
            }
        }
        return minEle;
    }
};