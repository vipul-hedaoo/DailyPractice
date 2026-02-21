class Solution {
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        // Step 1: Find length
        int length = 0;
        ListNode* temp = head;
        
        while (temp != nullptr) {
            length++;
            temp = temp->next;
        }
        
        // If removing head
        if (length == n) {
            return head->next;
        }
        
        // Step 2: Go to node before target
        temp = head;
        for (int i = 1; i < length - n; i++) {
            temp = temp->next;
        }
        
        // Step 3: Remove node
        temp->next = temp->next->next;
        
        return head;
    }
};
