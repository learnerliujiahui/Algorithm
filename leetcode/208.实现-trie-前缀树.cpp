/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树)
 * Date: 2021-04-14
 */

// @lc code=start
#include<iostream>
#include<vector>
#include<string>
class Trie {
private:
    bool isEnd;
    Trie* next[26];  // 数组指针
public:
    /** Initialize your data structure here. */
    Trie() {
        // 将其理解为多叉树
        isEnd = false;
        memset(next, 0, sizeof(next));
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* node = this;  // 当前节点标记为根结点
        // 为word中每一个char分配一个节点
        for(auto c: word) {
            if(node->next[c-'a'] == nullptr)
                node->next[c-'a'] = new Trie();
            node = node->next[c-'a'];
        }
        // 最后一个节点标记为叶子节点
        node->isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* node = this;
        // 顺着多叉树路径寻找
        for(auto c: word) {
            node = node->next[c-'a'];
            // 没有对应节点
            if(node == nullptr)
                return false;
        }
        // 考虑可能是已有词汇比查询词汇长的情况
        return node->isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* node = this;
        // 一样顺着多叉树路径查找
        for(auto c: prefix) {
            node = node->next[c-'a'];
            // 没有对应节点
            if(node == nullptr)
                return false;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

