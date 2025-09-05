class Solution {
public:
    void permutation(vector<int> nums,vector<vector<int>>& answer,int i ){
        if(i>=nums.size()){
            answer.push_back(nums);
            return;
        }

        for(int j = i;j<nums.size();j++){
            swap(nums[i],nums[j]);

            permutation(nums,answer,i+1);

            swap(nums[i],nums[j]);
        }

    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>answer;
        // vector<int>ans;
    
            
            permutation(nums,answer,0);

        return answer;
    }
};