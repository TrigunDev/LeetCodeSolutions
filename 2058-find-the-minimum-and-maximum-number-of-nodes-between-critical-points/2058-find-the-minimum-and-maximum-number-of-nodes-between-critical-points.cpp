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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* previous = head;
        ListNode* current = head->next;
        int index = 1, firstCritical = -1, lastCritical = -1;
        int minDistance = INT_MAX;

        while(current->next) {
            ListNode* next = current->next;
            bool isMax = current->val > previous->val && current->val > next->val;
            bool isMin = current->val < previous->val && current->val < next->val;

            if(isMax || isMin) {
                if(lastCritical == -1) {
                    firstCritical = index;
                }
                else {
                    minDistance = min(minDistance, index-lastCritical);
                }

                lastCritical = index;
            }

            previous = current;
            current = next;
            index++;
        }

        if(firstCritical == -1 || firstCritical == lastCritical) {
            return {-1, -1};
        }

        int maxDistance = lastCritical-firstCritical;

        return {minDistance, maxDistance};
    }
};