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

//By reversing linked list
class Solution {
public:
    ListNode* reverse(ListNode* head) {
        ListNode* start=nullptr;
        ListNode* mid=head;
        ListNode* end=head->next;
        
        while(mid)
        {
            mid->next=start;
            start=mid;
            mid=end;
            if(end)
                end=end->next;
        }
        return start;
    }

    ListNode* doubleIt(ListNode* head) {
        head=reverse(head);

        ListNode* running=head;
        ListNode* newTail=nullptr;
        
        int carry=0;

        while(running) {
            int curVal=running->val;
            int mul=curVal*2+carry;
            carry=mul/10;
            int newVal=mul%10;
            running->val=newVal;
            newTail=running;
            running=running->next;
        }

        if(carry) {
            newTail->next=new ListNode(1);
        }

        head=reverse(head);

        return head;
    }
};

//Without reversing linked list (Using Recursion)
class Solution {
public:
    int helper(ListNode* head) {
        if(head==nullptr)
            return 0;
        head->val=head->val*2;
        int carry=helper(head->next);
        int curVal=head->val+carry;
        head->val=curVal%10;
        return curVal/10;
    }

    ListNode* doubleIt(ListNode* head) {
        int lastCarry=helper(head);
        if(lastCarry) {
            ListNode* newHead=new ListNode(1);
            newHead->next=head;
            head=newHead;
        }
        return head;
    }
};
