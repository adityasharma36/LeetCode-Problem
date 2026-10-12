class Solution {
public:

    // int dfs(unordered_map<int,set<int>>&adList, int src,int n){
    //     vector<int>isVisited(n,0);
    //     isVisited[src] = 1;
    //     int sum = 0;
    //     queue<int>q;
    //     int level = 0;
    //     q.push(src);
    //     while(!q.empty()){
    //         int N = q.size();
    //         int temp = N;
    //         while(N--){
    //             int front = q.front();
    //             q.pop();
    //             for(auto neibour: adList[front]){
    //                 if(!isVisited[neibour]){
    //                     q.push(neibour);
    //                     isVisited[neibour] = 1;
    //                 }
    //             }
    //         }
        
    //         sum+= level* temp;
    //         level++;
    //     }
    //     return sum;
    // }


    long result_base_count = 0;
    vector<int>count;
    int N;
    int dfa(unordered_map<int,set<int>>&adList,int src,int prev,int curr_depth){
        int total_node= 1;

        result_base_count +=curr_depth;

        for(auto &list: adList[src]){
            if(list == prev){
                continue;
            }
            total_node +=dfa(adList,list,src,curr_depth+1);
        }
        count[src]= total_node;
        return total_node;
    }
    void DFA(unordered_map<int,set<int>>&adList,int src,int prev,vector<int>& result){
        for(auto &list: adList[src]){
            if(list == prev){
                continue;
            }
            result[list]= result[src] - count[list] + (N-count[list]);
            DFA(adList,list,src,result);
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        unordered_map<int,set<int>>adList;
        N = n;
       for(auto edge: edges){
            int u = edge[0];
            int v = edge[1];
            adList[u].insert(v);
            adList[v].insert(u);
       }
    //    vector<int>ans;
    //    for(int i = 0;i<n;i++){
    //         int sum = dfs(adList,i,n);
    //         ans.push_back(sum);
    //    }
    //    return ans;

    vector<int>result(n,0);
     count.resize(n, 0);
    dfa(adList,0,-1,0);
    result[0] = result_base_count;
    DFA(adList,0,-1,result);
    return result;
    }
};