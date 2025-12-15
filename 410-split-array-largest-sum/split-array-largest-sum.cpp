class Solution {
public:
    int findMaxEle(vector<int>& nums){
        int maxEle = INT_MIN;
        for(auto i : nums){
            maxEle = max(maxEle,i);
        }
        return maxEle;
    }
    bool isPossibe(vector<int>& nums,int k,int mid){
        int cnt = 0;
        int sum = 0;
        for(auto i : nums){
            if(sum+ i <= mid){
                
                sum+=i;
            }else{
                cnt++;
                sum= i;
                if(cnt>=k) return false;
            }
        }
        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        int start = findMaxEle(nums);
        int end = accumulate(nums.begin(),nums.end(),0);

        int ans = -1;
        while(start<=end){
            int mid = (end-start)/2 + start;

            if(isPossibe(nums,k,mid)){
                ans = mid;
                end = mid-1;
            }else{
                start = mid+1;
            }
        }
        return ans;
    }
};