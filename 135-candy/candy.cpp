class Solution {
public:
    int maxCandy(vector<int>& rat){
        int n = rat.size();
        vector<int>left(n,1);
        vector<int>right(n,1);

        for(int i = 1;i<n;i++){
            if(rat[i] > rat[i-1]){
                left[i]= left[i] + left[i-1];
            }
        }

        for(int i = n-2;i>=0;i--){
            if(rat[i] > rat[i+1]){
                right[i]= right[i] + right[i+1];
            }
        }
        int cnt = 0;
        for(int i = 0;i<n;i++){
            int maxEle = max(right[i],left[i]);
            cnt+=maxEle;
        }
        return cnt;
    }
    int candy(vector<int>& ratings) {
        return maxCandy(ratings);
    }
};