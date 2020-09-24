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
    int base, count, maxCount;
    vector<int> answer;

    void update(int x) {
        if (x == base) {
            ++count;
        } else {
            count = 1;
            base = x;
        }
        if (count == maxCount) {
            answer.push_back(base);
        }
        if (count > maxCount) {
            maxCount = count;
            answer = vector<int> {base};
        }
    }

    vector<int> findMode(TreeNode* root) {
        TreeNode *cur = root, *pre = nullptr;
        while (cur) {
            if (!cur->left) {//判断左结点是否为空
                update(cur->val);//若为空则直接遍历右结点
                cur = cur->right;
                continue;
            }
            pre = cur->left;//遍历左结点
            while (pre->right && pre->right != cur) {//遍历当前结点的左节点的最右结点，如果为空则没有链接，如果与cur相同则说明已经链接了。
                pre = pre->right;
            }
            if (!pre->right) {//没有链接就说明还没有遍历到。
                pre->right = cur;
                cur = cur->left;
            } else {//已经链接了则已遍历，需要将其去掉
                pre->right = nullptr;
                update(cur->val);//传入值，记录频率
                cur = cur->right;
            }
        }
        return answer;
    }
};
