class Solution {
public:
    void moveZero(vector<int>& nums){
        int start = 0;
        int mid = 0;
        int len = nums.size();
        while(mid<len){
            if(nums[mid] != 0){
                swap(nums[start],nums[mid]);
                start++;
            }
            mid++;
        }
    }
    void moveZeroes(vector<int>& nums) {
        moveZero(nums);
    }
};