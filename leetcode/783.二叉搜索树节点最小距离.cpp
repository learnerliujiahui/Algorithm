/*
 * @lc app=leetcode.cn id=783 lang=cpp
 *
 * [783] 二叉搜索树节点最小距离
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
    void DFS(TreeNode* root, int* pre, int* minNum) {
        if(root == nullptr)
            return;
        DFS(root->left, pre, minNum);
        *minNum = (abs(root->val - *pre) < *minNum) ? abs(root->val - *pre): *minNum;
        *pre = root->val;
        DFS(root->right, pre, minNum);
    }
    int minDiffInBST(TreeNode* root) {
        int pre = INT32_MAX;
        int minNum = INT32_MAX;
        DFS(root, &pre, &minNum);
        return minNum;
    }
};
// @lc code=end

