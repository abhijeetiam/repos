#include <iostream>
#include <algorithm>

using namespace std;

int MaxSumSubArray(int[], int);

int main()
{
	//int arr[] = { -2, -3, 4, -1, -2, 1, 5, -3 };
	int arr[] = { -2, -3, -4, -1, -2, -1, -5, -3 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "Number of elements in the array = " << n << endl;
	int max_sum = MaxSumSubArray(arr, n);
	cout << "Maximum contiguous sum is " << max_sum << endl;
	system("pause");
	return 0;
}

//This takes care of negative numbers too
int MaxSumSubArray(int a[], int n)
{
	int max_so_far = a[0];
	int curr_max = a[0];

	for (int i = 1; i < n; i++)
	{
		curr_max = max(a[i], curr_max + a[i]);
		max_so_far = max(max_so_far, curr_max);
	}
	return max_so_far;
}

//This takes care of positive numbers and ignore negative numbers
/*int MaxSumSubArray(int arr[], int n)
{
	int max_sum, cum_sum, start_index, end_index;
	max_sum = cum_sum = start_index = end_index = 0;

	for (int i = 0; i < n; i++)
	{
		cum_sum += arr[i];
		if (cum_sum < 0)
		{
			cum_sum = 0;
			start_index = i + 1;
		}
		else
		{
			if (cum_sum > max_sum)
			{
				max_sum = cum_sum;
				end_index = i;
			}
		}
	}

	cout << "Maximum SubArray sum = " << max_sum << ", StartIndex = " << start_index << ", EndIndex = " << end_index << endl;
	return max_sum;
}*/