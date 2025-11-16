#include <iostream>
#include <vector>
using namespace std;

int sum_of_stating10_MUL(int n)
{
    int sum = 0;
    for (int i = 1; i < 11; i++)
    {
        sum += i * n;
    }
    return sum;
}

void max_of_three(int arr[], int k, int l)
{
    int p = 1;
    int q = k;
    while (q <= l)
    {

        int max = arr[p - 1];
        for (int i = p - 1; i < q; i++)
        {
            if (arr[i] > max)
            {
                max = arr[i];
            }
        }
        cout << max;
        p++;
        q++;
    }
    cout << endl;
}

void max_full_parking(vector<vector<int>> &arr, int r, int c)
{
    int max = 0;

    for (int i = 0; i < r; i++)
    {
        int curr = 0;
        for (int j = 0; j < c; j++)
        {
            if (arr[i][j] == 1)
            {
                curr++;
            }
        }
        if (curr >= max)
        {
            max = curr;
        }
    }
    cout << max;
}

int max_horse(vector<int>&arr, int n, int k)
{
    int ans = 0;
    int sum = 0;
    int start = 0;


    for (int end = 0; end < n; end++)
    {
        sum += arr[end];
        while (sum > k && start <= end)
        {
            sum -= arr[start];
            start++;
        }
        ans = max(ans, end - start + 1);
    }

    return ans;
}

int main()
{
    // int n = 10;
    // cout<<sum_of_stating10_MUL(10);
    // int arr[6] = {1, 2, 3, 4, 5, 6};
    int k = 3;
    // max_of_three(arr, k, 6);
    int r = 3, c = 3;
    // vector<vector<int>> arr = {
    //     {1, 0, 0},
    //     {1, 0, 0},
    //     {1, 0, 1}};
    // max_full_parking(arr, r, c);

    vector<int> arr = {30, 40, 50, 20, 20, 20, 90, 10, 10, 10};

    cout << max_horse(arr, arr.size(), 100) << endl;
    return 0;
}
