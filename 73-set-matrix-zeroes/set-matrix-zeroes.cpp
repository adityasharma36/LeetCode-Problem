class Solution {
public:
    void setCol(vector<vector<int>>&temp,int col){
        for(int i =0;i<temp.size();i++){
            temp[i][col]= 0;
        }
    }
    void setRow(vector<vector<int>>&temp,int row){
        int n = temp[0].size();
        for(int i =0;i<n;i++){
            temp[row][i]= 0;
        }
    }
    void bruteForce(vector<vector<int>>& matrix){
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>>temp(m,vector<int>(n,1));
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(matrix[i][j]==0){
                    setCol(temp,j);
                    setRow(temp,i);
                }
            }
        }
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){

                if(temp[i][j]==0){

                matrix[i][j]= 0;
                }
            }
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        bruteForce(matrix);
    }
};