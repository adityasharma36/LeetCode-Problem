class Solution {
public:
    int findMinVal(vector<int>& bloomDay){
        int minVal = INT_MAX;
        for(int i = 0;i<bloomDay.size();i++){
            minVal = min(minVal,bloomDay[i]);
        }
        return minVal;
    }
    int findMaxVal(vector<int>& bloomDay){
        int maxVal = INT_MIN;
        for(int i = 0;i<bloomDay.size();i++){
            maxVal = max(maxVal,bloomDay[i]);
        }
        return maxVal;
    }
    bool isPossible(vector<int>& bloomDay,int m ,int k,int mid){
        int total = 0;
            int count = 0;
        for(int i = 0;i<bloomDay.size();i++){
                if(bloomDay[i]<= mid){
                    count++;
                }else{
                    total+=count/k;
                    count = 0;
                }
        }
         total += count / k;
        return total>= m;
    }
    int minimumDay(vector<int>& bloomDay,int m ,int k){
        int answer = -1;
        int start = findMinVal(bloomDay);
        int end = findMaxVal(bloomDay);
        if((long long)m * k > bloomDay.size()){
            return -1;
        } 


        while(start <= end){
            int mid = start + (end-start)/2;

            if(isPossible(bloomDay,m,k,mid)){
                answer = mid;
                end = mid-1;
            }else{
                start = mid+1;
            }
        }
        return answer;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int answer = minimumDay(bloomDay,m,k);
        return answer;
    }
};