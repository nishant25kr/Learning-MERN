#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// int Buy_and_sell_stocks_1(vector<int> &prices){
//     int mini = prices[0];
//     int  = 0;
//     for (int i = 0; i < prices.size(); i++)
//     {
//         int cost = (prices[i] - mini);
//         maxprofit = max(cost,maxprofit);
//         mini = min(mini, prices[i]);
//     }

//     return maxprofit;

// }

// int Buy_and_sell_stocks_2(int i, bool buy, vector<int> &prices, int n){

//     if(i == n){
//         return 0;
//     }

//     int profit = 0;
//     if(buy){
//         profit = max(-prices[i] + Buy_and_sell_stocks_2(i+1,0,prices,n), 0+ Buy_and_sell_stocks_2(i+1,0,prices,n));
//     }else{
//         profit = max( prices[i] + Buy_and_sell_stocks_2(i+1,1,prices,n), 0+ Buy_and_sell_stocks_2(i+1,1,prices,n));
//     }

//     return profit;

// }

int Buy_and_sell_stocks_3(int i, bool buy, int cap,vector<int >&prices, int n){
    if( i == n || cap == 0 ) return 0;

    int profit = 0;

    if(buy){
        profit = max( -prices[i] + Buy_and_sell_stocks_3(i+1,0,cap,prices,n), 0+ Buy_and_sell_stocks_3(i+1,1,cap,prices,n) );
    }else{
        profit = max( prices[i] + Buy_and_sell_stocks_3(i+1,1,cap-1,prices,n), 0+Buy_and_sell_stocks_3(i+1,0,cap,prices,n) );
    }

    return profit;

}



int main(){
   

    vector<int> nums;
    nums.push_back(3);
    nums.push_back(3);
    nums.push_back(5);
    nums.push_back(0);
    nums.push_back(0);
    nums.push_back(3);
    nums.push_back(1);
    nums.push_back(4);

    //prices = [7,1,5,3,6,4]

    //cout<<Buy_and_sell_stocks_1(nums);



    // cout<<Buy_and_sell_stocks_2(0, 1, nums, nums.size());
    
    
    // prices = [3,3,5,0,0,3,1,4]
    cout<<Buy_and_sell_stocks_3(0, 1, 2, nums, nums.size());






}