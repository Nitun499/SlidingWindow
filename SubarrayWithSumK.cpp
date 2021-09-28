#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
using namespace std;
//Brute force approach will be generating all the subarray and each time check whether that sum equals to a given value
//O(n^3)


//Time Complexity O(n)
int LargestSubarrayWithSumK(vector<int> &arr, int k)
{
    int i = 0, j = 0, sum = 0, maxlen = INT_MIN;
    while (j < arr.size())
    {
        sum += arr[j];
        if (sum < k)
        {
            j++;
        }
        else if (sum == k)
        {
            maxlen = max(maxlen, j - i + 1);
            j++;
        }
        else
        {
            while (sum > k)
            {
                sum -= arr[i];
                i++;
            }
            j++;
        }
    }
    return maxlen>0?maxlen:-1;
}

int main()
{
    vector<int> v = {8,4,-3,-1,11,-2,3,2,-6};
    int res = LargestSubarrayWithSumK(v, 15);
    cout << res;
    return 0;
}