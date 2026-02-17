class Solution {
public:
    int majorityEleFnc(vector<int>& nums){
        int majorityEle = 0;
        int majorityCnt = 0;
        for(int i = 0;i<nums.size();i++){
            if(majorityCnt==0){
                majorityEle = nums[i];
                majorityCnt++;
            }else if(majorityEle != nums[i]){
                majorityCnt--;
            }else{
                majorityCnt++;
            }
        }
        return majorityEle ;
    }
    int majorityElement(vector<int>& nums) {
        return majorityEleFnc(nums);
    }
};