class Solution {
public:
    void prevGreEle(vector<int>& heights,vector<int>&prevAns){
        stack<int>st;
        st.push(-1);
        for(int i = 0;i<heights.size();i++){
            int element = heights[i];
            while(st.top() != -1 && heights[st.top()] >=element){
                st.pop();
            }
            prevAns.push_back(st.top());
            st.push(i);
        }
    }
    void nextGreEle(vector<int>& heights,vector<int>&nextAns){
        stack<int>st;
        st.push(-1);
        for(int i = heights.size()-1;i>=0;i--){
            int element = heights[i];
            while(st.top() != -1 && heights[st.top()] >=element){
                st.pop();
            }
            nextAns.push_back(st.top());
            st.push(i);
        }
    }
    int largestRectangleArea(vector<int>& heights) {

        vector<int>nextAns;
        vector<int>prevAns;

        prevGreEle(heights,prevAns);
        nextGreEle(heights,nextAns);

        reverse(nextAns.begin(),nextAns.end());

        // ek extra case karna h jab -1 hai nextGreEle me to uska mtlb hai "array size"

        for(int i = 0;i<nextAns.size();i++){
            if(nextAns[i]== -1){
                nextAns[i] = nextAns.size();
            }
        }
        vector<int> maxAns;

        for(int i = 0;i<heights.size();i++){
            int width = nextAns[i]- prevAns[i]-1;
            int height = heights[i];

            int area = width * height;

            maxAns.push_back(area);
        }
        int largestRec = INT_MIN;

        for(int i = 0;i<maxAns.size();i++){
            largestRec = max(largestRec,maxAns[i]);
        }

        return largestRec;
    }
};