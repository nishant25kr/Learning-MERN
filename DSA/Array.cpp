#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

int largest_Element(vector<int> &arr, int n)
{
    int max = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

int secondLargest_Element(vector<int> &arr, int n)
{
    // sort(arr.begin(), arr.end());

    // int largest = arr[n - 1];
    // int secondLargst = -1;
    // for (int i = 0; i < n; i++)
    // {
    //     if (secondLargst < arr[i] && arr[i] < largest)
    //     {
    //         secondLargst = arr[i];
    //     }
    // }

    // return secondLargst;

    // optimized
    int max = arr[0];
    int smax = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            smax = max;
            max = arr[i];
        }
        else if (arr[i] < max && arr[i] > smax)
        {
            smax = arr[i];
        }
    }

    return smax;
}

int secondSmallest_Element(vector<int> &arr, int n)
{
    int min = arr[0];
    int smin = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] < min)
        {
            smin = min;
            min = arr[i];
        }
        else if (arr[i] > min && arr[i] < smin)
        {
            smin = arr[i];
        }
    }

    return smin;
}

bool Check_SortedOrNot(vector<int> &arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < arr[i - 1])
        {
            return false;
        }
    }
    return true;
}

int Remove_Duplicate(vector<int> &arr, int n)
{
    unordered_map<int, int> mp;
    for (auto i : arr)
    {
        mp[i]++;
    }
    for (auto it : mp)
    {
        cout << "Key = " << it.first
             << ", Value = " << it.second << endl;
    }
}

void UnionOfArrya(vector<int> &a, vector<int> &b)
{
    int i = 0;
    int j = 0;
    vector<int> arr;
    while (i < a.size() && j < b.size())
    {
        if (a[i] <= b[j])
        {
            if (arr.size() == 0 || arr.back() != a[i])
                arr.push_back(a[i]);
            i++;
        }
        else
        {
            if (arr.size() == 0 || arr.back() != b[j])
                arr.push_back(b[j]);
            j++;
        }
    }
    while (j < b.size())
    {
        if (arr.size() == 0 || arr.back() != b[j])
        {
            arr.push_back(b[j]);
            j++;
        }
    }
    while (i < a.size())
    {
        if (arr.size() == 0 || arr.back() != a[i])
        {
            arr.push_back(a[i]);
            i++;
        }
    }
    for (auto i : arr)
    {
        cout << i;
    }
}

int main()
{
    
    // vector<int> arr = {4, 2, 2, 6, 5};
    // vector<int> arr = {1, 2, 2, 3, 4, 5, 6};
    // cout << largest_Element(arr, sizeof(arr));
    // cout << secondLargest_Element(arr, arr.size());
    // cout << secondSmallest_Element(arr, arr.size());
    // cout << Check_SortedOrNot(arr, arr.size());
    // cout << Remove_Duplicate(arr, arr.size());
    vector<int> a = {1, 2, 3, 2, 1};
    vector<int> b = {3, 2, 2, 3, 3, 2};
    // UnionOfArrya(a, b);

    return 0;

}