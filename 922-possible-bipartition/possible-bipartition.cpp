class Solution {
public:
    bool isParition(unordered_map<int,set<int>>&adList,int i,vector<int>&color){
        queue<int>q;
        q.push(i);
        color[i]= 1;

        while(!q.empty()){
            int front = q.front();
            q.pop();

            for(auto &v: adList[front]){
                if(color[v] == color[front]){
                    return false;
                }
                if(color[v] == -1){
                    q.push(v);
                    color[v]= 1-color[front];
                }
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        unordered_map<int,set<int>>adList;
       
        vector<int> color(n+1 ,-1);
        for(auto &disli: dislikes){
            int u = disli[0];
            int v = disli[1];
            adList[u].insert(v);
            adList[v].insert(u);
        }

        for(int i = 1;i<=n;i++){
            if(color[i] == -1){
                if(!isParition(adList,i,color)){
                    return false;
                }
            }
        }
        return true;
    }
};