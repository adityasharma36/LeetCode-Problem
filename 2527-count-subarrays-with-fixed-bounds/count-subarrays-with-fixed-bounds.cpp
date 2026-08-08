class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int minPosi = -1;
        int maxPosi = -1;
        int cultPosi = -1;

        int j = 0;
        int n = nums.size();
        long long total = 0;
        while(j<n){
            int numb = nums[j];
             if(numb<minK || numb>maxK){
                cultPosi = j;
            }
            if(numb == minK){
                minPosi = j;
            }
            if(numb == maxK){
                maxPosi = j;
            }

           
            long long minEle = min(minPosi,maxPosi);
           long long sum = minEle-cultPosi;

            total+= (sum<=0) ? 0: sum;
           j++;
        }   
        return total;
    }
};