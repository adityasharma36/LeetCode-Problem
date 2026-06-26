class Solution {
public:
    long long bruteForce(vector<int>& nums,int target){
        long long cnt = 0;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            long long temp = 0;
            for(int j = i;j<n;j++){
                if(nums[j]== target) temp++;
                else temp--;
                if(temp>0) cnt++;
            }
        }
        return cnt;
    }
    long long optimseSol(vector<int>& nums,int target){
        unordered_map<int,int>um;
        long long cumSum = 0;
        long long validLeftPoint = 0;
        long long result = 0;

        um[0]=1;
        int n = nums.size();

        for(int i = 0;i<n;i++){
            if(nums[i]== target){
                validLeftPoint+=um[cumSum];
                cumSum++;
            }else{
                cumSum--;
                validLeftPoint-=um[cumSum];
            }
            um[cumSum]+=1;
            result+=validLeftPoint;
        }
        return result;
    }
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        // return bruteForce(nums,target);

        return optimseSol(nums,target);
    }
};