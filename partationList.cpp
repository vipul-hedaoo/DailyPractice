#include<iostream>
#include<vector>
using namespace std;
class Node
{public:
    int data;
    Node* next;
    Node(int val)
    {
        data=val;
        next=nullptr;
    }
    void setNext(Node* n)
    {
        next=n;
    }

};
void PartationList(Node* head, int target)
{
  Node* Dummy=new Node(0);
  Node* Dumm1=new Node(0);

  Node* curr=head;
  Node* LTTarget= Dummy;
  Node* GTTarget= Dumm1;
  while(curr!=nullptr)
  {
    if(curr->data<target)
   {
    LTTarget->next=curr;
    LTTarget=LTTarget->next;
    curr=curr->next;
   }
   else{
    GTTarget->next=curr;
    GTTarget=GTTarget->next;
    curr=curr->next;
   }
}
LTTarget->next=Dumm1->next;
GTTarget->next=nullptr;
head=Dummy->next;
}
int main()
{
    Node* head= new Node(1);
    head->setNext(new Node(4));
    head->next->setNext(new Node(3));
    head->next->next->setNext(new Node(2));
    head->next->next->next->setNext(new Node(5));
    head->next->next->next->next->setNext(new Node(2));
    Node* head1=head;
    while(head1!=nullptr)
    {
        cout<<head1->data<<" ";
        head1=head1->next;
    }
    cout<<endl;
    PartationList(head,3);
    while(head!=nullptr)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
}