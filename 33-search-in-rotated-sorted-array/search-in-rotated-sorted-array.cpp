class Solution {
public:
    int searchInRotatedArrByMap(vector<int>& nums,int target){
       

        unordered_map<int,int> um;

        for(int i = 0;i<nums.size();i++){

           int ele = nums[i];

           um[ele] = i;

           if(um.find(target) != um.end()){

                return um[target];

           }

        }

        return -1;    
    }

    int searchInRotatedArr(vector<int>& nums, int target){
        int start = 0;
        int end = nums.size()-1;
        int index  = -1;
        while(start<=end){
            int mid = start + (end-start)/2 ;

            if(nums[mid]== target){
                return mid;
            }
            if(nums[start]<=nums[mid]){
                if(nums[start]<= target && target <= nums[mid]){
                    end = mid-1;
                }else{
                    start = mid + 1;
                }
            }else {
                if(nums[mid]<= target && target <= nums[end]){
                    start = mid+1;
                }else{
                    end = mid-1;
                }
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        // int answer = searchInRotatedArrByMap(nums,target);
        int answer = searchInRotatedArr(nums,target);

        return answer;
    }
};