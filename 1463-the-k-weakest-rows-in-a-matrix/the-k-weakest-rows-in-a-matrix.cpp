class Solution {
public: 
   vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
           vector<int>freq;
           for(int i=0;i<mat.size();i++)
           { 
             int count =0;
             for(int j =0;j<mat[i].size();j++)
             {
                  if(mat[i][j]==1)
                  count++;
             }

             freq.push_back(count);
           }

           vector<pair<int, int>>p;
           int i =0;
           for(auto f:freq)
           {
              p.push_back(make_pair(f,i));
               i++;
           }

           // On the basis of the values we have to write the comparator
           sort(p.begin(),p.end());
           vector<int>ans;
            for(auto a:p)
            {
                 int r= a.first;
                 int t = a.second;

                 ans.push_back(t);
                 k--;
                 if(k==0)
                 return ans;

            }

            return {-1};
    }
};