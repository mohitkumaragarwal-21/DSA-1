class Solution {
public:
    int countSeniors(vector<string>& details) {
           int cnt = 0;
           for(int i=0;i<details.size();i++)
           {
              char a = details[i][11];
              char b = details[i][12];

              if((a-'0') > 6)
              {
                 cnt++;
              }
              else if((a-'0') == 6 && (b-'0')>0)
              {
                cnt++;
              }
           }

           return cnt;
    }
};