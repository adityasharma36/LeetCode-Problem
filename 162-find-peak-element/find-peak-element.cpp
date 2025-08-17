class Solution {
public:
    int bruteForce(vector<int>& nums){
        int len = nums.size()-1;

        if(nums.size() == 1) return 0;

        if(nums[0]> nums[1]) return 0;

        if(nums[len] > nums[len-1]) return len;

        for(int i = 1;i<nums.size()-1;i++){

            if((nums[i]>nums[i+1]) && (nums[i] > nums[i-1])){
                return i;
            }

        }
        return -1;
    }
    int findPeakElement(vector<int>& nums) {
        int answer = bruteForce(nums);
        return answer;
    }
};