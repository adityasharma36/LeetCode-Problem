class Solution {
public:
    void permutations(vector<int>& nums){
        int pivotIndex = -1;
        for(int i= nums.size()-2;i>=0;i--){
            if(nums[i]< nums[i+1]){
                pivotIndex = i;
                break;
            }
        }

        if(pivotIndex == -1){
            sort(nums.begin(),nums.end());
            return;
        }
        

        for(int i =nums.size()-1;i>pivotIndex;i--){
            if(nums[pivotIndex]< nums[i]){
                swap(nums[pivotIndex], nums[i]);
                break;
            }
        }
        int end = nums.size()-1;
        while(pivotIndex+1<end){
            swap(nums[pivotIndex+1],nums[end]);
            end--;
            pivotIndex++;
        }

        
    }
    void nextPermutation(vector<int>& nums) {
        permutations(nums);
        
    }
};