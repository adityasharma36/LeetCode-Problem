class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int count =1;
        vector<int>prev = points[0];
        int n = points.size();
        for(int i = 1;i<n;i++){
            int prevSt = prev[0];
            int prevEnd = prev[1];
            int currSt = points[i][0];
            int currEnd = points[i][1];

            if(prevEnd< currSt){
                count++;
                prev = points[i];
            }else{
                prev[0]= max(prevSt,currSt);
                prev[1]= min(prevEnd,currEnd);
            }
        }
        return count;
    }
};