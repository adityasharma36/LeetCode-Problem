class Solution {
public:
    void putAllSubSets(vector<int>& nums,int index,vector<vector<int>>& answer,vector<int>& temp){
        if(index == nums.size()){
            answer.push_back(temp);
            return;
        }
        temp.push_back(nums[index]);
        putAllSubSets(nums,index+1,answer,temp);

        temp.pop_back();
        putAllSubSets(nums,index+1,answer,temp);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
     vector<vector<int>> answer;
     vector<int> temp;
     putAllSubSets(nums,0,answer,temp);
     return answer;   
    }
};