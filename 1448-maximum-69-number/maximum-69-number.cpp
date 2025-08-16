class Solution {
public:
    int maximum69Number (int num) {
           string s = to_string(num);

        for(int i=0;i<s.length();i++)
        {
             if(s[i] == '6')
             {
                 s[i] = '9';
                 break;
             }
             
        }

        int res=0;
        for(int i=0;i<s.length();i++)
        {
             char ch = s[i];
             int num = ch-'0';
             res = res*10 + num;
        }

        return res;
    }
};