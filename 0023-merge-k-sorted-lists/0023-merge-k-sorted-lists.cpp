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
        int n = lists.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        ListNode* head = NULL; 

        for(int i = 0; i < n; i++) {
            if(lists[i] != NULL) {
                if(head == NULL) {
                    head = lists[i];
                }    
                ListNode* temp = lists[i];

                while(temp->next != NULL) {
                    pq.push(temp->val);
                    temp = temp->next;
                }
                pq.push(temp->val);

                if(i < n-1) {
                    int k = i + 1;
                    while(k < n && lists[k] == NULL) {
                        k++;
                    }    
                    if(k < n) {
                        temp->next = lists[k];
                    }    
                } 
            }
        }

        ListNode* temp = head;

        while(temp != NULL) {
            temp->val = pq.top();
            pq.pop();
            temp = temp->next;
        }
        
        return head;
    }
};