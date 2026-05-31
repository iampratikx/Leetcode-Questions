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

  /*
class Solution {
    void postorder(TreeNode* node, vector<int>& ans){
        if(node == NULL){
            return;
        }
        postorder(node -> left,ans);
        postorder(node -> right,ans);
        ans.push_back(node->val);
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        postorder(root,ans);
        return ans;
    }
};
*/

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postorder;
        if(root == NULL) return postorder;

        stack<TreeNode*> s1;
        stack<TreeNode*> s2;

        if(root!= NULL){
                s1.push(root);
        }
        while(!s1.empty()){
            TreeNode* node = s1.top();
            s1.pop();
            s2.push(node);
            if(node -> left != NULL) s1.push(node -> left);
            if(node -> right != NULL) s1.push(node -> right);
        }
        while(!s2.empty()){
            postorder.push_back(s2.top() -> val);
            s2.pop();
        }
        return postorder;
    }
};