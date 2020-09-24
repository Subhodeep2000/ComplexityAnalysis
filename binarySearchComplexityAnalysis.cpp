#include<iostream>
#include<sys/time.h>
using namespace std;
long getTimeInMicroSeconds() {
	struct timeval start;
	gettimeofday(&start, NULL);
	return start.tv_sec * 1000000 + start.tv_usec;
}
int binarySearchRecursive(int *input, int l, int r, int x)
{
	if (r >= l) {
		int mid = l + (r - l) / 2;
		if (input[mid] == x)
			return mid;
		if (input[mid] > x)
			return binarySearchRecursive(input, l, mid - 1, x);
		return binarySearchRecursive(input, mid + 1, r, x);
	}
	return -1;
}
int binarySearchIterative(int *input , int l, int r, int x)
{
	while (l <= r) {
		int m = l + (r - l) / 2;
		if (input[m] == x) return m;
		if (input[m] < x)  l = m + 1;
		else r = m - 1;
	}
	return -1;
}
int linearSearch(int*input, int n, int x)
{
	int i;
	for (i = 0; i < n; i++)
		if (input[i] == x)
			return i;
	return -1;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	for (int n  = 10; n <= 1000000; n *= 10) {
		int*input = new int[n];
		long starttime, endtime;
		for (int i = 0; i < n; i++) {
			input[i] = n - i;
		}
		starttime = getTimeInMicroSeconds();
		binarySearchIterative(input, 0, n - 1, n + 1);
		endtime = getTimeInMicroSeconds();
		cout << "binarySearchIterative n:" << n << "time = " << endtime - starttime << endl;

	}
	cout << "\n\n";

	for (int n  = 10; n <= 1000000; n *= 10) {
		int*input = new int[n];
		long starttime, endtime;
		for (int i = 0; i < n; i++) {
			input[i] =  i;
		}
		starttime = getTimeInMicroSeconds();
		binarySearchRecursive(input, 0, n - 1, n + 1);
		endtime = getTimeInMicroSeconds();
		cout << "binarySearchRecursive n:" << n << "time = " << endtime - starttime << endl;
	}
	cout << "\n\n";

	for (int n  = 10; n <= 1000000; n *= 10) {
		int*input = new int[n];
		long starttime, endtime;
		for (int i = 0; i < n; i++) {
			input[i] = i;
		}
		starttime = getTimeInMicroSeconds();
		linearSearch(input, n, n + 1);
		endtime = getTimeInMicroSeconds();
		cout << "linearSearch n:" << n << "time = " << endtime - starttime << endl;
	}
	return 0;
}