class Solution {
public:
    int minVal(vector<int>& nums){
        int minVa = INT_MAX;
        for(auto i: nums){
            minVa = min(minVa , i);
        }
        return minVa;
    }

    int maxVal(vector<int>& nums){
        int maxVa = INT_MIN;
        for(auto i: nums){
            maxVa = max(maxVa,i);
        }
        return maxVa;
    }

    bool isPossible(vector<int>& ans,int mid ,int m ,int k){
        int cnt = 0;
        int an = 0;

        for(int i : ans){
            if(i <= mid){
                cnt++;
            } else {
                an += (cnt / k);
                cnt = 0;
            }
        }
        an += (cnt / k);

        return an >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {

        if ((long long)bloomDay.size() < (long long)m * k) 
            return -1;   // FIXED

        int start = minVal(bloomDay);
        int end   = maxVal(bloomDay);
        int ans = -1;

        while(start <= end){
            int mid = start + (end - start) / 2;

            if(isPossible(bloomDay, mid, m, k)){
                ans = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return ans;
    }
};
