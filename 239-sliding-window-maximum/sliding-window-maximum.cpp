class Solution {
public:
    vector<int> slidingWindow(vector<int>&nums,int k){
        deque<int>dq;
        vector<int>ans;
        int n = nums.size();

        for(int i = 0;i<k;i++){
            if(!dq.empty()){
                while(!dq.empty() && nums[dq.back()] <= nums[i]){
                    dq.pop_back();
                }
                cout<<dq.front()<<endl;
            }
            dq.push_back(i);

        }
    

        for(int i = k;i<n;i++){

            // additon of element 
            if(!dq.empty()){

                int index = dq.front();

                int ele = nums[index];

                ans.push_back(ele);

                cout<<"here is properly working 0"<<endl;

            }

            // removal of element 

            if(!dq.empty() && dq.front()<=i-k){
                dq.pop_front();
                cout<<"here is properly workind 1"<<endl;
            }

            // add new present element in queue

            while(!dq.empty() && nums[dq.back()]<=nums[i]){
                dq.pop_back();
                cout<<"here properly working 2"<<endl;
            }
            dq.push_back(i);
        }
        if(!dq.empty()){
            ans.push_back(nums[dq.front()]);
            cout<<"here is properly 3"<<endl;
        }

        return ans;
    }
    vector<int>littleOptimse(vector<int>& nums,int k){
        deque<int>dq;
        vector<int>ans;
        int n = nums.size();
        for(int i = 0;i<n;i++){

            // removal of new Element 
            if(!dq.empty() && dq.front()==i-k){
                dq.pop_front();
            }

            // addition of new Element

            while(!dq.empty() && nums[dq.back()] <= nums[i]){
                dq.pop_back();          
            }
        
            dq.push_back(i);

        // addition of element in ans;
        if(i>=k-1){
            ans.push_back(nums[dq.front()]);
        }
        }
        return ans;
    }
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // return slidingWindow(nums,k);
        return littleOptimse(nums,k);
    }
};