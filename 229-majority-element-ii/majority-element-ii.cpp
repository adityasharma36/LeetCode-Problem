class Solution {
public:
    vector<int> findMajority(vector<int>& nums){

        // sort(nums.begin(),nums.end());

        unordered_map<int,int> um;

        for(auto num : nums){
            um[num]++;
        }

        vector<int> ans;
        int len = nums.size();
        int maxCount = len / 3 + 1;

        for(auto &p : um){

            int count = p.second;

            if(count>= maxCount){
                ans.push_back(p.first);
            }
        

        }

        return ans;

    }
    vector<int> codeOptimise(vector<int>& nums){
        int cnt1 = 0;
        int cnt2 = 0;
        int ele1 = INT_MIN;
        int ele2 = INT_MIN;
        for(int i = 0;i<nums.size();i++){
            if(cnt1 == 0 && ele2 != nums[i]){
                cnt1 = 1;
                ele1 = nums[i];
            }
            else if(cnt2 == 0 && ele1 != nums[i]){
                cnt2 = 1;
                ele2 = nums[i];
            }
            else if(nums[i] == ele1){
                cnt1++;
            }
            else if(nums[i] == ele2){
                cnt2++;
            }
            else {
                cnt1--;
                cnt2--;

            }
        }

        cnt1 = 0;
        cnt2 = 0;
        for(int i = 0;i<nums.size();i++){
            if(nums[i]== ele1) cnt1++;
            else if(nums[i]== ele2) cnt2++;
        }
        vector<int>ans;
        int len = nums.size();
        int maxLen= len/3 + 1;
        if(cnt1 >= maxLen) ans.push_back(ele1);
        if(cnt2 >= maxLen) ans.push_back(ele2);

        return ans;
    }
    vector<int> majorityElement(vector<int>& nums) {
        // vector<int> ans = findMajority(nums);

        vector<int> ans = codeOptimise(nums);
        return ans;
    }
};