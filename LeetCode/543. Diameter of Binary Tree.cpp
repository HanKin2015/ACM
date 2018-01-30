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
    int maxn = -2;

    int Height(TreeNode *root) {
        int lh, rh;
        if(root == NULL) return 0;
        lh = Height(root->left);
        rh = Height(root->right);
        if(lh > rh) return lh + 1;
        else return rh + 1;
    }

    int get_diameter(TreeNode *root) {
        int lh, rh;
        if(root == NULL) return 0;
        lh = Height(root->left);
        rh = Height(root->right);
        return lh + rh + 1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        int diameter = get_diameter(root);
        if(diameter > maxn) {
            maxn = diameter;
        }
        diameterOfBinaryTree(root->left);
        diameterOfBinaryTree(root->right);
        return maxn - 1;
    }
};