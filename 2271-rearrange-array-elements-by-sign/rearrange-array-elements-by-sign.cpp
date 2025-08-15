class Solution {
public:
    vector<int> arrangeArray(vector<int>& nums){
        vector<int> arr(nums.size(),0);
        int neg = 1;
        int posi = 0;
        for(int i = 0;i<nums.size();i++){
            if(nums[i] >0){
                arr[posi] = nums[i];
                posi+=2;
            }else{
                arr[neg]= nums[i];
                neg+=2;
            }
        }
        return arr;
    }
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> answer = arrangeArray(nums);
        return answer;
    }
};