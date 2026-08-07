class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = INT_MAX;
        int n = nums.size();
        int i = 0;
        int j = 0;
        int total = 0;
        while(j<n){
            total+=nums[j];
            while(total>=target){
                sum = min(j-i+1,sum);
                total-=nums[i];
                i++;
                
            }
            j++;
        }
       
        if(sum != INT_MAX) return sum;
        return 0;
    }
 };