class Solution {
public:
    void sumCombination(vector<int>& cand,int target,vector<vector<int>>& ans,vector<int>&temp,int index){

        if(target==0){
            ans.push_back(temp);
            return;
        }

        for(int i = index;i<cand.size();i++){
            int coin = cand[i];
            if(coin<=target){
                temp.push_back(coin);
                sumCombination(cand,target-coin,ans,temp,i);
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        sumCombination(candidates,target,ans,temp,0);
        return ans;
    }
};