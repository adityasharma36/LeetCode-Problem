class Solution {
public:
    void sumCombination(vector<int>& cand, int target, set<vector<int>>& st,
                        int start, int end, vector<int>& temp) {

        if(target == 0){

            st.insert(temp);

            return;
        }

        for(int i = start; i < end; i++){

            if(cand[i] <= target){

                temp.push_back(cand[i]);

                sumCombination(cand, target - cand[i], st, i + 1, end, temp);

                temp.pop_back();
            }
        }
    }
    void memo(vector<int>& cand, int target, int start, int end, vector<int>& temp,vector<vector<int>>&ans){
            if(target == 0){
                ans.push_back(temp);
                return;
            }
            for(int i = start;i<end;i++){

                    if(i>start && cand[i]== cand[i-1]) continue;

                    if(cand[i]>target) break;

                    temp.push_back(cand[i]);
                    memo(cand,target-cand[i],i+1,end,temp,ans);
                    temp.pop_back();
            }

        }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin(), candidates.end()); // ✅ important

        set<vector<int>> st;

        vector<int> temp;

        int n = candidates.size();


        // sumCombination(candidates, target, st, 0, candidates.size(), temp);

        vector<vector<int>>ans;

        memo(candidates,target,0,n,temp,ans);

        return ans;
    }
};
