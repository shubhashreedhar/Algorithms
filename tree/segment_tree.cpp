#include<iostream>
#include<math.h>

using namespace std;

void update_value_util(int st[], int ss, int se, int i, int diff, int si, int size_segment)
{
	if (si > size_segment)
		return;

	if (i < ss || i > se)
		return;

	st[si] += diff;
	if (ss != se)
	{
		int mid = ss + (se - ss)/2;
		update_value_util(st, ss, mid, i, diff, 2*si + 1, size_segment);
		update_value_util(st, mid + 1, se, i, diff, 2*si + 2, size_segment);	
	}
}

void update_value(int arr[], int st[], int n, int i, int val)
{
	if (i < 0 || i >= n)
		return;

	int diff = val - arr[i];
	
	int h = (int)(ceil(log2(n)));
	int size_segment = (2 * pow(2,h)) - 1;

	arr[i] = val;

	update_value_util(st, 0, n-1, i, diff, 0, size_segment);
}

int get_sum_util(int st[], int ss, int se, int qs, int qe, int si, int size_segment)
{
	if (si >= size_segment)
		return 0;

	if ( qs <= ss && se <= qe) {
		cout<<"*******"<<si<<" "<<st[si]<<"******"<<endl;
		return st[si];
	}

	if (qs > se || qe < ss)
		return 0;	
	
	int mid = ss + (se - ss)/2;

        int x = (get_sum_util(st, ss, mid, qs, qe, 2*si + 1, size_segment) + get_sum_util(st, mid+1, se, qs, qe, 2*si + 2, size_segment)); 	
	cout<<x<<endl;
	return x;
}

int get_sum(int st[], int n, int qs, int qe)
{
	if (qs < 0 || qe >= n || qs > qe)
		return -1;
	
	int h = (int)(ceil(log2(n)));
	int size_segment = (2 * pow(2,h)) - 1;

	return get_sum_util(st, 0, n-1, qs, qe, 0, size_segment);
}

int construct_segment_tree_util(int arr[], int st[], int ss, int se, int si, int size_segment)
{
	//If there is one element, store it in the current node of the segment tree
	if (si > size_segment)
		return 0;

	if (ss == se)
	{
		st[si] = arr[ss];
		cout<<si<<" "<<st[si]<<" ";
		return st[si]; 
	}

	//If there is more than one element, recur for left and right subtrees and then store the sum in this node
	int mid = ss + (se-ss)/2;
	
	st[si] = construct_segment_tree_util(arr, st, ss, mid, 2*si+1, size_segment) + construct_segment_tree_util(arr, st, mid+1, se, 2*si+2, size_segment);

	cout<<si<<" "<<st[si]<<" ";
	return st[si];
}

int *construct_segment_tree(int arr[], int n)
{
	//Height of the segment tree
	int h = (int)(ceil(log2(n)));
	
	//Calculate memory needed for segment tree
	int size_segment = (2 * pow(2,h)) - 1;

	int *st = new int[size_segment];

	construct_segment_tree_util(arr, st, 0, n-1, 0, size_segment);
	cout<<endl;

	return st;
}

int main()
{
	int N;
	cin>>N;
	int arr[N];

	for(int i=0; i<N; i++) {
		cin>>arr[i];
	}

	int *st = construct_segment_tree(arr,N);
	
	int sum = get_sum(st, N, 1, 3);
	cout<<sum<<endl;
	
	update_value(arr, st, N, 1, 10);
	cout<<arr[1]<<" ";

	return 0;
}
