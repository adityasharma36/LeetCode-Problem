class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int,int> um;

        for (int i : nums) {
            if (um[i] >= 1) {   // already seen
                return i;
            }
            um[i]++;
        }
        return -1;
    }
};
