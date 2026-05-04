class Solution {
public:
    void leftTrap(vector<int>& hei, vector<int>& left) {
        stack<int> st;
        st.push(-1);

        for (int i = 0; i < hei.size(); i++) {

            while (st.top() != -1 && hei[st.top()] <= hei[i]) {
                st.pop();
            }

            left.push_back(st.top());
            st.push(i);
        }
    }

    void rightTrap(vector<int>& hei, vector<int>& right) {
        stack<int> st;
        st.push(-1);

        for (int i = hei.size() - 1; i >= 0; i--) {

            while (st.top() != -1 && hei[st.top()] <= hei[i]) {
                st.pop();
            }

            right.push_back(st.top());
            st.push(i);
        }

        reverse(right.begin(), right.end());
    }
    int bruteForce(vector<int>&height){
        int n = height.size();

        vector<int> leftheight;
        vector<int> rightHeight;

        leftTrap(height, leftheight);
        rightTrap(height, rightHeight);

        // Replace -1 values
        for (int i = 0; i < n; i++) {
            if (leftheight[i] == -1) {
                leftheight[i] = i;
            }

            if (rightHeight[i] == -1) {
                rightHeight[i] = i;
            }
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {

            int leftMax = height[leftheight[i]];
            int rightMax = height[rightHeight[i]];

            int waterLevel = min(leftMax, rightMax);

            if (waterLevel > height[i]) {
                ans += waterLevel - height[i];
            }
        }

        return ans;
    }
    int littleOptimise(vector<int>&height){
        int n = height.size();
        vector<int>leftPrefix(n);
        leftPrefix[0]= height[0];
        for(int i = 1;i<height.size();i++){
            int maxEle = max(height[i],leftPrefix[i-1]);
            leftPrefix[i]= maxEle;
        }

        vector<int>suffixSum(n);
        
        suffixSum[n-1] = height[n-1];
        for(int i =n-2 ;i>=0;i--){
            int maxEle = max(height[i],suffixSum[i+1]);
            suffixSum[i]= maxEle;
        }
        int total = 0;
        for(int i = 0;i<n;i++){
            int leftMax = leftPrefix[i];
            int rightMax = suffixSum[i];

            if(height[i]<leftMax && height[i]< rightMax){
                total+=min(leftMax,rightMax)-height[i];
            }
        }
        return total;
    }
    int trap(vector<int>& height) {

        // return bruteForce(height);
        return littleOptimise(height);
    }
};