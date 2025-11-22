class Solution {
public:
    vector<int> missingEle(vector<vector<int>>& grid){
        vector<int> ans ;
        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[0].size();j++){
                ans.push_back(grid[i][j]);
            }
        }
        int i = 0;
        while(i<ans.size()){
            int index = ans[i]-1;

            if(ans[index]!= ans[i]){
                swap(ans[index],ans[i]);
            }else{
                i++;
            }
        }
        for(int i = 0;i<ans.size();i++){
            if(ans[i] != i+1){
                return {ans[i],i+1};
            }
        }
        return {-1,-1};
    }
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        return missingEle(grid);
    }
};