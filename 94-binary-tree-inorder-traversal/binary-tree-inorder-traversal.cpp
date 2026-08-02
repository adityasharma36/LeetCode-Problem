
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        
        TreeNode* curr = root;

        while(curr){
            if(!curr->left){
                ans.push_back(curr->val);
                curr = curr->right;
            }else{
                TreeNode* prec = curr->left;
                while( prec->right != curr && prec->right){
                    prec = prec->right;
                }
                if(prec->right == nullptr){
                    prec->right = curr;
                    curr = curr->left;
                }else{
                    ans.push_back(curr->val);
                    prec->right = nullptr;
                    curr = curr->right;
                }
            }
        }
        return ans;
    }
};