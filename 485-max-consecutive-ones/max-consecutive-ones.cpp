class Solution {
public:
    int maxConFnc(vector<int>& nums){
        int cnt = 0;
        int maxLen = 0;

        for(int i = 0;i<nums.size();i++){
            if(nums[i]==0){
                maxLen = max(cnt,maxLen);
                cnt= 0;
            }
            else{
                cnt++;
            }
        }
        maxLen = max(cnt,maxLen);

        return maxLen;
    }
    int findMaxConsecutiveOnes(vector<int>& nums) {
        return maxConFnc(nums);
    }
};