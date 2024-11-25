#include "DuplicateValuesArray.h"


void DuplicateValuesArray(int arr[], const int size)
{
	bool twiceCount = false;

	int currEl;
	int currIndex;

	int repeatEl;
	int i = 0;
	while (!twiceCount && i < size)
	{
		currEl = arr[i];
		currIndex = i;

		for (int i = 0; i < size; i++)
		{
			if (currEl == arr[i] && i != currIndex)
			{
				twiceCount = true;
				repeatEl = arr[i];
			}
		}
		i++;
	}


	cout << twiceCount << endl;

	if (twiceCount)
	{
		cout << repeatEl << endl;
	}
}
