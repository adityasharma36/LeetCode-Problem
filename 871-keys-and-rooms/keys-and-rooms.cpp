class Solution {
public:
    void bfa(unordered_map<int,set<int>>&adList,int src,unordered_map<int,bool>&isVisited){
        queue<int>q;
        q.push(src);
        isVisited[src] = true;

        while(!q.empty()){
            int N = q.size();
            while(N--){
                int front = q.front();
                q.pop();
                for(auto ele: adList[front]){
                    if(!isVisited[ele]){
                        q.push(ele);
                        isVisited[ele] = true;
                    }
                }
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_map<int,set<int>>adList;
        for(int i = 0;i<rooms.size();i++){
            for(auto ele: rooms[i]){
                adList[i].insert(ele);
            }
        }
        unordered_map<int,bool>isVisited;
       
        bfa(adList,0,isVisited);
        
        for(int i = 0;i<rooms.size();i++){
            if(!isVisited[i]) return false;
        }
        return true;
    }
};