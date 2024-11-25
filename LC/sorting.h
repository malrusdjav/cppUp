#pragma once
#include <iostream>
#include <vector>

enum Order
{
	descending, ascending
};

using namespace std;


void printArr(int* arr, int size);
void printVec(vector<int> data);


void insertSort(int* arr, int size);
void bubbleSort(int* arr, int size, Order ord);
void selectSort(int* arr, int size);
void quickSort(int* arr, int left, int right);

void mergeSort(vector<int>& arr);
void merge(vector<int>& leftArr, vector<int>& rightArr, vector<int>& arr);


