class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy;
        ListNode* cur=&dummy;
        int tmp=0;
        while(l1||l2||tmp){
            int sum=tmp;
            if(l1) sum+=l1->val,l1=l1->next;
            if(l2) sum+=l2->val,l2=l2->next;
            tmp=sum/10;
            cur->next=new ListNode(sum%10);
            cur=cur->next;
        }
        return dummy.next;
        
    }
};