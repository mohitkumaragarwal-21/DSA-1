class Solution {
public:
    bool canMakeSquare(vector<vector<char>>& grid) {
          
          int row1 =0;
          int col1 = 0;
          for(int i =0;i<2;i++)
          {
             for(int j =0;j<2;j++)
             {
                  if(grid[i][j]== 'B')
                  row1++;

                  else
                  {
                    col1++;
                  }
             }
          }


          int row2 =0;
          int col2=0;

          for(int i =0;i<2;i++)
          {
             for(int j =1;j<3;j++)
             {
                  if(grid[i][j]== 'B')
                  row2++;

                  else
                  {
                    col2++;
                  }
             }
          }

          int row3 =0;
          int col3 =0;

          for(int i =1;i<3;i++)
          {
             for(int j =0;j<2;j++)
             {
                  if(grid[i][j]== 'B')
                  row3++;

                  else
                  {
                    col3++;
                  }
             }
          }

          int row4 =0;
          int col4 =0;

          for(int i =1;i<3;i++)
          {
             for(int j =1;j<3;j++)
             {
                  if(grid[i][j]== 'B')
                  row4++;

                  else
                  {
                    col4++;
                  }
             }
          }

          if((row1==2 && col1==2)  &&  (row2==2 && col2==2) && (row3==2 && col3==2) &&(row4==2 && col4==2)  )

          return false;


          return true;


    }
};