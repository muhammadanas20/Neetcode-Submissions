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
    ListNode* reverseList(ListNode* head) {
      ListNode* prev = nullptr;
      ListNode* curr = head;

      while(curr != nullptr){
        ListNode* next = curr->next; //should be saved      
        curr->next = prev; //current next which becomes prev
        prev = curr;  // In prev curr
        curr = next;  //for looping saved next should be in curr 
      }
      return prev; //return the reverse list
    }
};
