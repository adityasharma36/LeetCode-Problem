class Solution {
public:
    int solve(vector<int>&nums,int start,int end){
        if(start>end) return 0;

        int choseStart = nums[start] + min(solve(nums,start+2,end),solve(nums,start+1,end-1));
        int choseEnd = nums[end] + min(solve(nums,start+1,end-1),solve(nums,start,end-2));

        return max(choseStart,choseEnd);
    }
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        int player1 = solve(nums,0,n-1);
        int totalSum = accumulate(nums.begin(),nums.end(),0);
        int player2 = totalSum - player1;

        if(player1>=player2) return true;
        return false;
    }
};