class Solution {
public:
    int strSub(string haystack, string needle) {

        if (haystack.length() < needle.length())
            return -1;

        for (int i = 0; i < haystack.length(); i++) {
            char ch = haystack[i];
            if (ch == needle[0]) {
                int temp = i;
                int j = 0;
                while (j < needle.size() && temp < haystack.length() &&
                       haystack[temp] == needle[j]) {
                        if (j + 1 == needle.length())
                        return i;
                        
                    temp++;
                    j++;
                    
                }
            }
        }
        return -1;
    }
    int strStr(string haystack, string needle) {
        return strSub(haystack, needle);
    }
};