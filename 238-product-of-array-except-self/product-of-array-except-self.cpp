class Solution {
public:
    vector<int>bruteForce(vector<int>& nums){
        int n = nums.size();
        vector<int>suff(n,0);
        vector<int>pref(n,0);
        int left_Pro = 1;
        for(int i = 0;i<n;i++){
            pref[i]= left_Pro;
            left_Pro*=nums[i];

        }
        int right_Pro = 1;
        for(int i = n-1;i>=0;i--){
            suff[i]= right_Pro;
            right_Pro*=nums[i];

        }
        for(int i = 0;i<n;i++){
            nums[i]= pref[i]*suff[i];
        }
        return nums;
    }
    vector<int> productExceptSelf(vector<int>& nums) {
        return bruteForce(nums);
    }
};