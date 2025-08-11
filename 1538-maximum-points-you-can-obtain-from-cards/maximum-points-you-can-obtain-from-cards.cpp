class Solution {
public:
    int findMaxScore(vector<int>& nums,int k){

        int sum = accumulate(nums.begin(),nums.begin()+k,0);

        int maxSum = sum;

        int lastIndex = nums.size()-1;

        for(int i = k-1;i>=0;i--){
            
            sum -=nums[i];

            sum += nums[lastIndex];

            lastIndex--;

            maxSum = max(sum,maxSum);

        }
        return maxSum;
    }
    int maxScore(vector<int>& cardPoints, int k) {

        int answer = findMaxScore(cardPoints,k);

        return answer;
        
    }
};