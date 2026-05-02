//
#include<iostream>
#include<vector>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
    void setNext(Node* n)
    {
        next=n;
    }
};
Node* removeDuplicates(Node* head)
{
    Node* dummy=new Node(0);
    dummy->next=head;
    Node* prev=dummy;
    Node* curr=head;
    while(curr!=nullptr)
    {
        if(curr->next!=nullptr && curr->data==curr->next->data)
        {
            while(curr->next!=nullptr && curr->data==curr->next->data)
            {
                curr=curr->next;
            }
            prev->next=curr->next;
        }
        else
        {
            prev=prev->next;
            // curr=curr->next;
        }
        curr=curr->next;
    }
   return dummy->next;
}
int main()
{
    Node* head=new Node(1);
    head->setNext(new Node(2));
    head->next->setNext(new Node(2));
    head->next->next->setNext(new Node(3));
    head->next->next->next->setNext(new Node(4));
    head->next->next->next->next->setNext(new Node(4));
    head->next->next->next->next->next->setNext(new Node(5));
    head->next->next->next->next->next->next->setNext(nullptr);
    // if(head->next->next==nullptr)
    // {
    //     //return head;
    // }
    // Node* curr=head;
    // Node* ans;
    // int currdata=curr->data;
    // int prevdata=curr->data;
    // int occr=1;
    Node* head1=head;
    while(head1!=nullptr)
     {
         cout<<head1->data<<" ";
         head1=head1->next;
     }
     cout<<endl;
     head=removeDuplicates(head);
     while(head!=nullptr)
     {
         cout<<head->data<<" ";
         head=head->next;
     }  
     return 0;
}