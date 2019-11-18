/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(pHead == NULL)
            return NULL;
        
        vector<int> randID;
        vector<int> listLabel;
        vector<RandomListNode*> listVector;
        RandomListNode* tmp = pHead;
        RandomListNode* tmpRand = NULL;
        
        while(tmp != NULL)
        {
            int x = -1;
            tmpRand = tmp->random;
            while(tmpRand != NULL)
            {
                x++;
                tmpRand = tmpRand->next;
            }
            randID.push_back(x);
            listLabel.push_back(tmp->label);
            tmp = tmp->next;
        }
        
        for(int i = 0;i < listLabel.size();i++)
        {
            listVector.push_back(new RandomListNode(listLabel[i]));
        }
        
        for(int i = 0;i < randID.size();i++)
        {
            if(i != randID.size() - 1)
            {
                listVector[i]->next = listVector[i + 1];
            }
            
            if(randID[i] == -1)
                listVector[i]->random = NULL;
            else
                listVector[i]->random = listVector[randID.size() - 1 - randID[i]];
        }
        
        return listVector[0];
    }
};
