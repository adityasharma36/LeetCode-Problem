class Solution {
public:
    int solveByRec(vector<int>& nums,int i ,int mini ){
        if(i>= nums.size()) return 0;
        int profit = nums[i]- mini;

        mini = min(nums[i],mini);
        int excl = solveByRec(nums,i+1,mini);

        return max(profit,excl);
    }
    int maxProfit(vector<int>& prices) {
        int ans = solveByRec(prices,1,prices[0]);
        return ans;
    }
};