#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

#define inf INT_MAX;

void print(int dist[20][20],int R)
{
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < R; j++)
		{
			if (dist[i][j] == INT_MAX)
			{
				cout << " INF";
			}
			else
			{
				cout << setw(4) << dist[i][j] ;
			}
		}
		cout << endl;
	}
}

int shortest_dist(int dist[20][20], int R, int K)
{
	int min = inf;
	int ch_arr[20] = { -1 }, k = 0;
	int k1 = K, k2, k3, z, sum, fsum = INT_MAX, j1;

	for (int i = 0; i < R - (k1 - 1); i++)
	{
		if (dist[i][0] < min)
		{
			min = dist[i][0];
			if (k != 0)
			{
				k = 0;
				ch_arr[k] = i;
			}
			else
			{
				ch_arr[k] = i;
			}
		}
		else if (dist[i][0] == min)
		{
			k++;
			ch_arr[k] = i;
		}

	}

	for (int i = 0; i <= k; i++)
	{
		k2 = K - 1;
		z = ch_arr[i];
		sum = dist[z][0];
				
		while (k2 != 0)
		{
			k3 = k2;
			min = inf;

			for (int j = z + 1; j < R - (k3 - 1); j++)
			{
				if (dist[z][j] < min)
				{
					min = dist[z][j];
					j1 = j;
				}
			}

			sum += min;
			k2--;
			z = j1;
			
		}
			
		if (fsum > sum)
		{
			fsum = sum;
		}
		
	}

	return fsum;
}

void main()
{
	int R, C, K, D, k1, count=0;
	int dist[20][20] = { INT_MAX };
	int mount[20][20] = { INT_MAX };
	int rc[20][2];

	cout << "\nEnter the row and the column : ";
	cin >> R >> C;
	cout << "Enter the number of dragons to Visit/Kill : ";
	cin >> K;
	cout << "Enter the total number of dragons : ";
	cin >> D;

	k1 = K;

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < R; j++)
		{
			dist[i][j] = inf;
		}
	}

	cout << "\n";

	for (int i = 0; i < D; i++)
	{
		cout << "Enter the row and column of the dragon " << i+1 << " : ";
		cin >> rc[i][0] >> rc[i][1];
		count++;
	}

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < count; j++)
		{
			if (rc[j][0] == i)
			{
				dist[i][0] = abs(rc[j][0]) + abs(rc[j][1]);
			}
		}
	}

	for (int i = 0; i < count-1; i++)
	{
		for (int j = i+1; j < count; j++)
		{
			dist[rc[i][0]][rc[j][0]] = abs(rc[i][0]-rc[j][0]) + abs(rc[i][1]-rc[j][1]);
		}
	}

	cout << "\n";
	print(dist, R);

	cout << "\n\nThe Shortest Path that comes out is : " << shortest_dist(dist,R,K);

}