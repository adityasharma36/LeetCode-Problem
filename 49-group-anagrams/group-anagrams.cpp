class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string,vector<string>>map;

        vector<vector<string>> ans;

        for(int i = 0;i<strs.size();i++){
            
            string current = strs[i];
            
            string newCurrent = current;

            sort(newCurrent.begin(),newCurrent.end());

            map[newCurrent].push_back(current);

        }

        for(auto i: map){

            ans.push_back(i.second);

        }

        return ans;
        
    }
};