class Solution {
    
private:
    stack<int> minValue;
    stack<int> stck;
public:
    void push(int value) {
        stck.push(value);
        if(minValue.empty())
        {
            minValue.push(value);
            return;
        }
        if(minValue.top() < value)
        {
            minValue.push(minValue.top());
        }
        else
        {
            minValue.push(value);
        }
        return;
    }
    void pop() {
        stck.pop();
        minValue.pop();
    }
    int top() {
        return stck.top();
    }
    int min() {
        return minValue.top();
    }
};
