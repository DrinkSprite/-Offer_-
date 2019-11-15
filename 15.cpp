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
    ListNode* ReverseList(ListNode* pHead) {
        ListNode* pRe = NULL;
        ListNode* tmp = NULL;
        ListNode* p = pHead;
        
        while(p != NULL)
        {
            tmp = p;
            p = p->next;
            tmp->next = pRe;
            pRe = tmp;
        }
        return pRe;
    }
};
