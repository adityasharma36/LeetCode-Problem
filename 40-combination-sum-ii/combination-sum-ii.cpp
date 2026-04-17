class Solution {
public:
    void sumCombination(vector<int>& candi, int target, vector<int>& temp,
                        int i, vector<vector<int>>& ans) {

        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        for (int j = i; j < candi.size(); j++) {

            // ✅ correct duplicate handling
            if (j > i && candi[j] == candi[j - 1]) continue;

            int sum = candi[j];

            if (target - sum >= 0) {

                temp.push_back(sum);

                sumCombination(candi, target - sum, temp, j + 1, ans);

                temp.pop_back();
            } else {
                break; // 🔥 optimization since array is sorted
            }
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin(), candidates.end());

        vector<vector<int>> ans;
        vector<int> temp;

        sumCombination(candidates, target, temp, 0, ans);

        return ans;
    }
};