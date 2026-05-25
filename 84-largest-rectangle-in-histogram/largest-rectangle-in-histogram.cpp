class Solution {
public:
    void rightArea(vector<int>& arr,vector<int>& ans){
        stack<int>st;
        st.push(-1);

        int n = arr.size();
        for(int i = n-1;i>=0;i--){
            while(st.top()!=-1 && arr[st.top()]>=arr[i]){
                st.pop();
            }
            st.top() == -1 ? ans.push_back(n): ans.push_back(st.top());

            st.push(i);
        }
        reverse(ans.begin(),ans.end());
    }
    void leftArea(vector<int>& arr,vector<int>& ans){
        stack<int>st;
        st.push(-1);
        int n = arr.size();
        for(int i = 0;i<n;i++){
            while(st.top()!=-1 && arr[st.top()]>=arr[i]){

                st.pop();

            }
            ans.push_back(st.top());

            st.push(i);
        }
    }
    int rectangeArea(vector<int>& arr){
        vector<int>right;
        rightArea(arr,right);
        vector<int>left;
        leftArea(arr,left);

        int ans = 0;
        int n = arr.size();
        for(int i = 0;i<n;i++){
            int width = right[i]-left[i]-1;
            int area = width*arr[i];

            ans = max(ans,area); 
        }

        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        return rectangeArea(heights);
    }
};