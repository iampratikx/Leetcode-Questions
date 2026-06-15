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
    bool checkTree(TreeNode* root) {
        if(root == NULL) return true;
        
        if(root->left == NULL && root->right == NULL)
        return true;
        
        if(!checkTree(root->left))
        return false;

        if(!checkTree(root->right))
            return false;

        int tot = 0;
        if(root->left)
        tot += root->left->val;

        if(root->right)
            tot += root->right->val;

        if(root->val != tot)
            return false;

        return true;
    }
};