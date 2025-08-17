class Solution {
public:

    int findSingleByMap(vector<int>& nums){
        unordered_map<int,int> um;
        for(int i = 0;i<nums.size();i++){
            um[nums[i]]++;
        }
        for(auto & mapping : um){
        
            if(mapping.second == 1){
                return mapping.first;
            }
        }
        return -1;
    }

    int findSingleBySAS(vector<int>& nums){

        int start = 1;

        int len = nums.size();

        int end = len-2;

        if(len == 1){

            return nums[0];

        }
        if(nums[0] != nums[start]) return nums[0];

        if(nums[len-1]!= nums[end]) return nums[len-1];

        while(start<=end){

            int mid = start + (end-start)/2;

            if((nums[mid] != nums[mid-1]) && (nums[mid] != nums[mid +1])){

                return nums[mid];

            }

            if((mid %2 == 1 && nums[mid] == nums[mid -1]) || (mid %2 == 0 && nums[mid] == nums[mid +1])){

                start = mid +1;

            } 
            else{

                end = mid-1;

            }
        }
        return -1;
    }
    int singleNonDuplicate(vector<int>& nums) {
        
        // int answer = findSingleByMap(nums);

        int answer = findSingleBySAS(nums);
        return answer;
    }
};