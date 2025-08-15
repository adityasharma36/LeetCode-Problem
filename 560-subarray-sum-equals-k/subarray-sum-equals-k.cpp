class Solution {
public:
    int sumSubarray(vector<int>& nums,int k){
        unordered_map<int,int>um;
        int sum = 0;
        int count = 0;
        um[0] = 1;
        for(int i = 0;i<nums.size();i++){
            sum+=nums[i];
            int diff = sum-k;
           

            if(um.find(diff)!= um.end()){
                count+=um[diff];
            }
           um[sum]++;
        }
        return count;
    }
    int subarraySum(vector<int>& nums, int k) {
        int answer =  sumSubarray(nums,k);
        return answer;
    }
};