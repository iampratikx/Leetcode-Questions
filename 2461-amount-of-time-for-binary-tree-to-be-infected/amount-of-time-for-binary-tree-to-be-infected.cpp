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
    TreeNode* make_parent(TreeNode* root, map<TreeNode*,TreeNode*> &parent_tarck,int start){
        
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* res = NULL;
        while(!q.empty()){
            TreeNode* current = q.front();
            q.pop();
            if(current -> val == start) res = current;
            if(current -> left){
                parent_tarck[current->left] = current;
                q.push(current->left);
            }
            if(current -> right){
                parent_tarck[current->right] = current;
                q.push(current->right);
            }
        }
        return res;
    }
    int findMaxDis(map<TreeNode*,TreeNode*> &parent_tarck,TreeNode* target){
        
        queue<TreeNode*> q;
        q.push(target);
        map<TreeNode*,bool> visited;
        visited[target] = true;
        int maxi = 0;
        while(!q.empty()){
            int size = q.size();
            int fl = 0;

            for(int i=0; i<size; i++){
                TreeNode* current = q.front();
                q.pop();

                if(current -> left && !visited[current->left]){
                    fl = 1;
                    q.push(current->left);
                    visited[current->left] = true;
                }

                if(current -> right && !visited[current->right]){
                    fl = 1;
                    q.push(current->right);
                    visited[current->right] = true;
                }
                if(parent_tarck[current] && !visited[parent_tarck[current]]){
                    fl = 1;
                    q.push(parent_tarck[current]);
                    visited[parent_tarck[current]] = true;   
                }
            }
            if(fl) maxi++;
        }
        return maxi;
    }
public:
    int amountOfTime(TreeNode* root, int start) {
        if(root == NULL)
            return 0;
        map<TreeNode*,TreeNode*> parent_tarck;
        TreeNode* target = make_parent(root,parent_tarck,start); 
        int maxi = findMaxDis(parent_tarck,target);
        return maxi;
    }
};