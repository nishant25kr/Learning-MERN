#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> arival {900, 940, 950, 1100, 1500, 1800};
    vector<int> dep {910, 1200, 1120, 1130, 1900, 2000};
    int i = 0;
    int j = 0;
    int cnt = 0;
    int maxcount = 0;
    while ( i < arival.size() )
    {
        if(arival[i] <= dep[j]){
            cnt++;
            i++;
        }else{
            cnt--;
            j++;
        }
        maxcount = max(maxcount, cnt);
    }
    cout<< maxcount;
    
}