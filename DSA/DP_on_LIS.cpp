#include <iostream>
#include <vector>
using namespace std;

int longest_increasing_subsequence(int i, int prev_int, vector<int > &nums, int n,vector<vector<int>>&dp){
    if( i == n ) return 0;

    if(dp[i][prev_int + 1]!=-1) return dp[i][prev_int];

    int len = 0 + longest_increasing_subsequence(i+1, prev_int, nums, n,dp);

    if(prev_int == -1 || nums[i] > prev_int){
        len = max(len , 1+(longest_increasing_subsequence(i+1, nums[i], nums, n,dp)));

    }

    return dp[i][prev_int + 1] = len;


}


int main(){
    // Input: nums = [10,9,2,5,3,7,101,18]
    vector<int> nums;
    nums.push_back(10);
    nums.push_back(9);
    nums.push_back(2);
    nums.push_back(5);
    nums.push_back(3);
    nums.push_back(7);
    nums.push_back(101);
    nums.push_back(18);


    vector<vector<int >>dp(nums.size(), vector<int>(nums.size()+1,-1));
    cout<< longest_increasing_subsequence(0,-1,nums,nums.size(),dp);


    
}