class Solution {
public:
    void leftSideRec(vector<int>&heights,vector<int>&leftSide){

        stack<int>st;
        st.push(-1);
        for(int i = 0;i<heights.size();i++){

            while(st.top()!= -1 && heights[st.top()]>=heights[i]){

                st.pop();

            }

            leftSide.push_back(st.top());

            st.push(i);
        }

    }
    void rightSideRec(vector<int>&heights,vector<int>&rightSide){
        stack<int>st;
        st.push(-1);
        int n = heights.size();
        for(int i = n-1;i>=0;i-- ){

            while(st.top()!=-1 && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.top()==-1){
                rightSide.push_back(n);
            }else{
                rightSide.push_back(st.top());
            }

            st.push(i);
        }
        reverse(rightSide.begin(),rightSide.end());
    }

    int largestRectangleArea(vector<int>& heights) {
        vector<int>leftSide;
        vector<int>rightSide;
        leftSideRec(heights,leftSide);

        for(auto i: leftSide){
            cout<<i<<" ";
        }
        cout<<endl;
        rightSideRec(heights,rightSide);

        for(auto i: rightSide){
            cout<<i<<" ";
        }
        cout<<endl;

        int answer = INT_MIN;

        for(int i = 0;i<heights.size();i++){
            int width = rightSide[i]-leftSide[i]-1;
            int height = heights[i];
            int area = width*height;
            answer = max(area,answer);
        }

    
        return answer;
    }
};