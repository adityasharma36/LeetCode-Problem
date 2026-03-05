class Solution {
public:
    vector<int>pascalTriFnc(int numRows){
        vector<int>temp;
        temp.push_back(1);
        int ans = 1;

        for(int col = 1;col<numRows;col++){

            ans = ans*(numRows-col);
            ans = ans/col;
            temp.push_back(ans);
        }
        return temp;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;

        for(int i = 1;i<=numRows;i++){
            vector<int>temp = pascalTriFnc(i);
            ans.push_back(temp);
        }
        return ans;
    }
};