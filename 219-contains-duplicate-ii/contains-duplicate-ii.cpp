class Solution {
public:
    bool containDuplicate(vector<int>&nums,int k){
        unordered_map<int,int>um;

        for(int i = 0;i<nums.size();i++){
            int ch = nums[i];

            if((um.find(ch) != um.end()) && (abs(i-um[ch]) <=k)){
                return true;
            }else{
                um[ch]= i;
            }
        }
        return false;
    }
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        return containDuplicate(nums,k);
    }
};