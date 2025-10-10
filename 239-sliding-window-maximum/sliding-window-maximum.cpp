class Solution {
public:
    vector<int> slidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        vector<int> ans;
        
        // Step 1: Process first window
        for(int i = 0; i < k; i++) {
            while(!q.empty() && nums[q.back()] <= nums[i])
                q.pop_back();
            q.push_back(i);
        }
        ans.push_back(nums[q.front()]);
        
        // Step 2: Process rest of the windows
        for(int i = k; i < nums.size(); i++) {
            // remove elements out of this window
            if(!q.empty() && q.front() <= i - k)
                q.pop_front();
            
            // remove smaller elements
            while(!q.empty() && nums[q.back()] <= nums[i])
                q.pop_back();
            
            q.push_back(i);
            ans.push_back(nums[q.front()]);
        }
        
        return ans;
    }

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        return slidingWindow(nums, k);
    }
};
