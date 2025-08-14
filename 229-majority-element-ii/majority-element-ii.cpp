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
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans = findMajority(nums);
        return ans;
    }
};