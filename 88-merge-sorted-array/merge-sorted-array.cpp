class Solution {
public:
    void mergeTwoSortedArray(vector<int>& nums1, int m, vector<int>& nums2, int n){
        vector<int>arr(nums1.size(),0);
        int i = 0;
        int start = 0;
        int start1 = 0;

        while(start<m && start1 < n ){
            if(nums1[start]< nums2[start1]){
                arr[i]= nums1[start];
             
                start++;
            }else{
                arr[i]= nums2[start1];

                start1++;
            }
               i++;
        }
        for(int in = start ;in<m;in++){
            arr[i] = nums1[in];
            i++;
        }
         for(int in = start1 ;in<n;in++){
            arr[i] = nums2[in];
            i++;
        }

        for(int i = 0;i<arr.size();i++){
            nums1[i]= arr[i];
        }
    }

    void solveByOptimiseSol(vector<int>& nums1, int m, vector<int>& nums2, int n){
        int idx = m + n -1;
        int i = m-1;
        int j = n-1;

        while(i>=0 && j>= 0){
            if(nums1[i]>= nums2[j]){
                nums1[idx]= nums1[i];
                i--;
                idx--;
            }
            else{
                nums1[idx]= nums2[j];
                idx--;
                j--;
            }
        }
        while(j>=0){
            nums1[idx]= nums2[j];
                idx--;
                j--;
        }
    }
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        solveByOptimiseSol(nums1,m,nums2,n);
    }
};