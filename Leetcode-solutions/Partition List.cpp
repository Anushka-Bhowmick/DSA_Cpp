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
    ListNode* partition(ListNode* head, int x) {
        // head of newly modified linked list
        ListNode* newHead=nullptr;

        // pointer for traversing the whole linked list
        ListNode* running=head;

        /* dummy nodes. 
           small holds the nodes which are smaller than x,
           big holds the nodes which are greater than or equal to than x
        */
        ListNode* small=new ListNode(-101);
        ListNode* big=new ListNode(101);

        // smallPtr for maintaining the tail and attaching new smaller value nodes
        ListNode* smallPtr=small;
        // bigPtr for maintaining the tail and attaching new greater than or equal to value nodes
        ListNode* bigPtr=big;

        // traversing the whole linked list 
        while(running) {
            if(running->val<x) {
                // if current value is smaller then do some operations
                smallPtr->next=running;
                smallPtr=smallPtr->next;
                running=running->next;
                smallPtr->next=nullptr;
            } else {
                // if current value is greate than or equal then do some operations
                bigPtr->next=running;
                bigPtr=bigPtr->next;
                running=running->next;
                bigPtr->next=nullptr;
            }
        }

        // attach the smaller and larger linked list together
        smallPtr->next=big->next;
        newHead=small->next;

        //dealocate the dummy nodes
        delete small;
        delete big;

        //return the head pointer of newly modified linked list
        return newHead;
    }
};
