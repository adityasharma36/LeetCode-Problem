class Solution {
public:
    int dfs(unordered_map<int,set<int>>&adList,vector<bool>& hasApple,int curr,int prev){
        int time = 0;
        for(auto &list: adList[curr]){
            if(list == prev) continue;
            int childApple =dfs(adList,hasApple,list,curr);
            if( childApple>0 || hasApple[list]){
                time += childApple + 2;
            }
        }
        return time;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        unordered_map<int,set<int>>adList;
        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];
            adList[u].insert(v);
            adList[v].insert(u);
        }
        return dfs(adList,hasApple,0,-1);
    }
};