#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int i = 0;

void f()
{

    if (i == 4)
        return;
    cout << i << " ";
    i++;
    f();
}

int cnt = 0;
void printname()
{
    if (cnt == 4)
        return;
    cout << "Nishant";
    cnt++;
    printname();
}

void p(int n, int times)
{
    if (n == times)
        return;

    cout << n << " ";

    p(n + 1, times);
}

void backtracking(int n, int m)
{
    if (n > m)
        return;

    backtracking(n + 1, m);
    cout << n;
}

void sum(int n, int s)
{
    if (n > 0)
    {

        sum(n - 1, s + n);
    }
    else
    {
        cout << s;
    }
}

int sum_recursion(int n)
{
    if (n == 0)
        return 0;

    return n + sum_recursion(n - 1);
}

int fact_recursion(int n)
{
    if (n < 1)
        return 1;

    return n * fact_recursion(n - 1);
}

void reverse_array(vector<int> &arr, int l, int r)
{
    if (l >= r)
        return;

    swap(arr[l], arr[r]);

    reverse_array(arr, l++, r--);
}

bool palendrom(int n, string &st)
{
    if (n >= st.size() / 2)
        return true;

    if (st[n] != st[st.size() - n - 1])
        return false;

    return palendrom(n + 1, st);
}

void printF(int i, vector<int> &ds, int arr[], int n)
{
    if (i == n)
    {
        for(int i : ds){
            cout<< i <<" ";
        }
        cout<<endl;
        return;
    }

    ds.push_back(arr[i]);
    printF(i + 1, ds, arr, n);
    ds.pop_back();

    printF(i + 1, ds, arr, n);
}

bool printF_sum_K(int i, vector<int> &ds, int s, int sum, int arr[], int n)
{
    if (i == n)
    {
        if (s == sum)
        {
            return true;
        }
        else
            return false;
    }
    ds.push_back(arr[i]);
    s += arr[i];
    if (printF_sum_K(i + 1, ds, s, sum, arr, n) == true)
    {
        return true;
    }

    s -= arr[i];
    ds.pop_back();

    if (printF_sum_K(i + 1, ds, s, sum, arr, n) == true)
        return true;

    else
        return false;
}

void subsequences_with_sum_K(int i, int sum,vector<int > &ds ,vector<int>nums){
    if(i == nums.size()){
        if(sum == 0){
            for(auto i : ds){
                cout<<i<<" ";
            }
            cout<<endl;
        }
        return;
    }
    ds.push_back(nums[i]);
    subsequences_with_sum_K(i+1, sum-nums[i], ds, nums);
    ds.pop_back();
    subsequences_with_sum_K(i+1, sum, ds, nums);
}

// print the combination of the sum
void find_sum(int i, vector<int> &arr, int target, vector<int> ds, vector<vector<int>> &ans)
{

    if (target == 0)
    {
        ans.push_back(ds);
        return;
    }
    if (i == arr.size() || target < 0)
        return;

    ds.push_back(arr[i]);
    find_sum(i + 1, arr, target - arr[i], ds, ans);
    ds.pop_back();
    find_sum(i + 1, arr, target - arr[i], ds, ans);
}

void combination_sum(vector<int> &arr, int target)
{
    vector<vector<int>> ans;
    vector<int> ds;

    find_sum(0, arr, target, ds, ans);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j];
            if (j < ans[i].size() - 1)
                cout << ", ";
        }
        cout << "]" << endl;
    }
}

int fibo(int n){
    if(n<=1) return n;
    int last = fibo(n-1);
    int slast = fibo(n-2);
    return last + slast;
}

void combinations_sum(int i, int target, vector<int > &ds, vector<int > &nums){
    
    if(target == 0){
        for(int i : ds) cout<< i <<" ";
        cout<<endl;
        return;
    }

    if (i == nums.size() || target < 0) return;

    if(nums[i] <= target){
        ds.push_back(nums[i]);
        combinations_sum(i+1, target-nums[i], ds, nums);
        ds.pop_back();
    }

    combinations_sum(i+1, target, ds, nums);

}

int main()
{
    int arr[] = {3,2,1};
    int n=3;
    vector<int > ds;
    // printF(0, ds, arr, n);
    // printF_sum_K(0, ds, 0, 3, arr, n);
    vector<int> nums = {1,2,3,4,5};
    combinations_sum(0,5,ds,nums);

    return 0;
}