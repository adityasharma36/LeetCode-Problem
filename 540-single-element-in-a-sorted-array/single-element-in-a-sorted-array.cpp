class Solution {
public:

    int findSingleByMap(vector<int>& nums){
        unordered_map<int,int> um;
        for(int i = 0;i<nums.size();i++){
            um[nums[i]]++;
        }
        for(auto & mapping : um){
        
            if(mapping.second == 1){
                return mapping.first;
            }
        }
        return -1;
    }


    int singleNonDuplicate(vector<int>& nums) {
        int answer = findSingleByMap(nums);
        return answer;
    }
};