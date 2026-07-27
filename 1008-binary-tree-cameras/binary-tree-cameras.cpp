/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int solve(TreeNode* root,int &camera){
        if(!root) return 1;

        int left = solve(root->left,camera);
        int right = solve(root->right,camera);

        if(left == 0 || right == 0){
            camera++;
            return 2;
        }
        if(left ==2 || right == 2){
            return 1;
        }
        return 0;
    }
    int minCameraCover(TreeNode* root) {
        int camera = 0;
        int cameraState = solve(root,camera);
        if(cameraState == 0) camera++;

        return camera;
    }
};