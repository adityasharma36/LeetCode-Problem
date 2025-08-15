class Solution {
public:
    bool sortedAndRotated(vector<int>& nums) {
        int n = nums.size();
        int pivotIndex = -1;

        // Find first drop
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                pivotIndex = i;
                break;
            }
        }

        // If no drop found, array is already sorted
        if (pivotIndex == -1) return true;

        // Check first part before pivot
        for (int i = 0; i < pivotIndex; i++) {
            if (nums[i] > nums[i + 1]) return false;
        }

        // Check second part after pivot
        for (int i = pivotIndex + 1; i < n - 1; i++) {
            if (nums[i] > nums[i + 1]) return false;
        }

        // Last element should be <= first element for rotation
        return nums[n - 1] <= nums[0];
    }

    bool check(vector<int>& nums) {
        return sortedAndRotated(nums);
    }
};
