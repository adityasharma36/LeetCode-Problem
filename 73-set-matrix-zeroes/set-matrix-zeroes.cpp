class Solution {
public:
    void setRowZero(vector<vector<int>>& nums,int row){
        for(int i = 0;i<nums.size();i++){
            if(nums[row][i]!=0){
                nums[row][i]=-1;
            }
        }
    }
    void setColZero(vector<vector<int>>& nums,int col){
        for(int i = 0;i<nums.size();i++){
            if(nums[i][col]!=0){
                nums[i][col]=-1;
            }
        }
    }
    void zeroesSet(vector<vector<int>>& nums){

        for(int i = 0;i<nums.size();i++){
            for(int j = 0;j<nums.size();j++){
                if(nums[i][j]==0){
                    setRowZero(nums,i);
                    setColZero(nums,j);
                }
            }
        }

        for(int i = 0;i<nums.size();i++){
            for(int j = 0;j<nums.size();j++){
                if(nums[i][j]==-1){
                    nums[i][j]=0;
                }
            }
        }
    }
    void betterSol(vector<vector<int>>& nums){
        int row = nums.size();
        int col = nums[0].size();

        vector<int> rowArr(row,0);
        vector<int>colArr(col,0);

        for(int i = 0;i<row;i++){
            for(int j = 0;j<col;j++){
                if(nums[i][j]==0){
                    rowArr[i]=1;
                    colArr[j]=1;
                }
            }
        }

        for(int i = 0;i<row;i++){
            for(int j = 0;j<col;j++){
                if(rowArr[i]==1 || colArr[j]==1){
                    nums[i][j]=0;
                }
            }
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        // zeroesSet(matrix);
        betterSol(matrix);
    }
};