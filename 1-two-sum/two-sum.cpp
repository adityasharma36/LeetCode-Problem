class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        // sabka logic hota hai
        // unordered_map<int,int> um;

        // for(int i = 0;i<nums.size();i++){
        //     int ele = nums[i];
        //     int check = target - ele;
        //     if(um.find(check) != um.end()){
        //         return {um[check],i};
        //     }
        //     um[ele] = i;
        // }
        // return {-1,-1};

        

        //  Method 2 --> Mast Code hai

        unordered_map<int,vector<int>> um;
        for(int i = 0;i<nums.size();i++){
            int ele = nums[i];
            um[ele].push_back(i);
        }

        for(int i = 0;i<nums.size();i++){
            int curEle = nums[i];
            int required = target-nums[i];

            if(um.find(required) != um.end()){

                // found

                //  1 element ko 1 hi baar use karna hai
                // duplicate element wale case ko bhi handle karna hai


                // duplicate element wala case
                if(curEle == required && um[curEle].size() == 1){

                    // iska matlab main same element ko 2 baar use kar raha hu
                    continue;

                }

                if(required == curEle && um[curEle].size() > 1){

                    //  duplicate case 
                    return {um[curEle][0], um[curEle][1]};

                }
                else{
                    
                    // reuired != current
                    return {i,um[required][0]};
                }
            }
        }
        return {-1,-1};
    }
};