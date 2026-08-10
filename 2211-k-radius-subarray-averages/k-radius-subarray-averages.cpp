class Solution {
public:
    vector<int> averages(vector<int>& nums, int k) {
        int size = nums.size();
        int window = 2 * k + 1;

        vector<int> ans(size, -1);

        if (k == 0) return nums;
        if (size < window) return ans;

        long long sum = 0;

        // first window
        for (int i = 0; i < window; i++) {
            sum += nums[i];
        }

        ans[k] = sum / window;

        int start = 0;

        for (int end = window; end < size; end++) {
            sum -= nums[start++];
            sum += nums[end];

            ans[start + k] = sum / window;
        }

        return ans;
    }

    vector<int> getAverages(vector<int>& nums, int k) {
        return averages(nums, k);
    }
};