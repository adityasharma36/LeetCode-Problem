class Solution {
public:
    int duplicateFromSorted(vector<int>& nums){
        int start = 0;
        int mid = 1;

        while(nums.size()> mid){
            if(nums[start] != nums[mid]){
            
                 start++;
                swap(nums[start],nums[mid]);
            }
            mid++;
        }
        return start +1;
    }
    int removeDuplicates(vector<int>& nums) {
        int answer = duplicateFromSorted(nums);
        return answer;
        
        
    }
};