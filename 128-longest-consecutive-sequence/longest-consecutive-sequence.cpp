class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        if(nums.empty()) return 0;

        int count = 1;
        int consecutive = 1;

        sort(nums.begin(),nums.end());

        for(int i = 1;i<nums.size();i++){

            if(nums[i]==nums[i-1]){

                continue;
            }

            else if( nums[i] == nums[i-1] + 1){

                count++;

            }
            
            else{
                    consecutive = max(count,consecutive);

                    count = 1;
            }
        }

        // sabse yahi pe faste h 
        return max(consecutive,count);
    }
};