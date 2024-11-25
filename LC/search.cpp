#include "search.h"

void printRes(int id, int key, bool isThere)
{
	if (isThere)
		cout << "Element: " << " " << key << "" << "position " << id << endl;
	else
		cout << "there's no such element";
}

void linearSearch(int* arr, int size, int key)
{
	bool found = false;
	int id = 0;
	int i = 0;

	while (!found && i < size)
	{
		if (arr[i] == key)
		{
			id = i;
			key = arr[i];
			found = true;
		}
		i++;
	}

	printRes(id, key, found);
}
