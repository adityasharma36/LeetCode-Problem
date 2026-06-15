class Solution {
public:
    void leftWidth(vector<int>&h,vector<int>& l){
        stack<int>st;
        st.push(-1);
        int n = h.size();
        for(int i = 0;i<n;i++){
            while(st.top() != -1 && h[st.top()]>=h[i]){
                st.pop();
            }
            l.push_back(st.top());
            st.push(i);
        }
    }
    void rightWidth(vector<int>&h,vector<int>& r){
        stack<int>st;
        st.push(-1);
        int n = h.size();
        for(int i = n-1;i>=0;i--){
            while(st.top() != -1 && h[st.top()] >= h[i]){
                st.pop();
            }
            st.top() == -1 ? r.push_back(n) : r.push_back(st.top());
            st.push(i);
        }
        reverse(r.begin(),r.end());
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int>left;
        vector<int>right;

        leftWidth(heights,left);
        rightWidth(heights,right);
        long long ans = INT_MIN;
        for(int i = 0;i<heights.size();i++){
            int wid = right[i]-left[i]-1;
            int height = heights[i];
            long long area = wid* height;
            ans = max(ans,area);
        }
        return (int)ans;
    }
};