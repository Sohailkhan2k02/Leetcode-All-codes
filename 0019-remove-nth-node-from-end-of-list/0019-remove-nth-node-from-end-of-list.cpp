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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow=head,*fast=head;
        while(fast && fast->next){
            if(n-->0){
                fast=fast->next;
            }
            else{
                fast=fast->next;
                slow=slow->next;
            }
        }

        if(n>0){
            return head->next;
        }
        slow->next=slow->next->next;
        return head;

    }
};