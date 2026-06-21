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

    bool subtree(TreeNode* root, long long mx, long long mn){
        if(root == NULL) return true;

        // Current node ki value range ke andar honi chahiye
        if(root->val >= mx || root->val <= mn)
            return false;

        // Left subtree ke liye max = current node value
        // Right subtree ke liye min = current node value
        return subtree(root->left, root->val, mn) &&
               subtree(root->right, mx, root->val);
    }

public:
    bool isValidBST(TreeNode* root) {

        // CHANGE 1:
        // Tumne INT_MIN aur INT_MIN pass kiya tha
        // Jisse root hi fail ho ja raha tha

        // OLD:
        // long max = INT_MIN;
        // int min = INT_MIN;

        // NEW:
        // Starting range (-infinity, +infinity)
        return subtree(root, LLONG_MAX, LLONG_MIN);

        // CHANGE 2:
        // long ki jagah long long use kiya
        // Taaki INT_MIN / INT_MAX edge cases handle ho jaye
    }
};