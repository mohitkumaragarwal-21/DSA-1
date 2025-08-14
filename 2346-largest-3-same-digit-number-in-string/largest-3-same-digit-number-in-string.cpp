class Solution {
public:
    string largestGoodInteger(string num) {

         string ans="";
         int n = num.length();
         for(int i=0;i<n-2;i++)
         {
             char  a = num[i];
             char b = num[i+1];
             char c = num[i+2];

             if(a ==b && b==c)
             {
                  if(!ans.empty())
                  {
                      char ch = ans[0];
                      if(a>ch)
                      {
                          ans ="";
                          ans+= a;
                          ans+=b;
                          ans+=c;
                      }
                  }
                  else
                  {
                      ans+=a;
                      ans+=b;
                      ans+=c;
                  }
             }
         } 

         return ans;
    }
};