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
    int maxPathSum(TreeNode* root) {
        int sum = INT_MIN;
        findMax(root,sum);
        return sum;
    }
private:
    int findMax(TreeNode* root, int &sum){
        if(root == NULL) return 0;

        int lh = max(0, findMax(root->left, sum));
        int rh = max(0, findMax(root->right, sum));

        sum = max(sum, lh + rh + root -> val);

        return root->val + max(lh, rh);
    }
};