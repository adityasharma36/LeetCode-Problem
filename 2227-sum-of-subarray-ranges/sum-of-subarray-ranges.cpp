class Solution {
public:
    void minLeftSide(vector<int>&nums,vector<int>&left){
        stack<int>st;
        st.push(-1);
        for(int i = 0;i<nums.size();i++){
            while(st.top()!=-1 && nums[st.top()]>nums[i]){
                st.pop();
            }
            left.push_back(st.top());
            st.push(i);
        }
    }
    void minRightSide(vector<int>&nums,vector<int>&right){
        stack<int>st;
        st.push(-1);
        int n = nums.size();
        for(int i = n-1;i>=0;i--){
            while(st.top()!=-1 && nums[st.top()]>=nums[i]){
                st.pop();
            }
            st.top()==-1 ? right.push_back(n):right.push_back(st.top());
            st.push(i);
        }
        reverse(right.begin(),right.end());
    }
    long long sumSubnumsayMin(vector<int>&nums){
        vector<int>left;
        vector<int>right;
        minLeftSide(nums,left);
        minRightSide(nums,right);

        long long ans = 0;
        for(int i = 0;i<nums.size();i++){
            long long leftLen= i-left[i];
            long long rightLen = right[i]-i;

            long long temp = leftLen* rightLen;
            long long sum = temp*nums[i];
            ans+=sum;
        }
        return ans;
    }
    void maxLeftSide(vector<int>&nums,vector<int>&left){
        stack<int>st;
        st.push(-1);
        for(int i = 0;i<nums.size();i++){
            while(st.top()!= -1 && nums[st.top()]<nums[i]){
                st.pop();
            }
            left.push_back(st.top());
            st.push(i);
        }
    }
    void maxRightSide(vector<int>&nums,vector<int>&right){
        stack<int>st;
        st.push(-1);
        int n = nums.size();
        for(int i = n-1;i>=0;i--){
            while(st.top()!=-1 && nums[st.top()]<=nums[i]){
                st.pop();
            }
            st.top()== -1 ? right.push_back(n): right.push_back(st.top());
            st.push(i);
        }
        reverse(right.begin(),right.end());
    }

    long long sumSubnumsayMax(vector<int>&nums){
        vector<int>left;
        vector<int>right;
        maxLeftSide(nums,left);
        maxRightSide(nums,right);

        long long ans = 0;
        for(int i = 0;i<nums.size();i++){
            long long leftLen= i-left[i];
            long long rightLen = right[i]-i;

            long long temp = leftLen* rightLen;
            long long sum = temp*nums[i];
            ans+=sum;
        }
        return ans;
    }
    long long subArrayRanges(vector<int>& nums) {
        long long ans =  sumSubnumsayMax(nums) - sumSubnumsayMin(nums);

        return ans;
    }
};