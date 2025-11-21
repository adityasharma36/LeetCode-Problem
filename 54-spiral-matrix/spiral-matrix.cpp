class Solution {
public:
    
    vector<int> orderSpiral(vector<vector<int>>& arr){
        vector<int> ans;

        int row = arr.size();
        int col = arr[0].size();

        int count = 0;

        int startRow = 0;
        int startCol= 0;
        int endingRow = row-1;
        int endingCol = col-1;

        int totalEle = row* col;

        while(count< totalEle){

            // print first Row 

            for(int i = startCol;i<=endingCol && count<totalEle ;i++){
                ans.push_back(arr[startRow][i]);
                count++;
            }
            startRow++;

            // last Col 
            for(int i = startRow ;i<=endingRow && count<totalEle ;i++){
                ans.push_back(arr[i][endingCol]);
                count++;
            }
            endingCol--;

            // last Row ;

            for(int i = endingCol;i>=startCol && count<totalEle;i--){
                ans.push_back(arr[endingRow][i]);
                count++;
            }
            endingRow--;
            // first col;
            for(int i = endingRow;i>=startRow && count<totalEle;i--){
                ans.push_back(arr[i][startCol]);
                count++;
            }
            startCol++;
        }
        return ans;
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        return orderSpiral(matrix);
        
    }
};