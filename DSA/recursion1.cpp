#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// robber in altername houses
// robber in last house connected with first house
int f(int i, vector<int> &nums, vector<int> &dp)
{
    if (i == 0)
        return nums[0];
    if (i < 0)
        return 0;

    int pick = nums[i] + f(i - 2, nums, dp);
    int npick = 0 + f(i - 1, nums, dp);

    return max(pick, npick);
}

int uniquepath(int m, int n, vector<vector<int>> &dp)
{
    if (m == 0 && n == 0)
        return 1;
    if (m < 0 || n < 0)
        return 0;

    if (dp[m][n] != -1)
        return dp[m][n];

    int up = uniquepath(m - 1, n, dp);
    int left = uniquepath(m, n - 1, dp);

    return dp[m][n] = up + left;
}

int uniquepath_with_obstacle(int i, int j, vector<vector<int>> obstacleGrid, vector<vector<int>> &dp)
{
    if (i >= 0 && j >= 0 && obstacleGrid[i][j] == 1)
        return 0;
    if (i == 0 && j == 0)
        return 1;
    if (i < 0 || j < 0)
        return 0;

    if (dp[i][j] != -1)
        return -1;

    int up = uniquepath_with_obstacle(i - 1, j, obstacleGrid, dp);
    int left = uniquepath_with_obstacle(i, j - 1, obstacleGrid, dp);

    return up + left;
}

//minimum energy to go to the bottom of the triangle
int min_in_triangle( int n, int i, int j, vector<vector<int>> &triangle, vector<vector<int>> &dp ){
    if(i == n-1) return triangle[n-1][j];


    int d = triangle[i][j]+min_in_triangle(n,i+1, j,triangle,dp);
    int dg = triangle[i][j]+min_in_triangle(n,i+1, j+1,triangle,dp);
    
    return min(d,dg);


}

int max_profit(vector<int> &profit){
    int mini = profit[0];
    int mprofits = 0;
    int n = profit.size();

    for (int i = 0; i < n; i++)
    {
        int cost = profit[i]-mini;
        mprofits = max(cost,mprofits);
        mini = min(mini,profit[i]);

    }
    return mprofits;
    
}

bool Partition_Equal_Subset_Sum(int i,int T,vector<int> &nums){
    
    if(T == 0) return 1;
    if(i == 0) return (nums[i]==T);

    bool npick = Partition_Equal_Subset_Sum(i-1,T,nums);
    bool pick;
    if(nums[i]>=T){
        pick = Partition_Equal_Subset_Sum(i-1,T-nums[i],nums);
    }

    return pick || npick;

}

int main()
{
    vector<int> nums;

    nums.push_back(1);
    nums.push_back(5);
    nums.push_back(11);
    nums.push_back(5);


    // vector<int> dp(nums.size(),-1);
    // cout<<f(nums.size()-1, nums, dp);

    // houses connected with last to first
    //  vector<int>temp1;
    //  vector<int>temp2;
    //  vector<int> dp1(nums.size()-1,-1);
    //  vector<int> dp2(nums.size()-1,-1);

    // for (int i = 0; i < nums.size(); i++)
    // {
    //     if(i != 0) temp1.push_back(nums[i]);
    //     if(i != nums.size()-1) temp1.push_back(nums[i]);
    // }
    // cout<<max(f(temp1.size()-1,temp1,dp1),f(temp2.size()-1,temp2,dp2));

    //int m = 3;
    //int n = 3;
    // vector<vector<int>> dp(m, vector<int>(n, -1));
    // cout << uniquepath(m - 1, n - 1, dp);

    // // obstacleGrid problem
    // int obstacleGrid[3][3] = {
    //     {0, 0, 0},
    //     {0, 1, 0},
    //     {0, 0, 0}};

    // // cout<<uniquepath_with_obstacle(m-1,n-1,obstacleGrid,dp);

    // vector<vector<int>> triangle = {
    //     {2},
    //     {3, 4},
    //     {6, 5, 7},
    //     {4, 1, 8, 3}};

    //     int n = triangle.size();
    //     vector<vector<int>> dp(n,vector<int>(n,-1));

    //     cout<<min_in_triangle(n,0,0,triangle,dp);

    // vector<int> price = [7,1,5,3,6,4]

    // cout<<max_profit(nums);



    //subset sum problem
    //nums = [1,5,11,5]

    // int n = nums.size();
    // int sum = 0;
    // for (int i = 0; i < n; i++)
    // {
    //     sum+=nums[i];
    // }

    // cout<<Partition_Equal_Subset_Sum(n-1,sum/2,nums);


        
    return 0;
}
