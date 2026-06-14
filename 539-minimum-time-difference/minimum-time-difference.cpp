class Solution {
public:
    void minDifference(vector<string>& timePoints,vector<int>&timeDiff){
        int n = timePoints.size();
        for(int i = 0;i<n;i++){
            int hrs = stoi(timePoints[i].substr(0,2)) * 60;
            int mint = stoi(timePoints[i].substr(3,5));
            int totalTime = hrs+mint;
            timeDiff.push_back(totalTime);
            cout<<totalTime<<endl;
        }
    }
    int findMinDifference(vector<string>& timePoints) {
        vector<int>timeDiff;
        minDifference(timePoints,timeDiff);
        sort(timeDiff.begin(),timeDiff.end());
        int n = timeDiff.size();

        int minDiff = INT_MAX;
        for(int i = 0;i<n-1;i++){
            int diff = timeDiff[i+1]-timeDiff[i];
            minDiff = min(minDiff,diff);
        }
        cout<<timeDiff[n-1]<<endl;
        int lastDiff = 1440 + timeDiff[0] - timeDiff[n-1];
        minDiff = min(minDiff,lastDiff);

        return minDiff;
    }
};