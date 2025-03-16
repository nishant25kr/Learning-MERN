#include <iostream>
#include <vector>
using namespace std;

int maxpoint(vector<int> &cardPoint, int k)
{
    int n = cardPoint.size();
    int lsum = 0;
    int rsum = 0;
    int render = n - 1;
    int maxsum = 0;

    for (int i = 0; i < k; i++)
    {
        lsum += cardPoint[i];
    }

    maxsum = lsum;

    for (int i = k - 1; i >= 0; i--)
    {
        lsum -= cardPoint[i];     
        rsum += cardPoint[render]; 
        render--;                 
        maxsum = max(maxsum, lsum + rsum);
    }

    return maxsum;
}

//count unique characters in given string 

int countmax(string s){
    int n=s.length();
    int len=0;
    int maxlen=0;
    for (int i = 0; i < n; i++)
    {
        unordered_map<char, int> hash;
        for (int j = i ; j < n; j++)
        {
            if(hash[s[j]]==1) break;
            len=j-i+1;
            maxlen=max(maxlen,len);
            hash[s[j]]=1;
        }
    }
    return maxlen;
}

int main()
{
    // vector<int> cardPoints = {1, 2, 3, 4, 5, 6};
    // vector<int> cardPoints( {1, 2, 3, 4, 5, 6} );
    vector<int> cardPoints;
    cardPoints.push_back(1);
    cardPoints.push_back(2);
    cardPoints.push_back(3);
    cardPoints.push_back(4);
    cardPoints.push_back(5);
    cardPoints.push_back(6);
    cardPoints.push_back(1);

    int k = 3;
    cout << "Maximum points: " << maxpoint(cardPoints, k) << endl;

    string s = "al;djf;lajdsf";

    cout<<countmax(s);



    return 0;

}
