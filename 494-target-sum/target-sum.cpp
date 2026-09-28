class Solution {
public:
    int solveByRec(vector<int>& nums,int target,int i){
        if(i>= nums.size() ) return target ==0 ? 1:0;
        int opt1 = solveByRec(nums,target-nums[i],i+1);
        int opt2 =  solveByRec(nums,target+nums[i],i+1);

        return opt1+ opt2;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        
        int ans = solveByRec(nums,target,0);
        return ans;
    }
};