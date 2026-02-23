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
ListNode* addTwoList(ListNode* list1,ListNode* list2)
{
     if(list1 == nullptr) return list2;
       if(list2 == nullptr)  return list1;
       ListNode dummy(0); 
       ListNode* tail=&dummy;
       while(list1 && list2)
       {
        if(list1->val<=list2->val)
        {
            tail->next=list1;
            list1=list1->next;
        }
        else{
            tail->next=list2;
            list2=list2->next;
        }tail = tail->next;
        }
        
        // Attach remaining part
        if (list1) tail->next = list1;
        if (list2) tail->next = list2;
        
        return dummy.next;
}
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0)
        {
            return nullptr;
        }
        ListNode* result = nullptr;
        for(int i = 0; i < lists.size(); i++)
{
    result = addTwoList(result, lists[i]);
}
return result;
        
    }
};