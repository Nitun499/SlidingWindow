#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
using namespace std;
int RowMax1(vector<vector<int>> &v, int n, int m)

{
    //Brute Force approach

        /* int maxcount=INT_MIN,ans=-1;
            for(int i=0;i<n;i++){
                int count=0;
                for(int j=0;j<m;j++){
                    if(v[i][j]==1)
                        count++;
                }
                if(count>maxcount){
                    maxcount=count;
                    ans=i;
                }
            }
            return ans;
        */

    /* Optimized Approach 
         O(n+m)  */
    int row = 0, col = m - 1;
    int ans = -1;
    while (row < n && col >= 0)
    {
        if (v[row][col] == 1)
        {
            ans = row;
            col--;
        }

        else
        {
            row++;
        }
    }
    return ans;
}

int main()
{
    vector<vector<int>> mat = {{0, 1, 1, 1}, {0, 0, 1, 1}, {0, 0, 0, 1}, {0,0,0, 1}};
    int row = mat.size();
    int col = mat[0].size();
    int res = RowMax1(mat, row, col);
    cout << res;
    return 0;
}