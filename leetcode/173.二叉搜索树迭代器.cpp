/*
 * @lc app=leetcode.cn id=173 lang=cpp
 *
 * [173] 二叉搜索树迭代器
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
class BSTIterator {
private:
    int index;
    std::vector<int> res;
public:
    void DFS(TreeNode* p_root) {
        if(p_root == nullptr)
            return;
        DFS(p_root->left);
        res.push_back(p_root->val);
        DFS(p_root->right);
    }
    BSTIterator(TreeNode* root) {
        index = 0;
        DFS(root);
    }
    
    int next() {
        return res[index++];
    }
    
    bool hasNext() {
        if(index < res.size())
            return true;
        else
            return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
// @lc code=end

