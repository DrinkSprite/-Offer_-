class Solution {
public:
    int rectCover(int number) {
        if(number < 3)
            return number;
        int pre = 1;
        int ans = 1;
        int tmp;
        for(int i = 2;i <= number;i++)
        {
            tmp = pre;
            pre = ans;
            ans += tmp;
        }
        return ans;
    }
};
