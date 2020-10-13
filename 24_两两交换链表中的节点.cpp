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
    ListNode* swapPairs(ListNode* head) {
        ListNode* p,*q;
        if(head!=nullptr&&head->next!=nullptr)
        {
            p=head->next;
            q=p->next;
            if(p->next!=nullptr&&p->next->next!=nullptr)head->next=p->next->next;
            else head->next=p->next;
            p->next=head;
            swapPairs(q);
        }
        else return head;
        return p;
    }
};
