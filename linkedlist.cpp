#include<iostream>
using namespace std;
class Node{
 int val;
 Node * next;
 public:
  Node(int val)
  {
    this->val=val;
    this->next=nullptr;
  }
  int getVal()
  {
    return this->val;
  }
  Node* getNext()
  {
    return this->next;
  }
  void setNext(Node* next)
  {
    this->next=next;
  }
};
int main()
{
    int k=0;
    cout<<"enter value";
    cin>>k;
    Node* head= new Node(k);
    Node* floating = head;
    for(int i=0;i<9;i++)
    {
        cout<<"enter value";
        cin>>k;
        floating->setNext(new Node(k));
        floating=floating->getNext();
    }
    floating->setNext(nullptr);
    while(head!=nullptr)
    {
        cout<<" "<<head->getVal()<<"<-";
        head=head->getNext();
    }

}