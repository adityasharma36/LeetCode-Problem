class Solution {
public:
    int findKth(vector<int>& arr,int k){
        int start = 0;
        int end = arr.size()-1;
        while(start<=end){
            int mid = (end-start)/2 + start;

            int findMissingEle = arr[mid]-(mid+1);

            if(findMissingEle<k){
                start = mid+1;
            }else{
                end = mid-1;
            }
        }
        return end + k + 1;
    }
    int findKthPositive(vector<int>& arr, int k) {
        return findKth(arr,k);
    }
};