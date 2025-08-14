class Solution {
public:
    int spaceOptimisation(vector<int> & nums){

        sort(nums.begin(),nums.end());
        int start = 0;

        int end = 0;

        int count = 0;

        int elment = nums[start];

        while(end<nums.size()){

            if(nums[start]== nums[end]){

                end++;

            }
            else{

                start = end;
                
            }

            
            int leng = end-start +1;

            if(count <leng){

                count = leng;

                elment = nums[start];

                }
        }

        return elment;

    }
    int timeOptimisation(vector<int> & nums){
        unordered_map<int,int> um;

        for(int i = 0;i<nums.size();i++){
            um[nums[i]]++;
        }
        int maxElm = 0;
        int count = 0;
        for(auto i : um){
            if(count<i.second){
                count = i.second;
                maxElm = i.first;
            }

        }
        return maxElm;
    }
    int codeOptimisation(vector<int>& nums){
        int count = 0;
        int ele = INT_MIN;
        sort(nums.begin(),nums.end());
        for(int i = 0;i<nums.size();i++){
            if(count == 0){
                count = 1;
                ele = nums[i];
            }
            else if(ele == nums[i]){
                count++;
            }else {
                count--;
            }
        }
        count = 0;
        for(int i = 0;i<nums.size();i++){
            if(nums[i] == ele) count++;
        }
        int len = nums.size();
        int majoCount   = len / 2 + 1;

        if(count >= majoCount) return ele;

        return -1;
    }
    int majorityElement(vector<int>& nums) {
        // return spaceOptimisation(nums);
        // return timeOptimisation(nums);

        return codeOptimisation(nums);
    }
};