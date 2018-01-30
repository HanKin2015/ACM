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
    int arr[100005], dex = 0;
    void visit(TreeNode *root) {
        if(root == NULL) return ;
        arr[dex++] = root->val;
        visit(root->left);
        visit(root->right);
        return ;
    }
    
    bool flag = true;
    
    TreeNode* convertBST(TreeNode* root) {
        if(flag) {
            visit(root);
            flag = false;
        }
        if(root == NULL) return NULL;
        int sum = root->val;
        for(int i = 0; i < dex; i++) {
            if(arr[i] > root->val) {
                sum += arr[i];
            }
        }
        root->val = sum;
        convertBST(root->left);
        convertBST(root->right);
        return root;
    }
};