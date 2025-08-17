class Solution {
public:
    int lowestInsert(vector<int>& nums,int target){
        int start = 0;
        int end = nums.size()-1;
        int index = -1;
        while(start<=end){
            int mid = start + (end-start)/2;
            if(nums[mid]==target){
                index = mid;
                end = mid-1;
            }else if(nums[mid]> target){
                index = mid;
                end = mid-1;
            }else{
                start = mid+1;
            }
        }
        if(index != -1) return index;
        return nums.size();
    }
    int searchInsert(vector<int>& nums, int target) {
        int answer = lowestInsert(nums,target);
        return answer;
    }
};