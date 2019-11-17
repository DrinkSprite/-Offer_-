class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        if(sequence.size() == 0)
            return false;
        if(sequence.size() == 1)
            return true;
        int N = sequence.size();
        if(sequence[0] > sequence[N - 1] && sequence[N - 2] > sequence[N - 1])
        {
            for(int i = 0;i < N-1; i++)
            {
                if(sequence[i] < sequence[N - 1])
                {
                    return false;
                }
            }
            vector<int> rightsequence(sequence.begin(),sequence.begin() + N -1);
            return VerifySquenceOfBST(rightsequence);
        }
        else if(sequence[0] < sequence[N - 1] && sequence[N - 2] < sequence[N - 1])
        {
            for(int i = 0;i < N-1; i++)
            {
                if(sequence[i] > sequence[N - 1])
                {
                    return false;
                }
            }
            vector<int> leftsequence(sequence.begin(),sequence.begin() + N -1);
            return VerifySquenceOfBST(leftsequence);
        }
        else if(sequence[0] < sequence[N - 1] && sequence[N - 2] > sequence[N - 1])
        {
            int index = 0;
            for(int i = 0;i < N;i++)
            {
                if(sequence[i] > sequence[N - 1])
                {
                    index = i;
                    break;
                }
            }
            for(int i = index;i < N - 1; i++)
            {
                if(sequence[i] < sequence[N - 1])
                {
                    return false;
                }
            }
            vector<int> leftsequence(sequence.begin(),sequence.begin() + index);
            vector<int> rightsequence(sequence.begin() + index,sequence.begin() + N -1);
            if(VerifySquenceOfBST(leftsequence) && VerifySquenceOfBST(rightsequence))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else if(sequence[0] > sequence[N - 1] && sequence[N - 2] < sequence[N - 1])
        {
            return false;
        }
        else
        {
            return true;
        }
    }
};
