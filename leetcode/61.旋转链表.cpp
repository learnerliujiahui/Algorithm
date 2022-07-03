/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || k == 0 || head->next == nullptr)
            return head;
        ListNode* p_end = head;
        int length = 1;
        while(p_end->next) {
            length++;
            p_end = p_end->next;
        }
        if (k % length == 0)
            return head;
        ListNode* p_curr = head;
        for(int i = 0; i < length - k%length-1; i++) {
            p_curr = p_curr->next;
        }
        p_end->next = head;
        ListNode* newhead = p_curr->next;
        p_curr->next = nullptr;
        return newhead;
    }
};
// @lc code=end

