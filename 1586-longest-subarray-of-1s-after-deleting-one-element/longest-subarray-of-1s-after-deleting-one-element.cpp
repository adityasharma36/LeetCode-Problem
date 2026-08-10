class Solution {
public:
    int longestSubarray(vector<int>& nums) {
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
     
        if(countZero ==0) return ans;
        return ans;
    }
};