class Solution {
public:
    // bool checking(vector<int>& nums){
    //     vector<int> newArr;
    //     int ind = -1;
    //     for(int i = 1;i<nums.size();i++){
    //         if(nums[i]< nums[i-1]){
    //             ind = i;
    //             break;
    //         }
    //     }

    //     cout<<"index "<< ind<<endl;

    //     if(ind == -1) return true;

    //     for(int i = ind;i<nums.size();i++){
    //         newArr.push_back(nums[i]);
    //     }

    //     for(auto i :newArr){
    //         cout<<i<<" ";
    //     }
    //     cout<<endl;

    //     for(int i = 0;i<ind;i++){
    //         newArr.push_back(nums[i]);
    //     }

    //      for(auto i :newArr){
    //         cout<<i<<" ";
    //     }


    //     for(int i = 1;i<nums.size();i++){
    //         if(newArr[i]<newArr[i-1]) return false;
    //     }

    //     return true;
    // }   

    bool checking(vector<int>& nums){
        int count = 0;
        for(int i = 0;i<nums.size();i++){
            if(nums[i]> nums[(i+1) % nums.size()]){
                count++;
            }
            if(count>1) return false;
        }
        return true;
    }
    bool check(vector<int>& nums) {
        return checking(nums);
    }
};