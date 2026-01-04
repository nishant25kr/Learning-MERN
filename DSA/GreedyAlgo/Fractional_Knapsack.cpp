#include <iostream>
#include <vector>
using namespace std;

int main()
{

    vector<int> val = {60, 100, 200, 100};
    vector<int> wt = {10, 20, 50, 50};
    int weight = 90;
    int total = 0;

    for (int i = 0; i < val.size(); i++)
    {
        if (wt[i] < weight)
        {
            weight -= wt[i];
            total += val[i];
        }
        else
        {
            int perUnit = val[i] / wt[i];
            total += perUnit * weight;
        }
    }
    cout << total;
}