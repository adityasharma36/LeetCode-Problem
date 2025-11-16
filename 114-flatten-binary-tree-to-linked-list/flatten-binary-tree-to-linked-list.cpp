class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* temp = root;

        while (temp) {
            if (temp->left) {
                // Step 1: Find rightmost node of left subtree
                TreeNode* prev = temp->left;
                while (prev->right) {
                    prev = prev->right;
                }

                // Step 2: Connect right subtree to rightmost node
                prev->right = temp->right;

                // Step 3: Move left subtree to right
                temp->right = temp->left;
                temp->left = nullptr;
            }

            // Move forward
            temp = temp->right;
        }
    }
};
