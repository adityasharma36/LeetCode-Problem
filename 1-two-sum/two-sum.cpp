class Solution {
public:
    // vector<int> twoSums(vector<int>& nums, int target){
    //     for(int i = 0;i<nums.size();i++){
    //         for(int j = i+1;j<nums.size();j++){
    //             if(nums[i]+ nums[j] == target){
    //                 return {i,j};
    //             }
    //         }
    //     }
    //     return {-1,-1};
    // }

    vector<int> twoSums(vector<int>& nums, int target){

        unordered_map<int,int>um;

        for(int i = 0;i<nums.size();i++){
            int findVal = target-nums[i];

            if(um.find(findVal) != um.end()){
                int index = um[findVal];
                return {i,index};
            }

            um[nums[i]] = i;
        }
        return {-1,-1};
    }
    vector<int> twoSum(vector<int>& nums, int target) {

        vector<int> answer = twoSums(nums,target);
        
        return answer;
        
    }
};