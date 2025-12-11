class Solution {
public:
    int findMaxEle(vector<int> & nums){
        int maxEle = INT_MIN;
        for(auto i : nums){
            maxEle = max(maxEle, i);
        }
        return maxEle;
    }

    bool isPossible(vector<int>& nums,int hours ,int mid){
        int totalHour = 0;
        for(int i = 0;i<nums.size();i++){
            int time = (nums[i] + mid - 1) / mid;  // correct ceil division
            totalHour += time;
            if(totalHour > hours) return false;
        }
        return true;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int start = 1;
        int end = findMaxEle(piles);
        int ans = 0;

        while(start <= end){
            int mid = (end - start) / 2 + start;

            if(isPossible(piles, h, mid)){
                ans = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return ans;
    }
};
