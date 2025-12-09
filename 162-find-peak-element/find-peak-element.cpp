
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int start = 0;
        int end = nums.size() - 1;

        while(start < end){
            int mid = start + (end - start) / 2;

            // if mid element is less than next element: peak is right side
            if(nums[mid] < nums[mid + 1]){
                start = mid + 1;
            } 
            // else peak is left side (including mid)
            else {
                end = mid;
            }
        }

        return start; // or end (both same)
    }
};


