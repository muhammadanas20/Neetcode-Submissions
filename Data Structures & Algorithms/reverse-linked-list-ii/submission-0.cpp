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
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        if (head == nullptr || left == right)
            return head;

        ListNode dummy(0);
        dummy.next = head;

        // Move prev to the node before 'left'
        ListNode* prev = &dummy;
        for (int i = 1; i < left; i++)
            prev = prev->next;

        // Start of sublist
        ListNode* start = prev->next;

        // Find end of sublist
        ListNode* end = start;
        for (int i = left; i < right; i++)
            end = end->next;

        // Save next part
        ListNode* nextPart = end->next;

        // Cut the list
        end->next = nullptr;

        // Reverse the sublist
        ListNode* newHead = reverse(start);

        // Reconnect
        prev->next = newHead;
        start->next = nextPart;

        return dummy.next;
    }

    ListNode* reverse(ListNode* head) {

        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr != nullptr) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        return prev;
    }
};