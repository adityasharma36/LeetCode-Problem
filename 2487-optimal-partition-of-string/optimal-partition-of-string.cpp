class Solution {
public:
    int partitionString(string s) {
        unordered_map<char, int> um;

        int j = 0;
        int cnt = 0;

        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];

            if (um.find(ch) != um.end() && um[ch] >= j) {
                cnt++;
                j = i;
            }

            um[ch] = i;
        }

        return cnt + 1;
    }
};