class Solution {
public:
    void allSubSets(vector<int>& nums,vector<vector<int>>& ans,vector<int>& temp,int i){
        if(i>=nums.size()){
            ans.push_back(temp);
            return;
        }

        int ele = nums[i];
        temp.push_back(ele);
        allSubSets(nums,ans,temp,i+1);
        temp.pop_back();
        allSubSets(nums,ans,temp,i+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int>temp;
        int i = 0;
        allSubSets(nums,ans,temp,i);
        return ans;
    }
};