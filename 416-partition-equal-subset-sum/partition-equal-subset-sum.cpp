class Solution {
public:
    bool partitionEqualSubSet(vector<int>& nums,int target,int index){
        if(target<0 || index == nums.size()) return false;
        if(target == 0) return true;

        int incld = partitionEqualSubSet(nums,target-nums[index],index+1);
        int excld = partitionEqualSubSet(nums,target,index+1);

        return incld || excld;
    }

    bool partitionEqualSubSetByMemo(vector<int>& nums,int target,int index,vector<vector<int>>& ans){
         if(target<0 || index == nums.size()) return false;
        if(target == 0) return true;

        if(ans[index][target] != -1) return ans[index][target];
        int incld = partitionEqualSubSetByMemo(nums,target-nums[index],index+1,ans);
        int excld = partitionEqualSubSetByMemo(nums,target,index+1,ans);

        ans[index][target] = incld || excld;
        return ans[index][target];
    }
    bool canPartition(vector<int>& nums) {

        int sums  = accumulate(nums.begin(),nums.end(),0);
        int  target = sums /2;

        if(sums %2 != 0){
            return false;
        }
        vector<vector<int>>ans(nums.size()+1 , vector<int>(target+1,-1));
        return partitionEqualSubSetByMemo(nums,target,0,ans);
    }
};