class Solution {
public:
    int bruteForce(vector<int>& arr){
        int n = arr.size();
        for(int i = 0;i<n-1;i++){
            if(arr[i]>arr[i+1]){
                return i;
            }
        }
        return -1;
    }
    int optimseSol(vector<int>& arr){

        int start = 0;
        int n = arr.size();
        int end = n-1;
        while(start<end){
            int mid = (end-start)/2 + start;
           
            if(arr[mid]>arr[mid+1]){
                end = mid;
            }else{
                start = mid+1;
            }
        }
        return start;
    }
    int peakIndexInMountainArray(vector<int>& arr) {
        // return bruteForce(arr);
        return optimseSol(arr);
    }
};