
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL)return NULL;
        ListNode *p1=head;
        ListNode *p2=head;
        while(true){
           p2=p2->next;
            if(p2==NULL)return NULL;
            p2=p2->next;
            if(p2==NULL)return NULL;
            p1=p1->next; 
            if(p2==p1)break;
        }
        p1=head;
        while(true){
            if(p1==p2)return p1;
            p1=p1->next;
            p2=p2->next;
            
        }
        return NULL;
    }
};