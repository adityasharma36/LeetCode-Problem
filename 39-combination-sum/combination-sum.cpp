class Solution {
public:
    void comboSum(vector<int>& candidates,int target,vector<vector<int>> & answer,vector<int>& tempAns,int index){

        if(target == 0){
            answer.push_back(tempAns);
            return;
        }

        for(int i = index;i<candidates.size();i++){
            int coinSum = candidates[i];

            if(coinSum<=target){
                tempAns.push_back(coinSum);
                comboSum(candidates,target-coinSum,answer,tempAns,i);
                tempAns.pop_back();

            }
        } 
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> answer;
        vector<int> tempAns;
        comboSum(candidates,target,answer,tempAns,0);
        return answer;
    }
};