class Solution {
public:
    int removeDuplicateFnc(vector<int>& nums){
        int start = 0;
        int mid = 0;
        while(mid<nums.size()){
            if(nums[start]!= nums[mid]){
                 start++;
                 swap(nums[start],nums[mid]);
            }
            mid++;
        }
        return start+1;
    }
    int removeDuplicates(vector<int>& nums) {
        return removeDuplicateFnc(nums);
    }
};