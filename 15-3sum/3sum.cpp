class Solution {
public:
    vector<vector<int>>bruteForce(vector<int>& nums){
        sort(nums.begin(),nums.end());
   
        set<vector<int>>st;
        for(int i = 0;i<nums.size();i++){
            for(int j = i+1;j<nums.size();j++){
                for(int k = j+1;k<nums.size();k++){
                    if(nums[i]+ nums[j]+ nums[k]== 0){
                        vector<int>temp = {nums[i],nums[j],nums[k]};
                        if(st.find(temp) == st.end()){
                            st.insert(temp);
                          
                        }
                    }
                }
            }
        }
        vector<vector<int>> ans(st.begin(),st.end());
        return ans;
    }
    vector<vector<int>>threeSumOptimse(vector<int>& nums){
            sort(nums.begin(),nums.end());
            vector<vector<int>>ans;
            for(int i = 0;i<nums.size();i++){
                if(i>0 && nums[i]== nums[i-1]) continue;
                int j = i+1, k = nums.size()-1;
                while(j<k){
                    int sum = nums[i]+ nums[j]+ nums[k];
                    if(sum<0){
                        j++;
                    }else if(sum>0){
                        k--;
                    }else{
                        ans.push_back({nums[i],nums[j],nums[k]});
                        j++;
                        k--;
                        while(j<k && nums[j-1]== nums[j]) j++;
                        while(j<k && nums[k+1]== nums[k]) k--;
                    }
                }
            }
            return ans;
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        // return bruteForce(nums);
        return threeSumOptimse(nums);
    }
};