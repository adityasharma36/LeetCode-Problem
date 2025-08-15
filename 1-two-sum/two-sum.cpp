class Solution {
public:
    vector<int> sumTwo(vector<int>& nums,int target){
        // int sum = 0;
        unordered_map<int,int> um;
        for(int i = 0;i<nums.size();i++){
            int ele = nums[i];
            int diff = target- ele;
            if(um.find(diff) != um.end()){
                int index = um[diff];
                return {i,index};
            }
            um[ele]= i;
        }
        return {-1,-1};
    }
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> answer = sumTwo(nums,target);
        return answer;
    }
};