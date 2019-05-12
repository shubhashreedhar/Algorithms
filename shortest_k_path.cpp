#include<iostream>
#include<vector>
using namespace std;

int shortest_k_path_helper(vector<pair<int, int> > g[], int start, int end, int k, int count, int *min_path)
{
	if (count == k && start == end) {
		cout<<"RETURN 1"<<endl;
	       return 1;
	}

	vector<pair <int, int> > temp = g[start];
	int rc;

	cout<<"******"<<start<<" "<<end<<" "<<k<<" "<<count<<" "<<*min_path<<"**********"<<endl;
	for(int i=0; i<temp.size(); i++)
	{
		cout<<"SDHAR: size:"<<temp.size()<<"i"<<i<<" ";
		rc = shortest_k_path_helper(g, temp[i].first, end, k, count+1, min_path);
		if (rc) {
			(*min_path) += temp[i].second;
			cout<<"sssssssssssssssssss"<<*min_path<<"sssssssssssssssssss"<<endl;
			return 1;
		}
	}
	return 0;	
}

int shortest_k_path(vector<pair<int, int> > g[], int start, int end, int k)
{
	int min_path_sum = INT8_MAX, min_path = 0;
	vector<pair<int, int> > temp = g[start];

	cout<<temp.size()<<endl;
	for(int i =0; i<temp.size(); i++)
	{
		int rc = shortest_k_path_helper(g, temp[i].first, end, k, 1, &min_path);
		if (rc) 
		{
			min_path += temp[i].second;
			if(min_path < min_path_sum)
				min_path_sum = min_path;
		}
		min_path = 0;
	}

	return min_path_sum;
}

int main()
{
	int V, E;
	cin>>V>>E;
	
	vector<pair<int, int> > g[V];
	int u, v, cost;

	//Directed Graph
	for(int i=0; i<E; i++)
	{
		cin>>u>>v>>cost;
		g[u].push_back(make_pair(v,cost));
	}

	int start, end, k;
	cin>>start>>end>>k;

	cout<<"-----------"<<start<<" "<<end<<"---------------"<<endl;
	int result = shortest_k_path(g, start, end, k);
	cout<<result<<endl;

	return 0;
}
