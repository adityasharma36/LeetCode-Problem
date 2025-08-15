class Solution {
public:
    int majorityEle(vector<int>& nums){
        int ele = 0;
        int count = 0;
        for(int i = 0;i<nums.size();i++){
            if(count == 0 ){
                ele = nums[i];
                count = 1;
            }else if(ele == nums[i]){
                count++;
            }
            else {
                count--;
            }
        }
        count = 0;
        for(int i = 0;i<nums.size();i++){
            if(ele == nums[i]){
                count++;
            }
        }
        int len = nums.size()/2;
        if(count>=len) return ele;

        return -1;
    }
    int majorityElement(vector<int>& nums) {
        int answer = majorityEle(nums);
        return answer;
    }
};