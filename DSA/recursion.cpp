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
            for (int j = 0; j < ds.size(); j++)
            {
                cout << ds[j] << " ";
            }
            cout << endl;
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



int main()
{
    // f();
    // printname();
    // // cout<<endl;
    // p(1,5);
    // // cout<<endl

    // backtracking(1,4);
    // // cout<<endl;
    // int s=0;
    // sum(3,s);
    // // cout<<endl;
    // // cout<<sum_recursion(5);
    // // cout<<endl;
    // // cout<<fact_recursion(5);
    // // cout<<endl;
    // // vector<int > arr;
    // // arr[0] = 1;
    // // arr[1] = 2;
    // // arr[2] = 3;
    // // reverse_array(arr, 0, arr.size()-1);
    // // cout<<endl;

    // // string st = "MADaM";
    // // cout<<palendrom(0,st);

    int arr[] = {3,2,1};
    int n=3;
    vector<int > ds;
    printF(0, ds, arr, n);

    // // printF_sum_K(0, ds, 0, 3, arr, n);

    // vector<int> arr;
    // arr.push_back(1);
    // arr.push_back(2);
    // arr.push_back(3);
    // arr.push_back(4);
    // arr.push_back(5);
    // arr.push_back(6);
    // int target = 6;
    // // combination_sum(arr, target);
    // int i=0;
    // while (i<10)
    // {
    //     cout<<i;
    //     i+=2;
    // }
    
    return 0;
}