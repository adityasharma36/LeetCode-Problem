class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string>setBank(bank.begin(),bank.end());
        unordered_set<string>isVisited;

        queue<string>q;
        q.push(startGene);
        int level = 0;
        isVisited.insert(startGene);
        while(!q.empty()){
            int n = q.size();
            while(n--){
                string curr = q.front();
                q.pop();
                if(curr == endGene) return level;
                for(auto put : "ACGT"){
                    for(int i = 0;i<curr.size();i++){
                        string st = curr;
                        st[i]=  put;

                        if((isVisited.find(st) == isVisited.end()) && (setBank.find(st) != setBank.end())){
                            isVisited.insert(st);
                            q.push(st);
                        }
                    }
                }
            }
                level++;
        }
        return -1;
    }
};