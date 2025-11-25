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
    return 0;
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

int longestSubarray(vector<int> &nums, int k)
{
    int i = 0, j = 0;
    long long sum = 0;
    int length = 0;

    while (j < nums.size())
    {
        sum += nums[j];

        // Shrink from left if sum > k
        while (i <= j && sum > k)
        {
            sum -= nums[i];
            i++;
        }

        // Check if sum == k
        if (sum == k)
        {
            length = max(length, j - i + 1);
        }

        j++;
    }

    return length;
}

void subarray_with_maximum_sum(vector<int> &nums)
{
    int sum = 0;
    int max = 0;
    vector<int> ans;

    for (auto i : nums)
    {
        sum += i;
        if (sum > max)
        {
            ans.push_back(i);
            max = sum;
        }
        else if (sum < 0)
        {
            sum = 0;
            ans.clear();
        }
    }
    for (auto i : ans)
    {
        cout << i << " ";
    }
}

int NcR(int n, int r)
{
    int res = 1;
    for (int i = 0; i < r; i++)
    {
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}

void print_all_element_fo_row(int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << NcR(n - 1, i) << " ";
    }
    cout << endl;
}

void print_pacal_triangle(int n)
{
    for (int i = 0; i < n; i++)
    {
        print_all_element_fo_row(i);
    }
}

void three_Sum(vector<int> &nums)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1]) continue; 

        int j = i + 1;
        int k = n - 1;

        while (j < k)
        {
            int sum = nums[i] + nums[j] + nums[k];

            if (sum > 0)
            {
                k--;
            }
            else if (sum < 0)
            {
                j++;
            }
            else
            {
                cout << nums[i] << nums[j] << nums[k];
                cout<<endl;
                j++;
                k--;
            }
        }
    }
}

void four_sum(vector<int> &nums){
    int n = nums.size();
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1]) continue; 
        for (int j = i+1; j < n; j++)
        {
            if (j > 0 && nums[j] == nums[j - 1]) continue; 
            int k = j+1;
            int l = n-1;
            while (k < l)
            {
                int sum = nums[i]+nums[j]+nums[k]+nums[l];
                if(sum < 0){
                    k++;
                }else if(sum > 0){
                    l++;
                }else{
                    cout<< nums[i]<< nums[j]<< nums[k]<< nums[l]<< endl;
                    k++;
                    l--;
                }

            }
            

        }
        
    }
    
}

void merge(vector<vector<int>> &nums){
    
    int n = nums.size();
    vector<vector<int >> res;
    vector<int > ans;
    for (int i = 0; i < n-1; i++)
    {
        if (nums[i][0] <= nums[i+1][0] && nums[i+1][0] <= nums[i][1]){
            ans.push_back({nums[i][0], nums[i+1][1]});
        }
    }

    for
    

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
    // vector<int> nums = {-3, 2, 1};
    int k = 15;
    // cout << longestSubarray(nums, k);
    // vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    // subarray_with_maximum_sum(nums);
    // cout<<NcR(4,1);
    // print_all_element_fo_row(6);
    // print_pacal_triangle(6);

    // vector<int> nums = {1,0,-1,0,-2,2};
    // three_Sum(nums);
    // four_sum(nums);

    vector<vector<int>> nums = {{1,3}, {2,6}, {8,10}, {15,18}};
    merge(nums);
    
    
    return 0;
}