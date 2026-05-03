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

Node* removeDuplicates1(Node* head)
    {
        Node* dummy=new Node(0);
        dummy->next=head;
        Node* curr=head;
        Node* prev=dummy;
        while(curr!=nullptr)
        {
            if(curr->next!=nullptr && curr->data==curr->next->data)
            {
                while(curr->next!=nullptr && curr->data==curr->next->data)
                {
                    curr=curr->next;
                }
                 prev->next=curr;
            }
            else{
                prev=prev->next;
                curr=curr->next;
            }
            
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
     Node* temp=head;
    while(temp!=nullptr)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }  
    cout<<endl;
    Node* newHead=removeDuplicates1(head);
    while(newHead!=nullptr)
    {
        cout<<newHead->data<<" ";
        newHead=newHead->next;
    }
    }