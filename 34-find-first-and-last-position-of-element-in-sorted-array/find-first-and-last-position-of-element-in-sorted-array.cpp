class Solution {
public:
    int firstPos(vector<int>& nums,int target){
        int start = 0;
        int end = nums.size()-1;
        int index =-1;
        while(start<=end){
            int mid = start + (end-start)/2 ;
            if(nums[mid]== target){
                index = mid;
                end = mid -1;
            }else if(nums[mid]> target){
                end = mid -1;
            }else{
                start = mid+1;
            }

        }
        return index;
    }
    int lastPos(vector<int>& nums,int target){
        int start = 0;
        int end = nums.size()-1;
        int index = -1;
        while(start<=end){
            int mid = start + (end-start)/2;
            if(nums[mid]== target){
                index = mid;
                start = mid +1;
            }else if(nums[mid] > target){
                end = mid-1;
            }else{
                start = mid +1;
            }
        }
        return index;
    }
    vector<int> firAndLastPos(vector<int>& nums,int target){
        int first = firstPos(nums,target);
        int last = lastPos(nums,target);
        return {first,last};
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> answer = firAndLastPos(nums,target);
        return answer;
    }
};