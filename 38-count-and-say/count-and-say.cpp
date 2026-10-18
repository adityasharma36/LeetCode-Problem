class Solution {
public:
    string countSay(int n){
        if(n == 1){
            return "1";
        }

        string ans = countSay(n-1);
        int j = 0;
        int i = 0;
        string temp = "";
        while(j<ans.size()){
              if(ans[i] != ans[j]){
                int len = j-i;
          temp += to_string(len) + ans[i];
                i = j;
            }
            j++;
        }
        int len =j-i;
     temp += to_string(len) + ans[i];
        return temp;
    }
    string countAndSay(int n) {
        return countSay(n);
    }
};