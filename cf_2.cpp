#include <iostream>
#define ll long long
using namespace std;

int main() {


    ll w1=0,h1=0,w2=0,h2=0;
    cin>>w1>>h1>>w2>>h2;
    ll areaTotal1 = (w1+2)*(h1+2);
    ll areaTotal2 = (w2+2)*(h2+2);

    ll commonArea = (w2+2)*2;

    ll answer = areaTotal1 + areaTotal2 - commonArea - (w1*h1) - (w2*h2);

    cout<<answer;


    return 0;

}