class Solution {
public:
    int twoSliding(vector<int>& nums){
         int i = 0;
        int j = 0;
        int size = nums.size();
        int ans = 0;
        int countZero = 0;
        while(j<size){
           if(nums[j]==0){
            countZero++;
           }
           while(countZero>1){
            if(nums[i]==0){
                countZero--;
            }
            i++;
           }
           ans = max(ans,j-i);
            j++;
        }
     
      
        return ans;
    }
    int oneSliding(vector<int>& nums){
        int i = 0;
        int j = 0;
        int size = nums.size();
        int oneIndex = -1;
        int ans = 0;
        while(j<size){
            if(nums[j]==0 && oneIndex != -1){
                i = oneIndex+1;
            }
            if(nums[j]==0){
                oneIndex = j;
            }
            ans = max(ans,j-i);
            j++;
        }
        return ans;
        }
    int longestSubarray(vector<int>& nums) {
    //    return twoSliding(nums);
        return oneSliding(nums);
    }
};