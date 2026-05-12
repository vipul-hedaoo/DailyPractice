#include<iostream>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode* next;

    ListNode(int x)
    {
        val = x;
        next = NULL;
    }

    void setNext(ListNode* nextNode)
    {
        next = nextNode;
    }
};

ListNode* ReverseLinkedListII(ListNode* head, int L, int R)
{
    if(head == NULL || L == R)
        return head;

    ListNode* dummy = new ListNode(0);
    dummy->next = head;

    ListNode* prev = dummy;

    // Move prev to node before L
    for(int i = 1; i < L; i++)
    {
        prev = prev->next;
    }

    // Start reversal
    ListNode* curr = prev->next;
    ListNode* Next = NULL;

    for(int i = 0; i < R - L; i++)
    {
        Next = curr->next;

        curr->next = Next->next;

        Next->next = prev->next;

        prev->next = Next;
    }

    return dummy->next;
}

int main()
{
    ListNode* head = new ListNode(1);

    head->setNext(new ListNode(2));
    head->next->setNext(new ListNode(3));
    head->next->next->setNext(new ListNode(4));
    head->next->next->next->setNext(new ListNode(5));

    cout << "Original List:\n";

    ListNode* curr = head;

    while(curr != NULL)
    {
        cout << curr->val << " ";
        curr = curr->next;
    }

    cout << endl;

    ListNode* head1 = ReverseLinkedListII(head, 2, 4);

    cout << "After Reversal:\n";

    while(head1 != NULL)
    {
        cout << head1->val << " ";
        head1 = head1->next;
    }
}