class Solution {
public:
//  in---> inbuild fnc  
    // bool inbuildFnc(vector<int>& nums){
        
    //     sort(nums.begin(),nums.end());
    
    //     for(int i = 0;i<nums.size()-1;i++){
    //         if(nums[i]> nums[i+1]){
    //             return false;
    //         }
    //     }
    //     return true;
    
    // }
    void swappingFnc(vector<int>& nums,int start,int end){
        while(start<=end){
            swap(nums[start],nums[end]);
            start++;
            end--;
        }
    }

    bool swappingMth(vector<int>& nums){

        int swappingIndex = -1;
        for(int i = 1 ;i<nums.size();i++){
            if(nums[i] < nums[i-1]){
                swappingIndex = i;
                break;
            }
        }

        if(swappingIndex == -1){
            return true;
        }
        int swapingVal = swappingIndex % (nums.size());
        
        swappingFnc(nums,0, swapingVal-1);
        swappingFnc(nums,swapingVal,nums.size()-1);
        swappingFnc(nums,0,nums.size()-1);

          for(int i = 1 ;i<nums.size();i++){
            if(nums[i] < nums[i-1]){
                return false;
            }
        }
    return true;
    }
    bool check(vector<int>& nums) {
        // return inbuildFnc(nums);
        return swappingMth(nums);
    }
};