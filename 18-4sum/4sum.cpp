class Solution {
public:
    vector<vector<int>> findFourSum(vector<int>& nums, int target){

        sort(nums.begin(),nums.end());

         vector<vector<int>> answer;

        for(int i = 0;i<nums.size();i++){

            if(i>0 && nums[i] == nums[i-1]) continue;

            for(int j = i+1;j<nums.size();j++){

                if(j>i+1 && nums[j]== nums[j-1]) continue;


                int k = j+1,l = nums.size()-1;

                while(k<l){

                    long long  sum =(long long) nums[i]+ nums[j]+ nums[k]+ nums[l];

                    if(sum > target){

                        l--;

                    }
                    else if(sum< target){

                        k++;

                    }
                    else{

                        answer.push_back({nums[i],nums[j],nums[k],nums[l]});
                        l-- , k++;

                        while(k<l && nums[k] == nums[k-1]) k++;
                        while(k<l && nums[l] == nums[l+1]) l--;

                    }
                }
            
            }
        }
        return answer;
    }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        vector<vector<int>> answer = findFourSum(nums,target);
         return answer;
    }
};