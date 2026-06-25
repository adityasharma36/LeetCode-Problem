class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int cnt = 0;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            int temp = 0;
            for(int j = i;j<n;j++){
                if(nums[j]== target){
                    temp++;
                }else{
                    temp--;
                }
            if(temp>0) cnt++;
            }
        }
        return cnt;
    }
};