class Solution {
public:
    int sortedSubArray(vector<int>& nums){

        int left = 0;
        int right = nums.size()-1;
        int leftMin = INT_MAX;
        int rightMax = INT_MIN;
        bool flag = false;

        for(int i  = 1;i< nums.size();i++){

            if(nums[i]< nums[i-1]){

                flag = true;

            }

            if(flag){

                leftMin  = min(leftMin,nums[i]);

            }
        }
        if(leftMin == INT_MAX) return 0;
        flag = false;

        for(int i = nums.size()-2;i>= 0;i--){

            if(nums[i]>nums[i+1]){
                flag = true;
            }

            if(flag){
                rightMax = max(rightMax,nums[i]);
            }

        }

        while(left< nums.size() && nums[left]<=leftMin){
            left++;
        }
        while(right>= 0 && nums[right]>=rightMax){
            right--;
        }

        return right-left >0 ? right-left+1:0;


    }
    int findUnsortedSubarray(vector<int>& nums) {
        return sortedSubArray(nums);
    }
};