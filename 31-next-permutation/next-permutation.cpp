class Solution {
public:
    void lexicoPermutation(vector<int>& nums){
        int len = nums.size()-1;
        int pivot = -1;
        for(int i = len-1;i>=0;i--){
            if(nums[i]<nums[i+1]){
                pivot = i;
                break;
            }
          
        }
          if(pivot == -1){
                sort(nums.begin(),nums.end());
                return;
            }
        for(int i = len;i>pivot ;i--){
            if(nums[i]>nums[pivot]){
                swap(nums[i],nums[pivot]);
                break;
            }
        }
        int next = pivot +1;
        while(next < len){

            swap(nums[next],nums[len]);
            next++;
            len--;
        }
    }
    void nextPermutation(vector<int>& nums) {
        lexicoPermutation(nums);
    }
};