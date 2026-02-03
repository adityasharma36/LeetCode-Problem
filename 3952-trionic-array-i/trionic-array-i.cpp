class Solution {
public:
    bool isTrionic(vector<int>& nums, int k = 3) {
        // At beginning nums should be increasing
        if (nums[0] >= nums[1])
            return false;

        int n = nums.size();

        int sign = 1, switches = 0;
        for (int i = 1; i < n; ++i) {
            int delta = nums[i] - nums[i - 1];
            if (delta == 0)  // Delta should be always decreasing or increasing
                return false;
            else if (delta * sign < 0) {  // Switch point detected
                sign *= -1;
                switches += 1;
            }
        }

        return switches == k - 1;
    }
};