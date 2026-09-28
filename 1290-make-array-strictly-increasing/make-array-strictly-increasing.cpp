class Solution {
public:
    int solveByRec(vector<int>& arr1,vector<int>& arr2,int p,int i){
        if(i>=arr1.size()) return 0;
        long long opt = INT_MAX;
        if(p<arr1[i]){
            opt = solveByRec(arr1,arr2,arr1[i],i+1);
        }
        long long  opt2 = INT_MAX;
        auto it = upper_bound(arr2.begin(),arr2.end(),p);

        if(it != arr2.end()){
            int index = it-arr2.begin();
            int temp = solveByRec(arr1,arr2,arr2[index],i+1);
            if(temp != INT_MAX){
                opt2  = 1+ temp;
            }
        }
        return min(opt,opt2);
    }
    int solveByMemo(vector<int>& arr1,vector<int>& arr2,int p,int i,map<pair<int,int>,int>&mp){
        if(i == arr1.size()) return 0;
        if(mp.find({p,i}) != mp.end()) return mp[{p,i}];
        int opt = INT_MAX;
        if(p<arr1[i]){
            opt = solveByMemo(arr1,arr2,arr1[i],i+1,mp);
        }
        int opt2 = INT_MAX;
        auto it = upper_bound(arr2.begin(),arr2.end(),p);
        if(it != arr2.end()){
            int index = it - arr2.begin();
            int temp = solveByMemo(arr1,arr2,arr2[index],i+1,mp);

            if(temp!= INT_MAX){
                opt2 = 1+temp;
            }
        }

       return  mp[{p,i}]= min(opt2,opt);
    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        if(n==1) return 0;
        sort(arr2.begin(),arr2.end());
        // int ans = solveByRec(arr1,arr2,-1,0);

        map<pair<int,int>,int>mp;
        int ans = solveByMemo(arr1,arr2,-1,0,mp);

        if(ans == INT_MAX) return -1;

        return ans;
    }
};