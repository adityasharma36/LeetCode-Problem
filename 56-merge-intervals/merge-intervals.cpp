class Solution {
public:
    vector<vector<int>> mergeInterval(vector<vector<int>> & intervals ){
        sort(intervals.begin(),intervals.end());
        int start = intervals[0][0];
        int end = intervals[0][1];

        vector<vector<int>> ans;
        for(int i = 1;i<intervals.size();i++){

            if(intervals[i][0]<= end){
                end = max(intervals[i][1],end);
            }else{
                
                ans.push_back({start,end});
                end = intervals[i][1];
                start = intervals[i][0];
            }
            
           
        }

        ans.push_back({start,end});
        return ans;
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans = mergeInterval(intervals);
        return ans;
    }
};