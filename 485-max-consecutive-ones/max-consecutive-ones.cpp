class Solution {
public:
    int consecutiveOne(vector<int>& nums){
        int count = 0;
        int temp =0;
        for(int i = 0;i<nums.size();i++){
            if(nums[i] != 1){
                count = max(count , temp);
                temp = 0;
            }else{
                temp++;
            }
        }
        count = max(count,temp);
        return count;
    }
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int answer = consecutiveOne(nums);
        return answer;
    }
};