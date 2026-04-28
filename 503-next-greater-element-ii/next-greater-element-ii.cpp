class Solution {
public:
    vector<int>bruteForce(vector<int>&nums){
        int n = nums.size();
        vector<int>ans(n,-1);

        for(int i = 0;i<n;i++){
            for(int j = 1;j<n;j++){
                int idx = (i+j) % n;
                if(nums[idx]> nums[i]){
                    ans[i]= nums[idx];
                    break;
                }
            }
        }
        return ans;
    }

    vector<int>optimiseSol(vector<int>&nums){

        int n = nums.size();
        stack<int>st;
        vector<int>ans(n);

        for(int i = 2*n-1;i>=0;i--){
            int curr = nums[i%n];

            while(!st.empty() && st.top()<=curr){
                st.pop();
            }

            if(i< n){
                if(st.empty()) ans[i]= -1;
                else ans[i]= st.top();
            }

            st.push(curr);
        }
    return ans;  

    }
    vector<int> nextGreaterElements(vector<int>& nums) {
        // return bruteForce(nums);
        return optimiseSol(nums);
    }
};