class Solution {
public:
    // void permutation(vector<int>& nums,vector<vector<int>>& answer,int i){
    //     if(i>= nums.size()){
    //         answer.push_back(nums);
    //         return;
    //     }

    //     for(int j = i;j<nums.size();j++){
    //         if(j>i && nums[j] == nums[j-1]) continue;

    //         swap(nums[i],nums[j]);
    //         permutation(nums,answer,i+1);
    //         swap(nums[i],nums[j]);
    //     }

    // }

    void permutation(vector<int>& nums,vector<vector<int>>& answer,int i){
        if(i>= nums.size()){
            answer.push_back(nums);
            return;
        }
        unordered_set<int>check;
        for(int j = i;j<nums.size();j++){

            if(check.count(nums[j])) continue;

            check.insert(nums[j]);
            swap(nums[i],nums[j]);
            permutation(nums,answer,i+1);
            swap(nums[i],nums[j]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>answer;
        sort(nums.begin(),nums.end());
        permutation(nums,answer,0);
        return answer;
    }
};