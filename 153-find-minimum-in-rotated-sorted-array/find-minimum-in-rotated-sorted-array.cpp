class Solution {
public:
    int minInRotatedArr(vector<int>& nums){
        int start = 0;
        int end = nums.size()-1;
        int answer = INT_MAX;
        while(start<=end){
            int mid = start + (end-start)/2;
            if(nums[mid]<= nums[end]){
                answer  = min(answer,nums[mid]);
                end = mid-1;
            }
            else {
                answer = min(answer , nums[start]);
                start = mid + 1;
            }
        }
        return answer;
    }
    int findMin(vector<int>& nums) {
        int answer = minInRotatedArr(nums);
        return answer;
    }
};