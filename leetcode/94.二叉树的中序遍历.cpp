/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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
private:
    std::vector<int> res;
public:
    void DFS(TreeNode* p_root) {
        //递归终止条件
        if(p_root == nullptr)
            return;
        DFS(p_root->left);
        res.push_back(p_root->val);
        DFS(p_root->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        DFS(root);
        return res;
    }
};
// @lc code=end

