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
private:
    ListNode* findMiddle(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head -> next;
        while(fast != NULL && fast -> next != NULL){
            slow  = slow -> next;
            fast  = fast -> next -> next;
        }
        return slow;
    }
    ListNode* merge(ListNode* left, ListNode* right){
        ListNode* t1 = left;
        ListNode* t2 = right;
        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;
        while(t1 != NULL && t2 != NULL){
            if(t1 -> val < t2 -> val){
                temp -> next = t1;
                temp = t1;
                t1 = t1 -> next;
            }
            else{
                temp -> next = t2;
                temp = t2;
                t2 = t2 -> next;
            }
        }
        if(t1 != NULL){
            temp -> next = t1;
        }
        else{
            temp -> next = t2;
        }
        return dummyNode -> next;
    }
    ListNode* sort(ListNode* head){
         if(head == NULL || head -> next == NULL){
            return head;
        }
        ListNode* middle =  findMiddle(head);
        ListNode* right = middle -> next;
        middle -> next = NULL;
        ListNode* left = head;

        left = sort(left);
        right = sort(right);

        return merge(left,right);
    }
public:
    ListNode* sortList(ListNode* head) {
        return sort(head);
    }
};