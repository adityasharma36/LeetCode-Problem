class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;
        int minEle = INT_MAX;
        int maxEle = INT_MIN;
        int n = nums.size();

        bool flag = false;
        for(int i= 1;i<nums.size();i++){
            if(nums[i]< nums[i-1]){
                flag = true;
            }
            if(flag){
            minEle = min(nums[i],minEle);
        }
        }

        flag = false;

        for(int i= nums.size()-2;i>=0;i--){
            if(nums[i]>nums[i+1]){
                flag = true;
            }
            if(flag){
                maxEle = max(nums[i],maxEle);
            }
        }

           while(left < n && nums[left] <= minEle){
            left++;
        }

        // find correct right boundary
        while(right >= 0 && nums[right] >= maxEle){
            right--;
        }

        return right-left> 0 ? right-left+1: 0;
    }
};