class Solution {
public:
    void moveZeroFnc(vector<int>& nums){
        int start = 0;
        int mid = 0;
        while(mid<nums.size()){
            if(nums[mid] != 0){
                swap(nums[start],nums[mid]);
                start++;
            }
            mid++;
        }
    }
    void moveZeroes(vector<int>& nums) {
        moveZeroFnc(nums);
    }
};