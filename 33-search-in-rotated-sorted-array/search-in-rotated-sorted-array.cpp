class Solution {
public:
    int searchInRotatedArr(vector<int>& nums,int target){
        // int start = 0;
        // int end = nums.size()-1;
        // int index = -1;
        // while(start<=end){

        // }

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
    int search(vector<int>& nums, int target) {
        int answer = searchInRotatedArr(nums,target);
        return answer;
    }
};