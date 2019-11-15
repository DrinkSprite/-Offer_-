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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        ListNode* pRe = NULL;
        ListNode* tmp = NULL;
        ListNode* p = NULL;
        ListNode* ans = NULL;
        int cnt = 0;
        
        p = pListHead;
        while(NULL != p)
        {
            cnt++;
            tmp = p;
            p = p->next;
            tmp->next = pRe;
            pRe = tmp;
        }
        
        if(k > cnt || k == 0)
        {
            return NULL;
        }
        ans = pRe;
        while(--k)
        {
            ans = ans->next;
        }
        
        p = pRe;
        pRe = NULL;
        while(NULL != p)
        {
            tmp = p;
            p = p->next;
            tmp->next = pRe;
            pRe = tmp;
        }
        
        return ans;
    }
};
