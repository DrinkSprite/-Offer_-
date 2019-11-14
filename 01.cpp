class Solution {
public:
	bool SubFind(int target, vector<int> line) {
        if(line.size() == 0)
        {
            return false;
        }
		int l = 0;
		int r = line.size() - 1;
		int mid = 0;
		while (l <= r)
		{
			mid = (l + r) / 2;
			if (line[mid] == target)
			{
				return true;
			}
			else if (line[mid] < target)
			{
				l = mid + 1;
			}
			else
			{
				r = mid - 1;
            }
		}
		return false;
	}
	bool Find(int target, vector<vector<int> > array) {
		bool ans = false;
		for (int i = 0; i < array.size(); i++)
		{
			ans = SubFind(target, array[i]);
			if (ans)
			{
				break;
			}
		}
		return ans;
	}
};
