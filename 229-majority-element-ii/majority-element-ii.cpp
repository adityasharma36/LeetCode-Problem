class Solution {
public:
    vector<int> majorityEle(vector<int>& nums){
        int cnt1 = 0;
        int cnt2 = 0;
        int ele1 = 0;
        int ele2 = 0;

        for(int i = 0;i<nums.size();i++){
            if(cnt1 == 0 && nums[i] != ele2){
                cnt1 = 1;
                ele1 = nums[i];
            }
            else if(cnt2 == 0 && nums[i] != ele1){
                cnt2 = 1;
                ele2 = nums[i];
            }
            else if(nums[i]==ele1){
                cnt1++;
            }
            else if(nums[i]==ele2){
                cnt2++;
            }else{
                cnt1--;
                cnt2--;
            }
        }
        cnt1 = 0;
        cnt2 = 0;
        for(int i = 0;i<nums.size();i++){
            if(ele1 == nums[i]) cnt1++;
            else if(ele2 == nums[i]) cnt2++;
        }
        int len = nums.size()/3;
        vector<int> answer;
        if(cnt1> len) answer.push_back(ele1);
        if(cnt2> len) answer.push_back(ele2);
        return answer;
    }
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> answer = majorityEle(nums);
        return answer;
    }
};