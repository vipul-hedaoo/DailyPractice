#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};

class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode *slow = head, *fast = head;

        // Find middle
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse second half
        ListNode *prev = nullptr, *curr = slow;

        while (curr) {
            ListNode *nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        // Find maximum twin sum
        int ans = 0;
        ListNode *first = head;
        ListNode *second = prev;

        while (second) {
            ans = max(ans, first->val + second->val);
            first = first->next;
            second = second->next;
        }

        return ans;
    }
};

int main() {
    int n;
    cin >> n;  // Number of nodes (must be even)

    if (n <= 0) return 0;

    int x;
    cin >> x;

    ListNode* head = new ListNode(x);
    ListNode* tail = head;

    for (int i = 1; i < n; i++) {
        cin >> x;
        tail->next = new ListNode(x);
        tail = tail->next;
    }

    Solution obj;
    cout << obj.pairSum(head) << endl;

    return 0;
}