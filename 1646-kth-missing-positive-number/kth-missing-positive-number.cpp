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
    int findKthPositive(vector<int>& arr, int k) {
        int answer = kthNumber(arr,k);
        return answer;
    }
};