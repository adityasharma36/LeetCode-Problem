class Solution {
public:
    vector<int>majorityEleFnc(vector<int>& nums){
        vector<int> ans;

        int firstEle = INT_MIN;
        int firstCnt = 0;

        int secondEle = INT_MIN;
        int secondCnt = 0;


        for(int i = 0;i<nums.size();i++){
            if(firstCnt == 0 && secondEle != nums[i]){
                firstEle = nums[i];
                firstCnt++;
            }else if(secondCnt == 0 && firstEle != nums[i]){
                secondEle = nums[i];
                secondCnt++;
            }
            else if(firstEle== nums[i]){
                firstCnt++;
            }else if(secondEle == nums[i]){
                secondCnt++;
            }else{
                firstCnt--;
                secondCnt--;
            }
        }

        firstCnt = 0;
        for(auto i:nums){
            if(firstEle == i){
                firstCnt++;
            }
        }

        secondCnt = 0;
        for(auto i:nums){
            if(secondEle == i){
                secondCnt++;
            }
        }
        if(firstCnt> nums.size()/3){
            ans.push_back(firstEle);
        }

         if(secondCnt> nums.size()/3){
            ans.push_back(secondEle);
        }
        return ans;
    }
    vector<int> majorityElement(vector<int>& nums) {
        return majorityEleFnc(nums);
    }
};