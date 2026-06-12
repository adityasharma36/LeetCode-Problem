class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>ans;
        intervals.push_back({newInterval[0],newInterval[1]});
        sort(intervals.begin(),intervals.end());

        int currSt = intervals[0][0];
        int currEnd = intervals[0][1];
        int n = intervals.size();
        for(int i = 1;i<n;i++){
            if(currEnd<intervals[i][0]){
                ans.push_back({currSt,currEnd});
                currSt= intervals[i][0];
                currEnd = intervals[i][1];
            }else{
                currEnd = max(currEnd,intervals[i][1]);
            }
        }
        ans.push_back({currSt,currEnd});

        return ans;
    }
};