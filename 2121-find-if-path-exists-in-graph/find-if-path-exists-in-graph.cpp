class Solution {
public:
        unordered_map<int,bool>isVisited;
    bool bfa(int n,unordered_map<int,set<int>>&adList,int src,int dest){

        queue<int>q;
        q.push(src);
        

        while(!q.empty()){
            int N = q.size();
            while(N--){
                int front = q.front();
                q.pop();
                if(front == dest) return true;               
                for(auto &list : adList[front]){
                    if(!isVisited[list]  ){
                        q.push(list);
                        isVisited[list] = true;
                    }
                }
            }
        }

        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {

        unordered_map<int,set<int>>adList;
        for(auto &edge : edges){
            int i = edge[0];
            int j = edge[1];
            adList[i].insert(j);
            adList[j].insert(i);
        }
        bool valid =bfa(n,adList,source,destination);
      
        return valid;
    }
};