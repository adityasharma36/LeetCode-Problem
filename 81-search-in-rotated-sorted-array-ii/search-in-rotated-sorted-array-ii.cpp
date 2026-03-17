class Solution {
public:
    bool isElePresent(vector<int>& nums,int target){
        int start = 0;
        int end = nums.size()-1;

        while(start <= end){
            int mid = (end-start)/2 + start;

            if(nums[mid] == target) return true;

            // handle duplicates
            if(nums[start] == nums[mid] && nums[mid] == nums[end]){
                start++;
                end--;
                continue;
            }

            // left sorted
            if(nums[start] <= nums[mid]){
                if(nums[start] <= target && target < nums[mid]){
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            }
            // right sorted
            else{
                if(nums[mid] < target && target <= nums[end]){
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }
        return false;
    }

    bool search(vector<int>& nums, int target) {
        return isElePresent(nums, target);
    }
};