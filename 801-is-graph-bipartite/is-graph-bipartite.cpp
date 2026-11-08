class Solution {
public:
    bool isBip(unordered_map<int,list<int>>&adList,vector<int>&isVisited,int src){
        queue<int>q;
        q.push(src);
        isVisited[src]=0;
        while(!q.empty()){
            int front = q.front();
            q.pop();
            for(auto adj : adList[front]){
                if(isVisited[adj] ==-1){
                    isVisited[adj] = !isVisited[front];
                    q.push(adj);

                }
                else if(isVisited[adj] == isVisited[front]){
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        unordered_map<int,list<int>>adList;
        for(int i = 0;i<graph.size();i++){
            for(auto j: graph[i]){
                adList[i].push_back(j);
            }
        }
        int n = graph.size();
        vector<int>isVisited(n+1,-1);
        for(int i = 0;i<=n;i++){
            if(isVisited[i] ==-1){
                bool result =  isBip(adList,isVisited,i);
                if(result == false) return false;
            }
        }
        return true;
    }
};