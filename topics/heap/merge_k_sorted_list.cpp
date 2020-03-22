// Source : https://oj.leetcode.com/problems/merge-k-sorted-lists/
// Author : Sukriti
// Date   : 2020-03-01


/********************************************************************************** 
* 
* Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
* 
* Example:
* 
* Input:
* [
*   1->4->5,
*   1->3->4,
*   2->6
* ]
* Output: 1->1->2->3->4->4->5->6
*               
**********************************************************************************/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto comp = [](ListNode* a, ListNode* b) { return a->val > b->val; };
        priority_queue<ListNode*, vector<ListNode*>, decltype(comp)> heap(comp);
        for (auto node : lists) {
            if (node) heap.push(node);
        }
        ListNode* head = nullptr;
        ListNode* ans = nullptr;
        while (!heap.empty()) {
            auto temp = heap.top();
            heap.pop();
            if (temp->next) {
                heap.push(temp->next);
            }
            if (head == nullptr) {
                head = temp;
                ans = temp;
            } else {
                ans->next = temp;
                ans = ans->next;
            }
        }
        return head;
    }
};