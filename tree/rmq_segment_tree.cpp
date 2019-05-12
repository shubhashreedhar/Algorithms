#include<iostream>
#include<math.h>
using namespace std;

int get_min_helper(int arr[], int st[], int ss, int se, int qs, int qe, int si)
{
	if (qs <= ss && qe >= se)
		return st[si];

	if (qs > se || qe < ss)
		return INT8_MAX;

	int mid = ss + (se - ss)/2;
	return min(get_min_helper(arr, st, ss, mid, qs, qe, 2*si + 1), get_min_helper(arr, st, mid+1, se, qs, qe, 2*si+2));
}

int get_min(int arr[], int st[], int n, int qs, int qe)
{
	if (qs < 0 || qs >= n || qs > qe)
		return -1;

	return get_min_helper(arr, st, 0, n-1, qs, qe, 0);	
}

int rmq_helper(int arr[], int st[], int ss, int se, int si)
{
	if (ss == se)
	{
		st[si] = arr[ss];
		return st[si];
	}

	int mid = ss + (se - ss)/2;

	st[si] = min(rmq_helper(arr, st, ss, mid, 2*si+1), rmq_helper(arr, st, mid+1, se, 2*si+2));
	
	return st[si];
}

int *construct_rmq_segment_tree(int arr[], int n)
{
	int h = (int)(ceil)(log2(n));
	int tree_size = 2*(pow(2,h)) - 1;

	int *st = new int[tree_size];

	rmq_helper(arr, st, 0, n-1, 0);

	return st;
}

int main()
{
	int N;
	cin>>N;

	int arr[N];
	for(int i=0; i<N; i++)
		cin>>arr[i];

	int *st = construct_rmq_segment_tree(arr, N);

	int min_element = get_min(arr, st, N, 1, 3);
	cout<<min_element<<endl;

	return 0;
}
