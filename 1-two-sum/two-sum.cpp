class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int,int> um;

        for(int i = 0;i<nums.size();i++){
            int ele = nums[i];
            int check = target - ele;
            if(um.find(check) != um.end()){
                return {um[check],i};
            }
            um[ele] = i;
        }
        return {-1,-1};
    }
};