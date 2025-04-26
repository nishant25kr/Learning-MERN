#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// int f1(vector<int>&nums,int i,vector<int>&dp){
//     if(i==0) return nums[i];
//     if(i<0) return 0;
//     if(dp[i]!=-1) return dp[1];
//     int pick=nums[i]+f(nums,i-2,dp);
//     int npick=0+f(nums,i-1,dp);

//     return dp[i] = max(pick,npick);
// }


//robber in altername houses
//robber in last house connected with first house
int f(int i, vector<int> &nums, vector<int> &dp){
    if(i==0) return nums[0];
    if(i<0) return 0;

    int pick = nums[i] + f(i-2,nums,dp);
    int npick = 0 + f(i-1,nums,dp);

    return max(pick,npick);
}


int uniquepath(int m, int n, vector<vector<int >> &dp){
    if(m==0 && n==0) return 1;
    if(m<0 || n<0) return 0;

    if(dp[m][n] != -1) return dp[m][n];

    int up = uniquepath(m-1,n,dp);
    int left = uniquepath(m,n-1,dp);

    return dp[m][n] = up+left;
}


int uniquepath_with_obstacle(int i, int j, vector<vector<int>> obstacleGrid, vector<vector<int >> &dp){
    if(i >= 0 && j >= 0 && obstacleGrid[i][j] == 1) return 0;
    if(i == 0 && j == 0) return 1;
    if(i < 0 || j < 0) return 0;

    if(dp[i][j] != -1) return -1;

    int up = uniquepath_with_obstacle(i-1,j,obstacleGrid,dp);
    int left = uniquepath_with_obstacle(i,j-1,obstacleGrid,dp);

    return up+left;

}

int main(){
    vector<int>nums;
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(9);
    nums.push_back(4);
    nums.push_back(2);
   

    // vector<int> dp(nums.size(),-1);
    // cout<<f(nums.size()-1, nums, dp);



    //houses connected with last to first
    // vector<int>temp1;
    // vector<int>temp2;
    // vector<int> dp1(nums.size()-1,-1);
    // vector<int> dp2(nums.size()-1,-1);

    // for (int i = 0; i < nums.size(); i++)
    // {
    //     if(i != 0) temp1.push_back(nums[i]);
    //     if(i != nums.size()-1) temp1.push_back(nums[i]);
    // }
    // cout<<max(f(temp1.size()-1,temp1,dp1),f(temp2.size()-1,temp2,dp2));

    int m = 3;
    int n = 3;
    vector<vector<int>> dp(m,vector<int>(n,-1));
    cout<<uniquepath(m-1,n-1,dp);

    //obstacleGrid problem
    int obstacleGrid[3][3] = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    };

    cout<<uniquepath_with_obstacle(m-1,n-1,obstacleGrid,dp);

    return 0;
}
