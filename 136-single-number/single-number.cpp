class Solution {
public:
    int singleFnc(vector<int>& nums){
        int singleEle = 0;
        for(int i = 0;i<nums.size();i++){
            singleEle^= nums[i];
        }
        return singleEle;
    }
    int singleNumber(vector<int>& nums) {
        return singleFnc(nums);
    }
};