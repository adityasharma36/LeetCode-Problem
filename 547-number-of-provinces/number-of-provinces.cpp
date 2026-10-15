class Solution {
public:
    void dfs(unordered_map<int,set<int>>&adList,int src,unordered_map<int,bool>&isVisited){
        isVisited[src] = true;

        for(auto list : adList[src]){
            if(!isVisited[list]){
                dfs(adList,list,isVisited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        unordered_map<int,set<int>>adList;
        int n = isConnected.size();
        int m = isConnected[0].size();
        for(int i = 0;i<n;i++){
            for(int j =0;j<n;j++){
                if(isConnected[i][j]){
                    adList[i].insert(j);
                    adList[j].insert(i);
                }
            }
        }
        int provience = 0;
        unordered_map<int,bool>isVisited;
        for(int i = 0;i<n;i++){
            if(!isVisited[i]){
                dfs(adList,i,isVisited);
                provience++;
            }
        }
        return provience;
    }
};