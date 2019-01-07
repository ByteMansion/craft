/**
 * @file	linkedlist.cpp
 * @brief	All functions are solutions of leetcode problems.
 *
 * @author	Changrui
 * @date	2019/1/7
 *
 * Copyright © 2018 ChangruiShao. All rights reserved.
 */

#incldue "linkedlist.hpp"


/**
 * @brief   Leetcode 92: Reverse Linked List II
 *
 * Accepted Solutions Runtime Distribution 55%
 */
ListNode* Solution_l::reverseBetween(ListNode* head, int m, int n)
{
    if(head == nullptr || m == n) {
        return head;
    }
    vector<int> valBetween;
    ListNode* index = head;
    int len = 0;
    while(index != nullptr) {
        len += 1;
        if(len >= m && len <= n) {
            valBetween.push_back(index->val);
        }
        index = index->next;
    }

    index = head;
    len = 1;
    size_t scope = valBetween.size();
    while(index != nullptr) {
        if(len >= m && len <= n) {
            index->val = valBetween[scope-len+m-1];
        }
        len++;
        index = index->next;
    }

    return head;
}
/**
 * @brief   Leetcode 92: Reverse Linked List II
 *
 * Accepted Solutions Runtime Distribution 55%
 */
ListNode* Solution_l::reverseBetween2(ListNode* head, int m, int n)
{
    if(head == nullptr || m == n) {
        return head;
    }
    ListNode* front = nullptr;
    ListNode* back = nullptr;
    ListNode* nodeM = nullptr;
    ListNode* nodeN = nullptr;
    ListNode* prev = nullptr;
    ListNode* after = nullptr;
    ListNode* node = head;
    int index = 1;
    while(node != nullptr) {
        if(index == m-1) { front = node; }
        if(index == m) { nodeM = node; }
        if(index == n) { nodeN = node; back = node->next; }

        if(index > m && index <= n) {
            after = node->next;
            if(index == m+1) { prev = nodeM;}
            node->next = prev;
            prev = node;
            node = after;
        } else {
            node = node->next;
        }
        index += 1;
    }
    if(front != nullptr) front->next = nodeN;
    else { nodeN->next = nodeM; head = nodeN;}
    nodeM->next = back;

    return head;
}






