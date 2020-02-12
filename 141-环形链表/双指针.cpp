
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL)return false;
        ListNode *p1=head;
        ListNode *p2=head;
        while(true){
            p2=p2->next;
            if(p2==NULL)return false;
            if(p2==p1)return true;
            p2=p2->next;
            if(p2==NULL)return false;
            if(p2==p1)return true;
            p1=p1->next;
        }
        return false;
    }
};