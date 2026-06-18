class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        set<int>st;
        for(auto i: nums){
            st.insert(i);
        }
        int n = nums.size()+1;
        for(int i = 1;i<=n;i++){
            if(st.find(i)==st.end()) return i;
        }
        return n;
    }
};