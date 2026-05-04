class Solution {
public:
    int MOD = 1e9 + 7;
    int bruteForce(vector<int>&arr){
        long long sum = 0;
        for(int i = 0;i<arr.size();i++){
            int temp = arr[i];
            for(int j = i;j<arr.size();j++){
                temp = min(temp,arr[j]);
                sum = (sum+temp) % MOD;
            }
        }
        return (int)sum;
    }
        void leftSide(vector<int>& arr, vector<int>& leftRange) {

        stack<int> st;

        for(int i = 0; i < arr.size(); i++) {

            while(!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }

            leftRange[i] = st.empty() ? -1 : st.top();

            st.push(i);
        }
    }

    void rightSide(vector<int>& arr, vector<int>& rightRange) {

        stack<int> st;

        for(int i = arr.size() - 1; i >= 0; i--) {

            while(!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            rightRange[i] = st.empty() ? arr.size() : st.top();

            st.push(i);
        }
    }

    int optimiseSol(vector<int>& arr) {

        int n = arr.size();

        vector<int> leftRange(n);
        vector<int> rightRange(n);

        leftSide(arr, leftRange);
        rightSide(arr, rightRange);

        long long sum = 0;

        for(int i = 0; i < n; i++) {

            long long leftCount = i - leftRange[i];
            long long rightCount = rightRange[i] - i;

            long long totalSubarrays =
                (leftCount * rightCount) % MOD;

            sum = (sum + (totalSubarrays * arr[i]) % MOD) % MOD;
        }

        return (int)sum;
    }
    int sumSubarrayMins(vector<int>& arr) {
        // return bruteForce(arr);
        return optimiseSol(arr);
    }
};