#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
string convert2binary(int n)
{
    string res;
    while (n > 0)
    {
        if (n%2 == 0)
        {
            res+= "0";
        }
        else{
            res+= "1";
        }
        n=n/2;
    }
    reverse(res.begin(), res.end());
    return res;
    
}
int binary2decimal(string s)
{
    int p2=1;
    int len=s.length();
    int num=0;

    for (int i = len-1; i >= 0 ; i--)
    {
        if (s[i] == '1')
        {
            num=num+p2;
        }
        p2=p2*2;
        
    }
    
    return num;
    
}
int main(){
    int n=998;
    string s=convert2binary(n);
    cout<<s<<endl;
    cout<<s.length()<<endl;
    cout<<s[s.length()-1];
    int x=binary2decimal(s);
    cout<<x;


}