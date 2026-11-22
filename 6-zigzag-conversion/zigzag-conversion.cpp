class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        int cycleLen = 2 * numRows - 2;
        int n = s.size();
        string res;
        for(int row = 0; row < numRows; row++){
            int i = row;
            bool toggle = false;
            while(i < n){
                res += s[i];
                i += (row == 0 || row == numRows-1)? cycleLen : toggle? 2 * row : cycleLen - 2 * row;
                toggle = !toggle;
            }
        }
        return res;
    }
};