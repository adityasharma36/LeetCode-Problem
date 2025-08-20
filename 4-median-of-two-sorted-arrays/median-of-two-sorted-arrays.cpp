class Solution {
public:


    // double findMedianOfMergedArrays(vector<int>& nums1,vector<int>& nums2){
    //     vector<int> sortedArray;

    //     int start = 0;
    //     int start1 = 0;
    //     int end = nums1.size()-1;
    //     int end1 = nums2.size()-1;

    //     while(start<=end && start1<=end1){
    //         if(nums1[start]<=nums2[start1]){
    //             sortedArray.push_back(nums1[start]);
    //             start++;
    //         }else{
    //             sortedArray.push_back(nums2[start1]);
    //             start1++;
    //         }
    //     }
    //     while(start<=end){
    //          sortedArray.push_back(nums1[start]);
    //             start++;
    //     };
    //     while(start1<=end1){
    //           sortedArray.push_back(nums2[start1]);
    //             start1++;
    //     };
    //     int len = sortedArray.size();
    
    //     int mid  = len/2;
    //     if(len%2 == 1){
    //         return static_cast<double>(sortedArray[mid]);
    //     }
        
    //      return (static_cast<double>(sortedArray[mid]) +static_cast<double>(sortedArray[mid-1]))/2.0;

    // }
       
 
    // double bruteForce(vector<int>& nums1,vector<int>& nums2){
    //     // appe
    //     for(auto i : nums2){
    //         nums1.push_back(i);
    //     }

    //     sort(nums1.begin(),nums2.end());

    //     int start = 0;
    //     int len = nums1.size();
    //     int end = len-1;
    //     int mid = start + (end-start)/2;
    //     if(len%2 == 0){
    //         return (nums1[mid]+ nums1[mid+1])/2;
    //     }else{
    //         return nums1[mid];
    //     }

    //     return -1;
    // }

    double optimiseSolution(vector<int>& nums1, vector<int>& nums2) {
    int len1 = nums1.size();
    int len2 = nums2.size();
    int total = len1 + len2;

    int index1 = total / 2;
    int index2 = index1 - 1;

    int i = 0, j = 0, cnt = 0;
    int ele1 = -1, ele2 = -1;

    // Merge-like process
    while (i < len1 && j < len2) {
        int pick;
        if (nums1[i] < nums2[j]) {
            pick = nums1[i++];
        } else {
            pick = nums2[j++];
        }

        if (cnt == index1) ele1 = pick;
        if (cnt == index2) ele2 = pick;
        cnt++;
    }

    while (i < len1) {
        int pick = nums1[i++];
        if (cnt == index1) ele1 = pick;
        if (cnt == index2) ele2 = pick;
        cnt++;
    }

    while (j < len2) {
        int pick = nums2[j++];
        if (cnt == index1) ele1 = pick;
        if (cnt == index2) ele2 = pick;
        cnt++;
    }

    if (total % 2 == 0) {
        return (ele1 + ele2) / 2.0;
    }
    return ele1;
}

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double answer = optimiseSolution(nums1,nums2);
        return answer;
        
    }
};