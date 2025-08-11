class Solution {
public:
    int solveByBF(vector<int>& nums, int k){

        int count = 0;
        int sum = 0;
        for(int i = 0;i<nums.size();i++){

            sum = 0;

            for(int j = i ;j<nums.size();j++){

                sum+=nums[j];

                count = sum % k == 0 ? count + 1: count + 0;
                // if(sum % k == 0){
                //     count++;
                // }

            }

        }
        return count;
    }
    int solveByOS(vector<int>& nums,int k){
        
        vector<int>prefixSum(nums.size(),0);
        
        prefixSum[0]= nums[0];
        
        for(int i = 1;i<nums.size();i++){

             prefixSum[i]= prefixSum[i-1]+ nums[i];
        
        }

        unordered_map<int,int>um;

        um[0]=1;

        int count = 0;

        for(int i = 0;i<prefixSum.size();i++){

            int div = prefixSum[i] %  k;

            if(div<0){

                div+=k;
           
            }

            if(um.find(div)!= um.end()){
                 count+= um[div];
            }

            um[div]++;
            
        }
        return count;

    }
    int subarraysDivByK(vector<int>& nums, int k) {

        // int answer = solveByBF(nums,k);

        int answer = solveByOS(nums,k);

        return answer;
        
    }
};