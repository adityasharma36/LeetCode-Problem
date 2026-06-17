class Solution {
public:
    char processStr(string s, long long k) {
int n = s.length();
        vector<long long> lengths(n);
        long long current_len = 0;

        
        for (int i = 0; i < n; ++i) {
            if (s[i] >= 'a' && s[i] <= 'z') {
                current_len++;
            } else if (s[i] == '*') {
                if (current_len > 0) current_len--;
            } else if (s[i] == '#') {
                current_len *= 2;
            } else if (s[i] == '%') {
             
            }
            lengths[i] = current_len;
        }

       
        if (k >= current_len) {
            return '.';
        }

   
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] >= 'a' && s[i] <= 'z') {
              
                if (k == lengths[i] - 1) {
                    return s[i];
                }
            } else if (s[i] == '#') {
             
                long long prev_len = (i > 0) ? lengths[i - 1] : 0;
                if (prev_len > 0) {
                    k %= prev_len;
                }
            } else if (s[i] == '%') {
             
                long long cur_len = lengths[i];
                k = cur_len - 1 - k;
            }
      
        }

        return '.';
    }
};