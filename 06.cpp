class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        int l = 0;
        int r = rotateArray.size() - 1;
        int mid;
        while(l + 1 < r)
        {
            mid = (r + l)/2;
            if(rotateArray[l] > rotateArray[mid])
            {
                r = mid;
            }
            else if(rotateArray[r] < rotateArray[mid])
            {
                l = mid;
            }
            else
            {
                l++;
            }
        }
        return rotateArray[r];
    }
};
