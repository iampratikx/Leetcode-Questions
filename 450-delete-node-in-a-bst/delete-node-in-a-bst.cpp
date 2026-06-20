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
    // Left subtree ka sabse right node return karega
    TreeNode* findlast(TreeNode* node) {
        node = node->left;

        while (node->right != NULL) {
            node = node->right;
        }

        return node;
    }

public:
    TreeNode* deleteNode(TreeNode* root, int key) {

        if (root == NULL) return NULL;

        TreeNode* curr = root;
        TreeNode* currprev = NULL;

        // Node find karo
        while (curr != NULL) {

            if (curr->val == key)
                break;

            currprev = curr;

            if (key < curr->val)
                curr = curr->left;
            else
                curr = curr->right;
        }

        // Key nahi mili
        if (curr == NULL)
            return root;

        // Leaf node
        if (curr->left == NULL && curr->right == NULL) {

            if (currprev == NULL)
                return NULL;

            if (currprev->left == curr)
                currprev->left = NULL;
            else
                currprev->right = NULL;

            delete curr;
            return root;
        }

        // Sirf right child hai
        if (curr->left == NULL) {

            if (currprev == NULL)
                return curr->right;

            if (currprev->left == curr)
                currprev->left = curr->right;
            else
                currprev->right = curr->right;

            delete curr;
            return root;
        }

        // Sirf left child hai
        if (curr->right == NULL) {

            if (currprev == NULL)
                return curr->left;

            if (currprev->left == curr)
                currprev->left = curr->left;
            else
                currprev->right = curr->left;

            delete curr;
            return root;
        }

        // Dono child hain
        TreeNode* rightchild = curr->right;
        TreeNode* lastnode = findlast(curr);

        // Right subtree ko left subtree ke last node se jodo
        lastnode->right = rightchild;

        // Root delete ho raha hai
        if (currprev == NULL) {
            TreeNode* newRoot = curr->left;
            delete curr;
            return newRoot;
        }

        // Parent ko curr ke left subtree se connect karo
        if (currprev->left == curr)
            currprev->left = curr->left;
        else
            currprev->right = curr->left;

        delete curr;

        return root;
    }
};