#include <iostream>
using namespace std;

int ship_area(int w1, int h1, int w2, int h2)
{
	int blue_area = 0, red_area = 0, common_area = 0, result;
	
	blue_area = (w2 + 2)*(h2 + 2);
	red_area = (w1+2)*(h1+2);

	common_area = (blue_area + red_area) - 2*min((w1+2), (w2+2));
	result = common_area - (w1*h1 + w2*h2);
	return result;
}

int main()
{
	int T;
	while(T--)
	{
		int w1, h1, w2, h2;
		cin>>w1>>h1>>w2>>h2;
		int result = ship_area(w1,h1, w2, h2);
		cout<<result<<endl;
	}
	return 0;
}
