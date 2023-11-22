class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == NULL && l2 == NULL) return NULL;
        if(l1 == NULL) l1 = new ListNode(0);
        if(l2 == NULL) l2 = new ListNode(0);
        
        int ans = l1->val + l2->val;
        int carry = 0;

        if(ans > 9) {
            ans -= 10;
            carry = 1;
        }
        l1->val = ans;
        
        if(l1->next != NULL && carry) l1->next->val += 1;
        else if(l2->next != NULL && carry) l2->next->val += 1;
        else if(carry) l1->next = new ListNode(1);
        
        l1->next = addTwoNumbers(l1->next, l2->next);
        return l1;
    }
};