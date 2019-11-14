/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> ans;
        ListNode* pNew = NULL;
        ListNode* pOld = head;
        ListNode* pTmp = NULL;
        
        while(NULL != pOld)
        {
            pTmp = pOld;
            pOld = pTmp->next;
            pTmp->next = pNew;
            pNew = pTmp;
        }
        
        pTmp = pNew;
        
        while(NULL != pTmp)
        {
            ans.push_back(pTmp->val);
            pTmp = pTmp->next;
        }
        /*
        pOld = pNew;
        pNew = NULL;
        
        while(NULL != pOld)
        {
            pTmp = pOld;
            pOld = pTmp->next;
            pTmp->next = pNew;
            pNew = pTmp;
        }
        */
        return ans;
    }
};
