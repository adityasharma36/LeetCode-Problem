class Solution {
public:
    int duplicateRemove(vector<int>& nums){
        int start= 0;
        int mid = 1;
        int cnt = 1;
        while(mid<nums.size()){
            if(nums[start]== nums[mid]){
                cnt++;
                if(cnt<=2){
                    start++;
                     nums[start]= nums[mid];
                }
            }else{
                cnt = 1;
                start++;
                nums[start]= nums[mid];
            }
            mid++;
        }
        return start+1;
    }
    int removeDuplicates(vector<int>& nums) {
        return duplicateRemove(nums);
    }
};