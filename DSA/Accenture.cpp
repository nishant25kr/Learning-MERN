#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int minTransformCost(string s1, string s2)
{
    unordered_map<char, int> count1, count2;

    for (int i = 0; i < s1.length(); i++)
    {
        count1[s1[i]]++;
    }

    for (int i = 0; i < s2.length(); i++)
    {
        count2[s2[i]]++;
    }

    int cost = 0;

    for (auto &p : count2)
    {
        char ch = p.first;
        int need = p.second - count1[ch];
        if (need > 0)
            cost += need;
    }

    // for (int i = 0; i < s2.length(); i++)
    // {
    //     int p = count1[s2[i]];
    //     int q = count2[s2[i]];
    //     int need = q - p;

    //     if (need > 0)
    //     {
    //         cost += need;
    //     }
    // }

    return cost;
}

void trialgle(int n)
{
    int count = 1;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << count;
            count++;
        }
        cout << endl;
    }
}

void SumOfLeaders(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        bool isLeader = true;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] > arr[i])
            {
                isLeader = false;
                break;
            }
        }
        if (isLeader)
        {
            sum += arr[i];
        }
    }

    cout << "Sum of leaders is :" << sum;
}

void longest_Word(string str)
{
    string word = "";
    string longest = "";

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] != ' ')
        {
            word += str[i];
        }
        else
        {
            if (word.length() > longest.length())
            {
                longest = word;
            }
            word = "";
        }
    }

    if (word.length() > longest.length())
    {
        longest = word;
    }

    cout << "Longest word: " << longest << endl;
}

void min_num_of_Int(int arr[], int n, int x, int y)
{
    int i = 0;
    int j = n - 1;
    int integers = 0;
    int prev = 0;
    while (j > i)
    {
        /* code */
        if ((i == 3 or i == 6) and (j == 3 or j == 6))
        {
            integers = j - i;
            if (integers < prev)
            {
                prev = integers;
            }
        }
        if (i == 3 or i == 6)
        {
            j--;
        }
        if (j == 3 or j == 6)
        {
            i++;
        }
        i++;
        j--;
    }

    cout << prev;
}

void most_freq_vovel(string s)
{

    int n = s.length();
    unordered_map<char, int>count;

    for (int i = 0; i < n; i++)
    {
        if(s[i] == 'A' or 'E' or 'I' or 'O' or 'U'){
            count[s[i]]++;
        }

    }

    int maxFreq = 0;
    char maxChar;   
    
    for(auto &c : count){
        if(c.second > maxFreq){
            maxFreq = c.second;
            maxChar = c.first;

        }
    }

    cout<<maxChar;
}

int main()
{
    string s1, s2;
    s1 = "ABD";
    s2 = "AABCCAD";
    // cout << "Minimum Cost: " << minTransformCost(s1, s2) << endl;

    int i = 4;
    // trialgle(i);

    // int arr[] = {52, 66, 64, 36, 45, 24, 32};
    // int n = sizeof(arr) / sizeof(arr[0]);
    // SumOfLeaders(arr, n);

    string str = "yes no number";
    // longest_Word(str);

    int x = 3;
    int y = 6;
    int arr[] = {10, 3, 2, 4, 5, 6, 9, 7, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    // min_num_of_Int(arr,n,x,y);

    string s = "xyuuuaab" ;
    most_freq_vovel(s);

    return 0;
}
