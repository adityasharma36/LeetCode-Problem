class Solution {
public:
    int beauty(vector<int>&temp){
        int mf = INT_MIN;
        int lf = INT_MAX;
        for(int i = 0;i<26;i++){
            if(temp[i]>0){
                if(mf<temp[i]){
                    mf = temp[i];
                }
                if(lf>temp[i]){
                    lf = temp[i];
                }
            }
        }
        return mf-lf;
    }
    int beautySum(string s) {
      
        int sumBeauty = 0;
        for(int i = 0;i<s.size();i++){
              vector<int>temp(26,0);
              for(int j = i;j<s.size();j++){
                  temp[s[j]-'a']++;
                  sumBeauty+=beauty(temp);
              }
            
        }
        return sumBeauty;
    }
};