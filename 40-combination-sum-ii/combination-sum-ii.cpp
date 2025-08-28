class Solution {
public:
    void combinationSum(vector<int>& candidates, int target,int index ,vector<int>&ans,set<vector<int>> & check){
        if(target == 0){
            check.insert(ans);
            return;
        }
          if (target < 0 || index >= candidates.size()) return;

        ans.push_back(candidates[index]);
        combinationSum(candidates,target-candidates[index],index+1,ans,check);
        ans.pop_back();
        combinationSum(candidates,target,index+1,ans,check);

    }

    void comboSum2(vector<int>& candidates,int target,int index,vector<vector<int>>& ans,vector<int>& answer){
        if(target == 0){
            ans.push_back(answer);
            return;
        }
            if(target<0) return;


        for(int i = index;i<candidates.size();i++){

            if( i > index && candidates[i] == candidates[i-1] ) continue;

            answer.push_back(candidates[i]);

            comboSum2(candidates,target-candidates[i],i+1,ans,answer);

            answer.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    
        // vector<int>ans;
        // set<vector<int>> check;
        // combinationSum(candidates,target,0,ans,check);
        //   vector<vector<int>>answer(check.begin(),check.end());
        //   return answer;

        sort(candidates.begin(),candidates.end());
        vector<int>answer;
        vector<vector<int>>ans;
        comboSum2(candidates,target,0,ans,answer);
        return ans;
    }
};