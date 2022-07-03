/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL)
            return NULL;
        ListNode* p_head = new ListNode(0);
        p_head->next = head;
        ListNode* p_pre = p_head;
        ListNode* p_curr = p_pre->next;
        ListNode* p_next;
        while(p_curr) {
            p_next = p_curr->next;
            while(p_next && p_curr->val == p_next->val) {
                p_pre->next = p_next;
                delete p_curr;
                p_curr = p_next;
                p_next = p_next->next;
            }
            p_pre = p_curr;
            p_curr = p_next;
        }
        return p_head->next;
    }
};
// @lc code=end

