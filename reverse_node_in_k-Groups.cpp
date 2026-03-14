
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void print(ListNode* head)
{
    while(head != nullptr)
    {
        cout << head->val << " -> ";
        head=head->next;
    }
    cout << "NULL\n";
}

ListNode* reverseKgroup(ListNode* head,int k)
{
    ListNode* temp = head;
    int count = 0;

    // check if k nodes exist
    while(count < k)
    {
        if(temp == nullptr)
            return head;

        temp = temp->next;
        count++;
    }

    // reverse next groups
    ListNode* prevNode = reverseKgroup(temp, k);
    temp = head;
    count = 0;

    // reverse current k nodes
    while(count < k)
    {
        ListNode* next = temp->next;
        temp->next = prevNode;
        prevNode = temp;
        temp = next;
        count++;
    }
    return prevNode;
}


int main(){
    ListNode* head = new ListNode(1);
    ListNode* first = new ListNode(2);
    ListNode* second = new ListNode(3);
    ListNode* third = new ListNode(4);
    ListNode* forth = new ListNode(5);
    head->next=first;
    first->next=second;
    second->next=third;
    third->next=forth;

    ListNode* ans=reverseKgroup(head,2);
    print(ans);
}