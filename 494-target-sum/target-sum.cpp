class Solution {
public:
    int solveByRec(vector<int>& nums,int target,int i){
        if(i>= nums.size() ) return target ==0 ? 1:0;
        int opt1 = solveByRec(nums,target-nums[i],i+1);
        int opt2 =  solveByRec(nums,target+nums[i],i+1);

        return opt1+ opt2;
    }
    int solveByMemo(vector<int>& nums,int target,int i,map<pair<int,int>,int>&mp){
        if(i>= nums.size()) return target == 0 ? 1: 0;
        if(mp.find({target,i}) != mp.end()) return mp[{target,i}];

        int op1 = solveByMemo(nums,target-nums[i],i+1,mp);
        int op2 = solveByMemo(nums,target+nums[i],i+1,mp);
        int index = op1 + op2;

        return mp[{target,i}]= index;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        
        // int ans = solveByRec(nums,target,0);
        map<pair<int,int>,int>mp;
        int ans = solveByMemo(nums,target,0,mp);
        return ans;
    }
};