class Solution {
public:
    void subSet2(vector<int>& nums,vector<vector<int>>& sub,vector<int> & subSet,int index){
        if(index == nums.size()) {
            sub.push_back(subSet);
            return;
        }


        subSet.push_back(nums[index]);
        subSet2(nums,sub,subSet,index+1);
        subSet.pop_back();

        int nextIndex = index + 1;
        while (nextIndex < nums.size() && nums[nextIndex] == nums[index]) {
            nextIndex++;
        }
        subSet2(nums,sub,subSet,nextIndex);
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> sub;
        vector<int>subSet;
        sort(nums.begin(),nums.end());
        subSet2(nums,sub,subSet,0);
        return sub;
    }
};