class Solution {
public:
    void swappingFnc(vector<int>& nums,int start,int end){
        while(start<=end){
            swap(nums[start],nums[end]);
            start++;
            end--;
        }
    }
    void rotationFnc(vector<int>& nums,int k){
        int swapingIndex = k% nums.size();

        swappingFnc(nums,0,nums.size()-1);
        swappingFnc(nums,0,swapingIndex-1);
        swappingFnc(nums,swapingIndex,nums.size()-1);
    }
    void rotate(vector<int>& nums, int k) {
        rotationFnc(nums,k);
    }
};