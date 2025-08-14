class Solution {
public:
    vector<int> pascalTriangle(int row){
        
        int ans = 1;

        vector<int>insertArr;

        insertArr.push_back(1);

        for(int col = 1;col<row;col++){

            ans = ans*(row-col);

            ans = ans/col;

            insertArr.push_back(ans);
        }
        return insertArr;
    }
    vector<vector<int>> generate(int numRows) {

        vector<vector<int>> Arr;

        for(int i = 1;i<=numRows;i++){

            Arr.push_back(pascalTriangle(i));

        }

        return Arr;
        
    }
};