class Solution {
public:
    int kthNumber(vector<int>& arr,int k){
        int start = 1;
        int count = 0;
        int i = 0;

        while(true){
            if(i< arr.size() && arr[i]== start){
                i++;
            }
            else{
                count++;
                if(count == k) return start;
            }
            start++;
        }
        return -1;
    }
    int optimiseSol(vector<int>& arr,int k)
{
    int start = 0;
    int end = arr.size()-1;
    while(start<=end){
        int mid = start + (end-start)/2;
        int missingNum = arr[mid] -(mid +1);

        if(missingNum < k){
            start = mid + 1;
        }else{
            end = mid -1;
        }
    }
    return end + k + 1;
}
    int findKthPositive(vector<int>& arr, int k) {
        // int answer = kthNumber(arr,k);

        int answer = optimiseSol(arr,k);
        return answer;
    }
};