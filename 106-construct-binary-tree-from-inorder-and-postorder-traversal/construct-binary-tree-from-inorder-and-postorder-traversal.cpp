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
    // Helper function to recursively build the tree
    TreeNode* buildTree(vector<int>& postorder, int postStart, int postEnd,
                        vector<int>& inorder, int inStart, int inEnd,
                        map<int, int> &inmap) {
        // Step 6: Base case - invalid range
        if (inStart > inEnd || postStart > postEnd)
            return NULL;
        
        // Step 2: Last element in postorder is the root
        TreeNode* root = new TreeNode(postorder[postEnd]);

        // Step 3: Find root position in inorder using hashmap
        int inRoot = inmap[root->val];
        
        // Step 4: Calculate number of nodes in left subtree
        int numsleft = inRoot - inStart;

        // Step 5: Recursively build left and right subtrees
        // Left subtree: first numsleft elements in postorder
        root->left = buildTree(postorder, postStart, postStart + numsleft - 1,
                               inorder, inStart, inRoot - 1, inmap);
        
        // Right subtree: remaining elements before root in postorder
        root->right = buildTree(postorder, postStart + numsleft, postEnd - 1,
                                inorder, inRoot + 1, inEnd, inmap);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // Step 1: Build hashmap for O(1) inorder index lookup
        map<int, int> inmap;
        for (int i = 0; i < inorder.size(); i++) {
            inmap[inorder[i]] = i;
        }
        
        // Start recursive tree construction
        TreeNode* root = buildTree(postorder, 0, postorder.size() - 1, 
                                   inorder, 0, inorder.size() - 1, inmap);
        return root;
    }
};