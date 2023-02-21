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
        
        int c=0;
        ListNode *curr=head;

        while(curr!=NULL){

            c++;
            curr=curr->next;
        }

        curr=head;
        ListNode *prev=NULL;

        for(int i=0; i<(c-n); i++){
            
            prev=curr;
            curr=curr->next;
        }

        if(curr==head){

            head=curr->next;
        }
        else{

            prev->next=curr->next;
        }

        return head;
    }
};
