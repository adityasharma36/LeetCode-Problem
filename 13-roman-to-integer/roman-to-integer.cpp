class Solution {
public:
    int romanToInteger(string s){

      unordered_map<char,int> mp{{'I',1}, {'V',5}, {'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
        int result = 0;
      for(int i = 0;i<s.size();i++){
        int curr = mp[s[i]];
        int next = (i+1< s.size()) ? mp[s[i+1]] : 0;

        if(curr<next){
            result-=curr;
        } else{
            result +=curr;
        }
      }
      
      return result;
      
         }
    int romanToInt(string s) {
        return romanToInteger(s);
    }
};