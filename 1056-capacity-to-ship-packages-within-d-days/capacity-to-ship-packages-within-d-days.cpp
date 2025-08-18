class Solution {
public:
    int maxValue(vector<int>& weights){
        int maxVal = INT_MIN;
        for(int i= 0;i<weights.size();i++){
            maxVal = max(maxVal,weights[i]);
        }
        return maxVal;
    }
    int shipCapacity(vector<int>& weights,int days){
        int start = maxValue(weights);
        int end = accumulate(weights.begin(),weights.end(),0);
        int answer = -1;
        while(start<=end){
            int mid = start + (end-start)/2;
            int daysNeeded = 1, currWeight = 0;
            for(auto weight : weights){
                if(currWeight + weight > mid){
                    daysNeeded++;
                    currWeight = 0;
                }
                currWeight += weight;
            }
            if(daysNeeded<= days){
                answer = mid;
                end = mid-1;
            }else{
                start = mid+1;
            }
        }
        return answer;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int answer = shipCapacity(weights,days);
        return answer;
    }
};