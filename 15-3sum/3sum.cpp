class Solution {
public:
    vector<vector<int>> solveByBF(vector<int>& nums){

        // sabse phele array ko sort kiya 

        //  phir ek 2d array create kiya usmae apon ko store karna  h 
        // ek unordered_set bhi create kiya uska kam ki same element ko waps nhi aane dena 

        // and uske baad brute force approach use kiya usmae teen loop kiya 
        //  same element nhi chaiye to apon ne sabko next se start kiya h 
        
        // and akri me print kar dena 

         sort(nums.begin(),nums.end());

        vector<vector<int>>ans;

        set<vector<int>>st;

        for(int i = 0;i<nums.size();i++){

            for(int j = i+1;j<nums.size();j++){

                for(int k = j+1 ;k<nums.size();k++){

                    if(nums[i]+ nums[j]+ nums[k]== 0){

                        vector<int> temp = {nums[i],nums[j],nums[k]};

                        if(st.find(temp) == st.end()){

                            st.insert(temp);

                            ans.push_back(temp);

                        }
                    }
                }
            }
        }
        return ans;
    }

    vector<vector<int>> solveByOS(vector<int>& nums){

        // brute force + hashing 

        // isme sabse pehele array ko sort kiya 
        //  phir unique set ke liye set function create kiya 

        //  nums[i]+ nums[j]+ num[k]= 0;
        //  nums[k]= -nums[i]-nums[j];

        // phir element find karne ke  liye ek set create uska kaam h 
        // find karna ki value presenet h ki nhii agar h to usko dalo unique set me
        //  and unique set ko dalo array me

        sort(nums.begin(),nums.end());
        
        set<vector<int>>st;

        for(int i = 0;i<nums.size();i++){

            int ele = -nums[i];

            set<int>un;

            for(int j = i+1;j<nums.size();j++){

                int thirdEle = ele-nums[j];

                if(un.find(thirdEle)!= un.end()){

                    vector<int>temp = {nums[i],nums[j],thirdEle};

                    st.insert(temp);

                }

                un.insert(nums[j]);

            }
        }

         vector<vector<int>>ans(st.begin(),st.end());

         return ans;
    }

    vector<vector<int>> solveByOS2(vector<int>& nums){
        // two pointer approach h 

         vector<vector<int>> answer;

        sort(nums.begin(),nums.end());

        for(int i = 0;i<nums.size();i++){

            if(i>0 && nums[i] == nums[i-1]) continue ;

            int j = i+1, k = nums.size()-1;

            while(j<k){

                int sum = nums[i] + nums[j]+ nums[k];

                if(sum<0){

                   j++;

                }

                else if(sum>0) k--;

                else{
                     answer.push_back({nums[i],nums[j],nums[k]});

                    j++ , k--;
                

                while(j<k && nums[j]== nums[j-1]) j++;

                while(j<k && nums[k]== nums[k+1]) k--;

                }

            }

        }

        return answer;
    }


    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> answer = solveByOS2(nums);
        return answer;
    }
};