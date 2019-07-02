#include <iostream>
using namespace std;
int main()
{
	int n, m, id_1, id_2, weight, max = 0, id_max;
	cin >> n >> m;
	long long int *counter = new long long int[n];
	for (int j = 0; j < n; j++)
	{
		counter[j] = 0;
	}
	for (int i = 0; i < m; i++)
	{
		cin >> id_1 >> id_2 >> weight;
		counter[id_1]++;
		counter[id_2]++;
		if (counter[id_1] > max)
		{
			max = counter[id_1];
			id_max = id_1;
		}
		else if (counter[id_2] > max)
		{
			max = counter[id_2];
			id_max = id_2;
		}
	}
	for (int j = 0; j < n; j++)
	{
		cout << counter[j] << "\n";
	}
	return 0;
}
