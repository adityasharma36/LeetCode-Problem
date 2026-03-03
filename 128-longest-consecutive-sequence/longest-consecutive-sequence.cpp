class Solution {
public:
    int consecutiveFnc(vector<int>&nums){
        if(nums.empty()) return 0;
        sort(nums.begin(),nums.end());

        int longest = 1;
        int cnt = 1;
        for(int i = 1;i<nums.size();i++){
            if(nums[i-1]== nums[i]) continue;
            else if(nums[i-1]+1 == nums[i]) cnt++;
            else{
                longest = max(longest,cnt);
                cnt= 1;
            }
        }
        longest = max(longest,cnt);
        return longest;
    }

    int optimseFnc(vector<int>& nums){
        // unordered_map<int,int>um;
      unordered_set<int>st(nums.begin(),nums.end());

        int longestCon = 0;
        for(auto num: st){
            if(st.find(num-1) == st.end()){
                int current = num;
                int tempMax = 1;
                while( st.find(current+1) != st.end()){
                    current++;
                    tempMax++;
                }
                longestCon = max(longestCon,tempMax);
            }
        }
        return longestCon;
    }
    int longestConsecutive(vector<int>& nums) {
        // return consecutiveFnc(nums);
        return optimseFnc(nums);
    }
};