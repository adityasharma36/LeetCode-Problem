class Solution {
public:
    void comboSum(int k, int n, int start, vector<int>& current, vector<vector<int>>& result) {
        if (k == 0 && n == 0) {
            result.push_back(current);
            return;
        }
        if (k == 0 || n <= 0) return;

        for (int i = start; i <= 9; i++) {
            current.push_back(i);
            comboSum(k - 1, n - i, i + 1, current, result);
            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> current;
        comboSum(k, n, 1, current, result);
        return result;
    }
};
