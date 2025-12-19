class Solution {
public:
    int answer(string s){
        unordered_map<char,int> um;
        um['I'] = 1;
        um['V'] = 5;
        um['X'] = 10;
        um['L'] = 50;
        um['C'] = 100;
        um['D'] = 500;
        um['M'] = 1000;

        int result = 0;

        for(int i = 0;i<s.size();i++){
            int curr = um[s[i]];

            int nextVal = (i+1< s.size()) ? um[s[i+1]] : 0;

            if(curr< nextVal) {
                result-= curr;
            }else{
                result+=curr;
            }
        }
        return result;
    }
    int romanToInt(string s) {
        return answer(s);
    }
};