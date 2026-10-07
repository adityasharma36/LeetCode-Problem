class Solution {
public:
    void dfa(int src,unordered_map<int,bool>&isVisited,unordered_map<int,list<int>>&adjList){
        isVisited[src]= true;

        for(auto list: adjList[src]){
            if(!isVisited[list]){
                dfa(list,isVisited,adjList);
            }
        }
    }
    int solveByDFS(vector<vector<int>>&isConnected){
        int n = isConnected.size();
        int m = isConnected[0].size();

        int count = 0;
        unordered_map<int,list<int>>adjList;
        unordered_map<int,bool>isVisited;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(isConnected[i][j]){
                    adjList[i].push_back(j);
                }
            }
        }

        for(int i = 0;i<n;i++){
            if(!isVisited[i]){
                dfa(i,isVisited,adjList);
                count++;
            }
        }
        return count;
    }
    void bfs(int src,unordered_map<int,bool>&isVisited,unordered_map<int,list<int>>&adjList){
        queue<int>q;
        q.push(src);
        isVisited[src] = true;
        while(!q.empty()){
            int front = q.front();
            q.pop();
            for(auto list: adjList[front]){
                if(!isVisited[list]){
                    q.push(list);
                    isVisited[list]= true;
                }
            }
        }
    }
    int solveByBFS(vector<vector<int>>& isConnected){
        int n = isConnected.size();
        int m = isConnected[0].size();

        int count = 0;
        unordered_map<int,list<int>>adjList;
        unordered_map<int,bool>isVisited;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(isConnected[i][j]){
                    adjList[i].push_back(j);
                }
            }
        }

        for(int i = 0;i<n;i++){
            if(!isVisited[i]){
                bfs(i,isVisited,adjList);
                count++;
            }
        }
        return count;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        // int count = solveByDFS(isConnected);
        int count = solveByBFS(isConnected);
        return count;
    }
};