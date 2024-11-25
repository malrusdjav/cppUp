#include "SmartPTR.h"

SmartPTR::SmartPTR(int* ptr)
{
	this->ptr = ptr;
	cout << "Constructor" << endl;
}

SmartPTR::~SmartPTR()
{
	if (ptr)
		delete ptr;
	cout << "Destructor" << endl;
}

int& SmartPTR::operator*()
{
	return *ptr;
}
