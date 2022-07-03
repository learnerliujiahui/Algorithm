/*
 * @lc app=leetcode.cn id=897 lang=cpp
 *
 * [897] 递增顺序查找树
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
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* cur = root;
        TreeNode* pre = nullptr;
        TreeNode* dummy = new TreeNode(0);
        TreeNode* tail = dummy;
        while(cur != nullptr){
            pre = cur->left;
            if(pre != nullptr){
                while(pre->right != nullptr && pre->right != cur){
                    pre = pre->right;
                }
                if(pre->right == nullptr){
                    pre->right = cur;
                    cur = cur->left;
                    continue;
                } else {
                    cur->left = nullptr;
                }
            }
            tail->right = cur;
            tail = cur;
            cur = cur->right;
        }
        return dummy->right;
    }
};
// @lc code=end

