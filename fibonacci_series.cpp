#include<iostream>
using namespace std;

/*
int fib(int n) 
{ 
    if (n <= 1) 
        return n; 
    return fib(n-1) + fib(n-2); 
}
*/

int fib(int n) 
{ 
	int f[n+2];   // 1 extra to handle case, n = 0 
	int i; 
	      
	f[0] = 0; 
	f[1] = 1; 
	
       	for (i = 2; i <= n; i++) 
	{ 
		f[i] = f[i-1] + f[i-2]; 
	} 
		    
	return f[n]; 
} 

int sum_of_fibonacci(int arr[], int n)
{
	int i = 0, j = 0, k = 0;
	int ans = 0;

	for(i=0; i<n; i++)
		for(j=0; j<n; j++)
			for(k=0; k<n; k++)
				ans += fib(arr[i] + arr[j] - arr[k]);

	return (ans % 1000000007);
}

int main()
{
	int T;
	cin>>T;

	while(T--)
	{
		int N;
		cin>>N;

		int arr[N];
		for(int i=0; i<N; i++)
		{
			cin>>arr[i];
		}

		int res = sum_of_fibonacci(arr, N);
		cout<<res<<endl;
		return 0;
	}
}
