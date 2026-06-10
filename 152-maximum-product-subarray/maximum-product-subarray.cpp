class Solution {
public:
    int bruteForce(vector<int>& nums){
        int maxLen = INT_MIN;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            int temp = nums[i];
            for(int j  = i+1;j<n;j++){
                maxLen = max(maxLen,temp);
                temp*=nums[j];
            }
            maxLen = max(maxLen,temp);
        }
        return maxLen;
    }
    int maxProduct(vector<int>& nums) {
        return bruteForce(nums);
    }
};