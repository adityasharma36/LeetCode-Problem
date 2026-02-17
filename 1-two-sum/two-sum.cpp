class Solution {
public:
    vector<int>twoSumFnc(vector<int>& nums,int target){
        unordered_map<int,int>um;
        for(int i = 0;i<nums.size();i++){
            int findVal = target- nums[i];
            if(um.find(findVal)!= um.end()){
                return {um[findVal],i};
            }
            um[nums[i]] = i;
        }
        return {-1,-1};
    }
    vector<int> twoSum(vector<int>& nums, int target) {
        return twoSumFnc(nums,target);
    }
};