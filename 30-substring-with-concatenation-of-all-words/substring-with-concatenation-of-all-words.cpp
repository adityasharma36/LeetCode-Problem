class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        if (words.empty()) return ans;

        unordered_map<string,int> freq;
        for (auto &w : words) freq[w]++;

        int wordLen = words[0].length();
        int totalWords = words.size();
        int n = s.length();

        for (int offset = 0; offset < wordLen; offset++) {
            unordered_map<string,int> visited;
            int count = 0;

            for (int i = offset; i + wordLen <= n; i += wordLen) {
                string sub = s.substr(i, wordLen);

                if (freq.find(sub) == freq.end()) {
                    visited.clear();
                    count = 0;
                } else {
                    visited[sub]++;
                    count++;

                    while (visited[sub] > freq[sub]) {
                        string left = s.substr(i - (count - 1) * wordLen, wordLen);
                        visited[left]--;
                        count--;
                    }

                    if (count == totalWords) {
                        ans.push_back(i - (count - 1) * wordLen);
                    }
                }
            }
        }
        return ans;
    }
};
