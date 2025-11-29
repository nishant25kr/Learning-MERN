#include <iostream>
#include <vector>

using namespace std;

bool BinarySearch_int(vector<int> &nums, int target){
    int low = 0;
    int high = nums.size()-1;
    while (low <= high)
    {
        int mid = low + (high-low)/2;
        if(nums[mid] == target) return true;

        if(target < nums[mid]) high = mid-1;
        else low = mid+1;
    }

    return false;
    
}

int lower_bound(vector<int > &nums, int target){

    int low = 0;
    int high = nums.size()-1;
    int ans = nums.size()-1;
    while(low <= high){
        int mid = (high + low) / 2;
        if(nums[mid] >= target){
            ans = mid;
            high = mid-1;
        }else{
            low = mid + 1;
        }
    }
    return ans;

}

int upper_bound(vector<int > &nums, int target){
    int low = 0;
    int high = nums.size()-1;
    int ans;
    while(low <= high){
        int mid = (high + low) / 2;
        if (nums[mid] <= target)
        {
            ans = mid;
            low = mid+1;
        }else{
            high = mid - 1;
        }
        
    }
    return ans;
}

int main(){

    // vector<int > nums = {-1,1,4,5,5,12};
    vector<int > nums = {3, 4, 4, 7, 8, 10};
    int target = 5;
    // cout<<BinarySearch_int(nums, target);
    cout<<nums[upper_bound(nums, target)];
    cout<<nums[lower_bound(nums, target)];


}