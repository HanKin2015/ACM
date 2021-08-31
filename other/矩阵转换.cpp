#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
 	TreeNode *right;
	//TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class FindElements {
public:
	int isTrue[1000005] = { 0 };
    FindElements(TreeNode* root) {
        queue<TreeNode> Q;
        Q.push(root);
        Q.val = 0;
        isTrue[0] = 1;
        while(!Q.empty()) {
        	TreeNode cur = Q.front();
        	Q.pop();
        	if (cur->left != NULL) {
        		Q.push(cur->left);
        		cur->left.val = cur.val * 2 + 1;
        		isTrue[cur->left.val] = 1;
        	}
        	if (cur->right != NULL) {
        		Q.push(cur->right);
        		cur->right.val = cur.val * 2 + 2;
        		isTrue[cur->right.val] = 1;
        	}
        }
    }
    
    bool find(int target) {
        if (isTrue[target]) return true;
        return false;
    }
};

int main()
{
	TreeNode root;


	FindElements* obj = new FindElements(root);
	bool param_1 = obj->find(target);
 	return 0;
 }