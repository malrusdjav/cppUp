#pragma once
#include <iostream>
using namespace std;

class SmartPTR
{
public:
	SmartPTR(int *ptr);
	~SmartPTR();
	int& operator*();
private:
	int* ptr = nullptr;
};


