class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        stack<int> stk;
        vector<int>::iterator itpush = pushV.begin();
        for(vector<int>::iterator it = popV.begin();it < popV.end();)
        {
            if(stk.empty() || stk.top() != *it)
            {
                if(itpush == pushV.end())
                    return false;
                stk.push(*itpush);
                itpush++;
            }
            else
            {
                stk.pop();
                it++;
            }
        }
        return true;
    }
};
