class Solution {
public:
    bool isPossible(vector<int>& nums,int k,int mid){
        int sum = 0;
        int possibleSplit = 1;

        for(int i = 0;i<nums.size();i++){
            if(nums[i]+ sum <= mid){
                sum+= nums[i];
            }else{
                possibleSplit++;
                sum = nums[i];
            }
        }
        if(possibleSplit> k) return false;

        return true;
    }
    int maxElement(vector<int>& nums){
        int maxEle = INT_MIN;
        for(int i = 0;i<nums.size();i++){
            maxEle = max(maxEle, nums[i]);
        }
        return maxEle;
    }
    int splitArrayLargestSum(vector<int>& nums,int k){
        int start = maxElement(nums);
        int end = accumulate(nums.begin(),nums.end(),0);
        int answer = -1;
        while(start<=end){
            int mid = start + (end-start)/2;
            if(isPossible(nums,k,mid)){
                answer = mid;
                end = mid-1;
            }else{
                start  = mid+1;
            }
        }
        return answer;
    }
    int splitArray(vector<int>& nums, int k) {
        int answer = splitArrayLargestSum(nums,k);
        return answer;
    }
};