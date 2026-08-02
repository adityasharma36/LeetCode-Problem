
class Solution {
public:
  
    void flatten(TreeNode* root) {
        TreeNode* curr = root;
        while(curr ){
            if(curr->left){
            TreeNode* prec = curr->left;
            while(prec->right){
                prec = prec->right;
            }
            prec->right = curr->right;
            curr->right = curr->left;
            curr->left = nullptr;
            }
            curr = curr->right;

        }
    }
};