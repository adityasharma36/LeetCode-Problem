class Solution {

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
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<vector<int>>mt;

        int m = matrix.size();
        int n = matrix[0].size();

        for(int i = 0;i<m;i++){
            vector<int>temp;
            for(int j = 0;j<n;j++){
                temp.push_back(matrix[i][j]-'0');
            }
            mt.push_back(temp);
        }
        int ans = largestRectangleArea(mt[0]);

        for(int i = 1;i<m;i++){
            for(int j = 0;j<n;j++){
                if(matrix[i][j] == '1'){
                    mt[i][j]+=mt[i-1][j];
                }else{
                    mt[i][j]=0;
                }
            }
            ans = max(ans,largestRectangleArea(mt[i]));
        }
        return ans;
    }
};