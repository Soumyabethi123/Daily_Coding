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
    void reorderList(ListNode* head) {
        
        if(head==NULL || head->next==NULL){

            return;
        }

        ListNode*rev=NULL;
        ListNode*curr=head;

        int count=1;

        while(curr!=NULL){

             ListNode*temp = new ListNode(curr->val);

             temp->next=rev;

             rev=temp;

             curr=curr->next;
             count++;
        }

        ListNode*prev=head;
        curr=rev;

        int count2=2;

        while(true){

           ListNode*temp = prev->next;
           ListNode*temp2= curr->next;

           if(count2==count){

               prev->next=NULL;
               break;
           }
           prev->next=curr;
           count2++;

           if(count2==count){

               curr->next=NULL;
               break;
           }
           curr->next=temp;
           count2++;

           prev=temp;
           curr=temp2;
        }

        
    }
};
