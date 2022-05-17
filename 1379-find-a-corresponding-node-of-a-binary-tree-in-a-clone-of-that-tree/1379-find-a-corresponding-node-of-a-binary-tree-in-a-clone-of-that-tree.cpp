/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* f(TreeNode* root,TreeNode* target){
        if(root == NULL){
            return NULL;
        }
        
        if(root->val == target->val){
            return root;
        }
        TreeNode* b = f(root->right,target);
        TreeNode* a = f(root->left,target);
        return a?a:b;
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        return f(cloned,target);
    }
};