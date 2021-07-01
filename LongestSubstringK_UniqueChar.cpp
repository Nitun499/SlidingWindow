#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
using namespace std;
//O(n^2) and space complexity O(n)
int Solve(string str, int k)
{
    int maxlen = 0;
    unordered_set<int> st;
    int n = str.length();
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            st.insert(str[j]);
            if (st.size() == k)
            {
                maxlen = max(maxlen, j - i + 1);
            }
        }
    }
    return maxlen;
}
//Optimized approach ->Sliding window

int main()
{
    string str = "aababbabcebebe";
    int res = Solve(str, 3);
    cout << res;
    return 0;
}