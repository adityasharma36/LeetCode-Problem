class Solution {
public:
    void sumCombination(vector<int>& candidates, int target, 
                        vector<vector<int>>& ans,
                        vector<int>& temp, int i) {

        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        for (int j = i; j < candidates.size(); j++) {
            if (target - candidates[j] >= 0) {
                temp.push_back(candidates[j]);

                sumCombination(candidates, target - candidates[j], ans, temp, j);

                temp.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;

        sumCombination(candidates, target, ans, temp, 0);

        return ans;
    }
};