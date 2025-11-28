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

int main(){

    vector<int > nums = {-1,0,3,5,9,12};
    int target = 3;
    cout<<BinarySearch_int(nums, target);
}