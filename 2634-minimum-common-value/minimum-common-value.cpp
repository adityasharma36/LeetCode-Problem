class Solution {
public:
    int bruteForce(vector<int>& nums1,vector<int>& nums2){
        int n = nums1.size();
        int m = nums2.size();

        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(nums1[i]==nums2[j]){
                    return nums1[i];
                }
            }
        }
        return -1;
    }
    int optimseSol(vector<int>& nums1,vector<int>& nums2){
        int n = nums1.size();
        int m = nums2.size();
        int i = 0;
        int j = 0;
        while(i<n && j<m){
            if(nums1[i]==nums2[j]) return nums1[i];
            else if(nums1[i]> nums2[j]) j++;
            else i++;
        }
        return -1;
    }
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        // return bruteForce(nums1,nums2);
        return optimseSol(nums1,nums2);
    }
};