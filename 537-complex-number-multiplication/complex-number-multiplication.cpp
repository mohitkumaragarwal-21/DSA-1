class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        // (a+ib)*(c+id)
         int idx1=0, idx2=0;
         char ch1 ='0',ch2 ='0';
         for(auto ch:num1)
         {
             if(ch!= '+')
             idx1++;
             else
             break;
         }

          for(auto ch:num2)
         {
             if(ch!= '+')
             idx2++;
             else
             break;
         }
         
         string a = num1.substr(0,idx1);
         string b = num1.substr(idx1+1);

         string c = num2.substr(0,idx2);
         string d = num2.substr(idx2+1);

         int p = stoi(a);
         int q = stoi(b);
         int r = stoi(c);
         int s = stoi(d);

         int f = (p*r) - (q*s);
         int g = (p*s) + (q*r);

         string ans ="";
          string  temp = to_string(f);
          ans+= temp;

          ans+= '+';
         

          ans+= to_string(g);
          ans+='i';
          return ans;
    }
};