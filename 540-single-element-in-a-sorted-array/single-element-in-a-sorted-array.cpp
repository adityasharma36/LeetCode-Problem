class Solution {
public:
    int singleEle(vector<int>& nums){
        int start = 1;
        int len = nums.size();
        int end = len-2;

        if(len == 1) return nums[0];

        if(nums[0]!= nums[start]) return nums[0];
        if(nums[len-1]!= nums[end]) return nums[len-1];

        while(start<=end){
            int mid = (end-start)/2 + start;

            if((nums[mid] != nums[mid-1]) && (nums[mid] != nums[mid+1])) return nums[mid];


            if((mid % 2 == 1 && nums[mid] == nums[mid-1] ) ||  (mid %2 == 0 && nums[mid] ==nums[mid+1])){
                start = mid+1;
            }else{
                end = mid-1;
            }
        }
        return -1;
    }
    int singleNonDuplicate(vector<int>& nums) {
        return singleEle(nums);
    }
};