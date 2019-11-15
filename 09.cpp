class Solution {
public:
    int jumpFloorII(int number) {
        if(number < 3)
            return number;
        
        vector<int> arr;
        int ans = 0;
        arr.push_back(0);
        for(int i = 1;i <= number;i++)
        {
            ans = 1;
            for(int j = 0; j < i;j++)
            {
                ans += arr[j];
            }
            arr.push_back(ans);
        }
        return ans;
    }
};
