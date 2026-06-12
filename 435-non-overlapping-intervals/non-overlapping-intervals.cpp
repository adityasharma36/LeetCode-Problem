class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(begin(intervals),end(intervals));
        int cnt = 0;
        int currSt = intervals[0][0];
        int currEnd = intervals[0][1];

        for(int i = 1;i<n;i++){
            if(currEnd<=intervals[i][0]){
                currSt = intervals[i][0];
                currEnd = intervals[i][1];
            }else{
                if(currEnd<= intervals[i][1]){
                    cnt++;
                }else{
                    cnt++;
                    currSt = intervals[i][0];
                    currEnd = intervals[i][1];
                }
            }
        }
        return cnt;
    }
};