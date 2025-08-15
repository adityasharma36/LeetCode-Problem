class Solution {
public:
    int singleNumb(vector<int>& nums){
        int single = 0;
        for(int i = 0;i<nums.size();i++){
            single^=nums[i];
        }
        return single;
    }
    int singleNumber(vector<int>& nums) {
        int answer = singleNumb(nums);
        return answer;
    }
};