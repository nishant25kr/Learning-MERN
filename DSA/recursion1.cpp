#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int f(vector<int>&nums,int i,vector<int>&dp){
    if(i==0) return nums[i];
    if(i<0) return 0;
    if(dp[i]!=-1) return dp[1];
    int pick=nums[i]+f(nums,i-2,dp);
    int npick=0+f(nums,i-1,dp);

    return dp[i] = max(pick,npick);
}

int main(){
    vector<int>nums;
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(9);
   
    // int i=0;
    // int sum=0;
    // while (i<nums.size())
    // {
    //     sum+=nums[i];
    //     i+=2;
    // }
    // cout<<"hello";
    // cout<<sum;

    int i=nums.size();
    vector<int >dp(i,-1);
    cout<<f(nums,i-1,dp);





    return 0;
}
