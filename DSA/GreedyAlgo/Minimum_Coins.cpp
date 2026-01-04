#include<iostream>
#include<vector>

using namespace std;

int main(){
    
    vector<int >deno = {1,2,5,10,20,50,100,500,1000};
    vector<int> ans;
    int v = 49;
    
    for(int i = deno.size()-1 ; i>0 ; i--){
        if(v >= deno[i]){
            v-=deno[i];
            ans.push_back(deno[i]);
        }
    }
    
    for(auto i : ans){
        cout<<i;
    }

}