class Solution {
public:
    // int houseRobber(vector<int>& nums,int index,vector<int>& ans){
    //     if(index >=nums.size()){
    //          return 0;
    //     }

    //     int include  = nums[index] + houseRobber(nums,index+2);
    //     int exclude = 0 + houseRobber(nums,index+1);

    //     return max(include,exclude);
    // }
    // int houseRobberByMemo(vector<int>& nums,int index,vector<int>& ans){
    //     if(index >=nums.size()){
    //          return 0;
    //     }

    //     if(ans[index] != 0){
    //         return ans[index];
    //     }

        // int include  = nums[index] + houseRobberByMemo(nums,index+2,ans);
        // int exclude = 0 + houseRobberByMemo(nums,index+1,ans);

        // ans[index]= max(include,exclude);
    //     return ans[index];
    // }

    int houseRobberByTab(vector<int>& nums){
        vector<int> ans(nums.size()+2,0);

        for(int i = nums.size()-1;i>=0;i--){
             int include  = nums[i] + ans[i+2];
            int exclude = 0 + ans[i+1];

            ans[i]= max(include,exclude);
        }
        return ans[0];
    }
    int rob(vector<int>& nums) {

        vector<int> ans(nums.size()+1,0);
        // int answer = houseRobberByMemo(nums,0,ans);
        int answer = houseRobberByTab(nums);
        return answer;
    }
};