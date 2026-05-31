class Solution {
public:
    void transpose(vector<vector<int>>& matrix){
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i = 0;i<m;i++){
            for(int j = i;j<n;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        // cout<<"complte"<<endl;
    }
    void rotateMar(vector<vector<int>>& matrix){
        int n = matrix.size();
        for(int i = 0;i<n;i++){
            int start = 0;
            int end = matrix[i].size()-1;
            while(start<end){
                swap(matrix[i][start],matrix[i][end]);
                start++;
                end--;
            }
        }
    }
    void rotate(vector<vector<int>>& matrix) {
        transpose(matrix);
        rotateMar(matrix);
    }
};