class Solution {
public:
    vector<int> kFrequent(vector<int>& nums,int k){
        unordered_map<int,int> um;
        for(auto i: nums){
            um[i]++;
        }
        priority_queue<pair<int,int>> pq;
        for(const auto & i : um){
            pq.push({i.second,i.first});
        }
        vector<int> ans;
        while(k--){
            auto [frq,val]= pq.top();
            pq.pop();
            ans.push_back(val);
        }
        return ans;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        return kFrequent(nums,k);
    }
};