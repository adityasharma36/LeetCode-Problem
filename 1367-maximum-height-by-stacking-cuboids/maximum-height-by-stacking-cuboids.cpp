class Solution {
public:
    bool isFollow(vector<int>&prev,vector<int>&curr){
        if(prev[0]<=curr[0] && prev[1] <= curr[1] && prev[2] <= curr[2]){
            return true;
        }
        return false;
    }
    int solveByRec(vector<vector<int>>& cuboids,int prev,int curr){
        if(curr>=cuboids.size()) return 0;

        int include = 0;
        
        if(prev == -1 || isFollow(cuboids[prev],cuboids[curr])){
            include = cuboids[curr][2] + solveByRec(cuboids,curr , curr+1);
        }
        int excl = solveByRec(cuboids,prev,curr+1);
        return max(include,excl);
    }
    int maxHeight(vector<vector<int>>& cuboids) {
        for(auto &cuboid : cuboids){
            sort(begin(cuboid),end(cuboid));
        }
        sort(begin(cuboids),end(cuboids));

        int ans = solveByRec(cuboids,-1,0);
        return ans;
    }
};