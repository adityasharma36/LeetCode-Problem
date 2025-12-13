class Solution {
public:
    int largeEle(vector<int>& nums){
        int ele = INT_MIN;
        for(int i : nums){
            ele = max(ele, i);
        }
        return ele;
    }

    bool isPossible(vector<int>& nums, int mid, int thres){
        int cnt = 0;
        for(int i : nums){
            cnt += (i + mid - 1) / mid; 
            if(cnt > thres) return false;
        }
        return true;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int start = 1;               
        int end = largeEle(nums);
        int answer = end;

        while(start <= end){
            int mid = start + (end - start) / 2;

            if(isPossible(nums, mid, threshold)){
                answer = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return answer;
    }
};
