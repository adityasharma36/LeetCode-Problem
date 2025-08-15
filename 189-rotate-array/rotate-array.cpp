class Solution {
public:
    void swapArray( int start ,int end ,vector<int>& nums){
        while(start<end){
            swap(nums[start],nums[end]);
            start++;
            end--;
        }
    }
    void rotateArray(vector<int>& nums,int k){
        int start =  0;
        int end = nums.size()-1;
        swapArray(start,end , nums);

        int kRotate = k % nums.size();

        swapArray(start,kRotate-1,nums);

        swapArray(kRotate,end,nums);
    }
    void rotate(vector<int>& nums, int k) {
        rotateArray(nums,k);
    }
};