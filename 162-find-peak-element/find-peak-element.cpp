class Solution {
public:
    int bruteForce(vector<int>& nums){
        int len = nums.size()-1;

        if(nums.size() == 1) return 0;

        if(nums[0]> nums[1]) return 0;

        if(nums[len] > nums[len-1]) return len;

        for(int i = 1;i<nums.size()-1;i++){

            if((nums[i]>nums[i+1]) && (nums[i] > nums[i-1])){
                return i;
            }

        }
        return -1;
    }
    int findPeakEle(vector<int>& nums){
        int start = 1;
        int len = nums.size();
        int end = len-1;
        if(len == 1) return 0;
        if(nums[0]> nums[1]) return 0;
        if(nums[len-1]> nums[len-2]) return len-1;

        while(start<=end){
            int mid = start + (end-start)/2;
            if((nums[mid-1]< nums[mid]) && (nums[mid]> nums[mid + 1])) return mid;

            else if(nums[mid-1]< nums[mid]){
                start = mid + 1;
            }else{
                end = mid -1;
            }
        }
        return -1;
    }
    int findPeakElement(vector<int>& nums) {

        // int answer = bruteForce(nums);

        int answer = findPeakEle(nums);
        return answer;
    }
};