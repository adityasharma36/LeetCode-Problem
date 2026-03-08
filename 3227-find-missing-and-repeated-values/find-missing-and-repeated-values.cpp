class Solution {
public:
    vector<int> findMissingValue(vector<vector<int>>& grid){
        vector<int>ans;
        for(auto i : grid){
            for(auto j : i){
                ans.push_back(j);
            }
        }
        int i = 0;
        while(i< ans.size()){
            int index = ans[i]-1;
            
            if(ans[index]!= ans[i]){
                swap(ans[index],ans[i]);
            }else{
                i++;
            }
        }
        for(int i = 0;i<ans.size();i++){
            if(i+1 != ans[i]){
                return {ans[i],i+1};
            }
        }
        return {-1,-1};
    }
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        return findMissingValue(grid);
    }
};