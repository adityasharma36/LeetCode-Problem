class Solution {
public:
    int minVal(vector<int>& bloomDay){
        int valMin = INT_MAX;
        for(auto i: bloomDay){
            valMin = min(i,valMin);
        }
        return valMin;
    }
    int maxVal(vector<int>& bloomDay){
        int valMax = INT_MIN;
        for(auto i: bloomDay){
            valMax = max(i,valMax);
        }
        return valMax;
    }
    bool isPossible(vector<int>& bloomDay,int m,int k ,int mid){
        int cnt = 0;
        int total = 0;
        for(auto i: bloomDay){
            if(i<=mid){
                cnt++;
            }else{
                total+=cnt/k;
                cnt=0;
            }
        }
        total+=cnt/k;
        return total>=m;
    }
    int minDayFnc(vector<int>& bloomDay,int m,int k){
        int start = minVal(bloomDay);
        int end = maxVal(bloomDay);
        int minDay = INT_MAX;
        if((double)m*k > bloomDay.size())return -1;
        while(start<=end){
            int mid = (end-start)/2 + start;

            if(isPossible(bloomDay,m,k,mid)){
                minDay = min(minDay,mid);
                end = mid-1;
            }else {
                start = mid+1;
            }
        }
        if(minDay!= INT_MAX) return minDay;
        return -1;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int daysMin = minDayFnc(bloomDay,m,k);
        return daysMin;
    }
};