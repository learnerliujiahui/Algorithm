/*
 * @lc app=leetcode.cn id=100 lang=cpp
 *
 * [100] 相同的树
 */

// @lc code=start
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
    bool DFS(TreeNode* p, TreeNode* q) {
        // 递归终止条件
        if (!p && !q)
            return true;
        else if ((p&&q)&& p->val == q->val) {
            return DFS(p->left, q->left) && DFS(p->right, q->right);
        }
        else
            return false;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return DFS(p,q);
    }
};
// @lc code=end

