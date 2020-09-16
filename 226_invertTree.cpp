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
    TreeNode* invertTree(TreeNode* root) {
        preorderTraversal(root);
        return root;

    }
    void ChangeNode(TreeNode* Node){
        TreeNode *p;
        p=Node->right;
        Node->right=Node->left;
        Node->left=p;
    }
    void preorderTraversal(TreeNode* root) {
        stack<TreeNode*> S;
        TreeNode* rt = root;
        while(rt || S.size()){
            while(rt){
                ChangeNode(rt);
                S.push(rt->right);
                rt=rt->left;
            }
            rt=S.top();S.pop();
        }
    }
};
