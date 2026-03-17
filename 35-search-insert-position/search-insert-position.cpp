class Solution {
public:
    int searchFnc(vector<int>& nums,int target){
        int start = 0;
        int end = nums.size()-1;
        while(start<=end){
            int mid = (end-start)/2 + start;

            if(nums[mid]== target){
                return mid;
            }else if(nums[mid]<target){
                start = mid+1;
            }else{
                end = mid-1;
            }
        }
        return start;
    }
    int searchInsert(vector<int>& nums, int target) {
        return searchFnc(nums,target);
    }
};