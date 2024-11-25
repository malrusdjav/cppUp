#include "sorting.h"

void printArr(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "#" << i << " " << arr[i] << endl;
	}
	cout << endl << endl;
}

void printVec(vector<int> data)
{
	for (int n : data)
		cout << n << endl;
	cout << endl << endl;
}

// O(n^2)
void insertSort(int* arr, int size)
{
	for (int i = 1; i < size; i++)
	{
		int k = i;
		while (k > 0 && arr[k - 1] > arr[k])
		{
			int tmp = arr[k - 1];
			arr[k - 1] = arr[k];
			arr[k] = tmp;
			k--;
		}
	}

}

// O(n^2)
void bubbleSort(int* arr, int size, Order ord)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			switch (ord)
			{
			case Order::descending:
			{
				if (arr[j] < arr[j + 1])
				{
					int tmp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = tmp;
				}
				break;
			}

			case Order::ascending:
			{
				if (arr[j] > arr[j + 1])
				{
					int tmp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = tmp;
				}
				break;
			}		
			}
			
		}
	}
}

//O(n^2)
void selectSort(int* arr, int size)
{
	/*for (int k = 0; k < size - 1; k++)
	{
		int id_min = k;
		for (int i = k + 1; i < size; i++)
		{
			if (arr[i] < arr[id_min])
				id_min = i;
		}

		int tmp = arr[k];
		arr[k] = arr[id_min];
		arr[id_min] = tmp;
	}*/

	for (int k = 0; k < size - 1; k++)
	{
		int id_min = k;
		for (int i = k + 1; i < size; i++)
		{
			if (arr[i] < arr[id_min])
				id_min = i;
		}

		int tmp = arr[k];
		arr[k] = arr[id_min];
		arr[id_min] = tmp;
	}
}

//O(n*log(n))
void quickSort(int* arr, int left, int right)
{
	if (left > right) return;
	int sup_el = arr[(left + right) / 2];
	int i = left;
	int j = right;
	while(i <= j)
	{
		while (arr[i] < sup_el) i++;
		while (arr[j] > sup_el) j--;
		if (i <= j)
		{
			int tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			i++;
			j--;
		}
	}
	quickSort(arr, left, j);
	quickSort(arr, i, right);
}

//O(n*log(n))
void mergeSort(vector<int>& arr)
{
	int length = arr.size();
	if (length <= 1) return; //base case

	int middle = length / 2;

	vector<int> leftArr (middle);
	vector<int> rightArr(length - middle);


	int i = 0; //left array
	int j = 0; //right array

	for (; i < length; i++) {
		if (i < middle) {
			leftArr[i] = arr[i];
		}
		else {
			rightArr[j] = arr[i];
			j++;
		}
	}
	mergeSort(leftArr);
	mergeSort(rightArr);
	merge(leftArr, rightArr, arr);
}

void merge(vector<int>& leftArr, vector<int>& rightArr, vector<int>& arr)
{
	int leftSize = arr.size() / 2;
	int rightSize = arr.size() - leftSize;
	int i = 0, l = 0, r = 0; //indices

	//check the conditions for merging
	while (l < leftSize && r < rightSize) {
		if (leftArr[l] < rightArr[r]) {
			arr[i] = leftArr[l];
			i++;
			l++;
		}
		else {
			arr[i] = rightArr[r];
			i++;
			r++;
		}
	}
	while (l < leftSize) {
		arr[i] = leftArr[l];
		i++;
		l++;
	}
	while (r < rightSize) {
		arr[i] = rightArr[r];
		i++;
		r++;
	}
}
