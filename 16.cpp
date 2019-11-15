/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if(pHead1 == NULL)
        {
            return pHead2;
        }
        
        if(pHead2 == NULL)
        {
            return pHead1;
        }
        
        ListNode* ans = NULL;
        ListNode* tmp = NULL;
        
        if(pHead1->val < pHead2->val)
        {
            ans = pHead1;
            pHead1 = pHead1->next;
        }
        else
        {
            ans = pHead2;
            pHead2 = pHead2->next;
        }
        tmp = ans;
        while(pHead1 != NULL && pHead2 != NULL)
        {
            if(pHead1->val < pHead2->val)
            {
                tmp->next = pHead1;
                pHead1 = pHead1->next;
                tmp = tmp->next;
            }
            else
            {
                tmp->next = pHead2;
                pHead2 = pHead2->next;
                tmp = tmp->next;
            }
        }
        if(pHead1 == NULL)
        {
            tmp->next = pHead2;
        }
        else if(pHead2 == NULL)
        {
            tmp->next = pHead1;
        }
        return ans;
    }
};
