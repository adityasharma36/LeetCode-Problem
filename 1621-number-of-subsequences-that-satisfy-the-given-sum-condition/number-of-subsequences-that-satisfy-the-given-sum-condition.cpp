class Solution {
public:
    // int numberSubSequence(vector<int>& nums,int target,int index,int minVal,int maxVal,int count,int sum){
    //     if(index == nums.size() && maxVal + minVal <= target){
    //         count++;
    //     }

     

    //     int includeSubSeque = numberSubSequence(nums,target,index+1,sum+nums[index]);

    //     int excludeSubSeque = numberSubSequence(nums,target,index+1,sum);

    //     int answer = includeSubSeque + excludeSubSeque;

    //     return answer;

    // }


    // two pointer 
    int modulo = 1e9+7;
    int numberSubSequence(vector<int>& nums,int target){

        vector<int>ans(nums.size()+1,1);

        for(int i = 1;i<nums.size();i++){
            ans[i]= (ans[i-1]*2) % modulo;
        }

        int start = 0;
        int end = nums.size()-1;
        int result = 0;
        while(start<=end){
            int diff = end-start;

            if(nums[end]+ nums[start]<= target){

                result = (result + ans[diff]) % modulo;
                start++;
            }else{
                end--;
            }
        }
        return result;
    }
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        return numberSubSequence(nums,target);

    }
};