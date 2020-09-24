#include<iostream>
#include<sys/time.h>
using namespace std;
long getTimeInMicroSeconds() {
	struct timeval start;
	gettimeofday(&start, NULL);
	return start.tv_sec * 1000000 + start.tv_usec;
}

//partition of quick sort
int partition (int *arr, int low, int high)
{
	int pivot = arr[(high + low) / 2];
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++)
	{
		if (arr[j] < pivot)
		{	i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[high]);
	return (i + 1);
}

//quick sort
void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		int pi = partition(arr, low, high);
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}


//merge function of merge Sort
void merge(int *arr, int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;
	int L[n1], R[n2];
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];
	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}
	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}
	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}

//merge Sort
void mergeSort(int arr[], int l, int r)
{
	if (l < r) {
		int m = l + (r - l) / 2;
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);

		merge(arr, l, m, r);
	}
}

//Bubble Sort
void bubbleSort(int *arr, int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)
		for (j = 0; j < n - i - 1; j++)
			if (arr[j] > arr[j + 1])
				swap(arr[j], arr[j + 1]);
}

//selection sort
void selectionSort(int *arr, int n)
{
	int i, j, min_idx;
	for (i = 0; i < n - 1; i++)
	{	min_idx = i;
		for (j = i + 1; j < n; j++)
			if (arr[j] < arr[min_idx])
				min_idx = j;
		swap(arr[min_idx], arr[i]);
	}
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
		mergeSort(input, 0, n - 1);
		endtime = getTimeInMicroSeconds();
		cout << "mergeSort n: " << n << "time = " << endtime - starttime << endl;
	}

	cout << "\n\n";
	for (int n  = 10; n <= 1000000; n *= 10) {
		int*input = new int[n];
		long starttime, endtime;
		for (int i = 0; i < n; i++) {
			input[i] = n - i;
		}
		starttime = getTimeInMicroSeconds();
		quickSort(input, 0, n - 1);
		endtime = getTimeInMicroSeconds();
		cout << "quickSort n: " << n << "time = " << endtime - starttime << endl;
	}
	cout << "\n\n";
	for (int n  = 10; n <= 1000000; n *= 10) {
		int*input = new int[n];
		long starttime, endtime;
		for (int i = 0; i < n; i++) {
			input[i] = n - i;
		}
		starttime = getTimeInMicroSeconds();
		bubbleSort(input, n);
		endtime = getTimeInMicroSeconds();
		cout << "bubbleSort n: " << n << "time = " << endtime - starttime << endl;

	}

	cout << "\n\n";


	for (int n  = 10; n <= 1000000; n *= 10) {
		int*input = new int[n];
		long starttime, endtime;
		for (int i = 0; i < n; i++) {
			input[i] = n - i;
		}
		starttime = getTimeInMicroSeconds();
		selectionSort(input, n);
		endtime = getTimeInMicroSeconds();
		cout << "selectionSort n: " << n << "time = " << endtime - starttime << endl;


	}



	return 0;
}