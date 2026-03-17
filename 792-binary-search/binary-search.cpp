class Solution {
public:
    int searchFnc(vector<int>& nums,int target){
        int start = 0;
        int end = nums.size()-1;
        while(start<=end){
            int mid = (end-start)/2 + start;

            if(nums[mid]== target){
                return mid;
            }else if(nums[mid]>target){
                end = mid-1;
            }else{
                start = mid+1;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        return searchFnc(nums,target);
    }
};