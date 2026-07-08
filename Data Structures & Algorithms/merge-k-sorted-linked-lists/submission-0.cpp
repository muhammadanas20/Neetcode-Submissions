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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
         if (lists.empty()) return nullptr;
        int n = lists.size();
        for(int i=1;i<n;i++){
           lists[i] = mergetwoList(lists[i],lists[i-1]);
        }
        return lists[n-1];
    }
    ListNode* mergetwoList(ListNode* list1,ListNode* list2){
        ListNode dummy;
        ListNode* head = &dummy;
        while(list1 != nullptr && list2 != nullptr){
            int first = list1->val;
            int second = list2->val;
            if(first < second){
               head->next = list1;
               list1 = list1->next;
            }else{
               head->next = list2;
               list2 = list2->next;
            }
            head = head->next;
        }
        if(list1 != nullptr){
            head->next = list1;
        }else{
            head->next = list2;
        }
        return dummy.next;
    }
};
