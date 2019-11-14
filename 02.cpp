class Solution {
public:
	void replaceSpace(char *str,int length) {
        char *str_cpy = (char*)malloc(sizeof(char)*length);
        memcpy(str_cpy,str,sizeof(char)*length);
        for(int i = 0,j = 0;i < length;i++,j++)
        {
            if(str_cpy[i] == ' ')
            {
                str[j] = '%';
                str[j+1] = '2';
                str[j+2] = '0';
                j = j + 2;
            }
            else
            {
                str[j] = str_cpy[i];
            }
        }
        delete(str_cpy);
	}
};
