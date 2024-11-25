#include <iostream>
#include "DuplicateValuesArray.h"
#include <vector>
#include <list>
#include <map>
#include <string>
#include  <algorithm> 
#include "sorting.h"
#include "search.h"
#include "SmartPTR.h"
#include <memory>
#include <math.h>
using namespace std;


void DelEl(int arr[], const int size, int id_del, int& counter);
void InsEl(int arr[], const int size, int id_ins, int val_ins, int& counter);

void printArr(int arr[], const int size, int counter);
void fillArr(int* const A, const int size);
void copyArray(int* modifiableArray, int* replicableArray, int SIZE);



void SortVec(vector<int>& data);

void displayRatings(const list<int>& playersRatings);
void insertPlayerIntoOrderedList(int newPlayerRating, list<int>& playersByRating);

void multMatr(vector<vector<int>>& m1, vector<vector<int>>& m2, vector<vector<int>>& res);
void fillMatr(vector<vector<int>>& vec);
void printMatr(vector<vector<int>>& vec);

int Fact(int N);

class CompNum
{
	double re = 0;
	double im = 0;
	double r;
	double phi;

	double* trigInfo = nullptr;



public:
	CompNum() : re(0.0), im(0.0), r(0.0), phi(0.0) {} //конструктор по умолчанию
	CompNum(double real) : re(real), im(0.0) {} // конструктор преобразования (в этом случае преобразует double в CompNum, положив при этим im = 0.0)
	CompNum(double real, double imag): re(real), im(imag) {}
	CompNum(const CompNum& other) : re(other.re), im(other.im) //конструктор копирования
	{
		trigInfo = new double[2];
		trigInfo[0] = other.trigInfo[0];
		trigInfo[1] = other.trigInfo[1];
		cout << "Copy constructor" << endl;
	}


	void trigForm()
	{
		r;
		phi;

		trigInfo = new double[2];

		r = sqrt(re * re + im * im);
		phi = atan(im / re);

		trigInfo[0] = r;
		trigInfo[1] = phi;

		cout << "Radius: " << trigInfo[0] << "\t" << "Angle: " << trigInfo[1] << endl << endl;
	}

	void getData()
	{
		cout << "Real part: " << re << "\t" << "Imaginary part: " << im << endl;
		cout << endl << endl;
	}

	CompNum operator+(const CompNum& other)
	{
		CompNum res;

		res.re = this->re + other.re;
		res.im = this->im + other.im;

		return res;
	}

	CompNum operator-(const CompNum& other)
	{
		CompNum res;

		res.re = this->re - other.re;
		res.im = this->im - other.im;

		return res;
	}

	CompNum operator*(const CompNum& other) {
		return CompNum(re * other.re - im * other.im, re * other.im + im * other.re);
	}

	CompNum operator/(const CompNum& other)
	{
		CompNum res;
		const double im2 = other.re * other.re + other.im * other.im;
		res.re = (re * other.re + im * other.im) / im2;
		res.im = (im * other.re - re * other.im) / im2;

		return res;
	}

	const CompNum& operator=(const CompNum& other)
	{
		if (this == &other)
			return *this;

		trigInfo = new double[2];
		trigInfo[0] = other.trigInfo[0];
		trigInfo[1] = other.trigInfo[1];
		cout << "Operator= is working" << endl;
		
	}

	~CompNum()
	{
		cout << "Destructor" << endl;

		delete[] trigInfo;
	}
};


struct Node
{
	int data;
	Node* left;
	Node* right;
};

struct Point2D
{
	int x, y;
};

struct Point3D
{
private:
	int x, y, z;
public:
	Point3D(double x, double y, double z);
	void getDistanceTo(Point3D& other);
};

Point3D::Point3D(double x, double y, double z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

void Point3D::getDistanceTo(Point3D& other)
{
	cout << sqrt((x - other.x) * (x - other.x) + (y - other.y) * (y - other.y) + (z - other.z) * (z - other.z)) << endl;
}


Node* createNode(int data)
{
	Node* newNode = new Node();
	newNode->data = data;
	newNode->left = newNode->right = nullptr;

	return newNode;
}

void printTree(Node* root)
{
	if (root == nullptr) return;

	cout << root->data << endl;
	printTree(root->left);
	printTree(root->right);
}




int main()
{
	const int SIZE = 10;

	const int size1 = 5;
	const int size2 = 7;

	int *A1 = new int[size1];
	int *A2 = new int[size2];
    int nums[10] = { 5, 12, -80, 1, -2, 3, 4, 6, -1, 10};
	Order ord = Order::descending;


	/*delete[] A1; //free the memory originally occupied by the array
	//A1 = new int[size2]; // allocate new memory which size is equal to the size of the replicable array

	//for (int i = 0; i < size2; i++)
	//{
	//	A1[i] = A2[i]; // copy all elements from the target array
	//}

	int counter = 6;
	DuplicateValuesArray(nums, SIZE);
	PrintArray(nums, SIZE, counter);

	InsEl(nums, SIZE, 4, 3, counter);
	PrintArray(nums, SIZE, counter);

	DelEl(nums, SIZE, 0, counter);
	PrintArray(nums, SIZE, counter);*/
	vector<int> vec = { 1, 3, 5, -8, 10, 0 };


	//printArr(nums, 10);

	linearSearch(nums, SIZE, -80);

	//printArr(nums, 10);

	list<int> allPlayers = { 10, 2, 1, 4, 8, 9, 10, 1 ,4, 8, 5,3, 7, 6, 0, 11 };
	
	list<int> beginners; //rating 1-5
	list<int> pros;      //rating 6-10

	/*for (list<int>::iterator it = allPlayers.begin(); it != allPlayers.end(); it++)
	{
		int rating = *it;
		if (rating >= 1 && rating <= 5)
			insertPlayerIntoOrderedList(rating, beginners);
		else if (rating >= 6 && rating <= 10)
			insertPlayerIntoOrderedList(rating, pros);
		else
			cout << rating << " " << ": rating doesn't correspond to either of the groups!" << endl << endl;
	}*/

	/*displayRatings(beginners);
	displayRatings(pros);*/

	/*map<string, list<string>> myClothes;

	list<string> shoes{ "boots", "sneakers", "clogs" };
	list<string> outerwear{"skirt", "coat", "jeans"};
	list<string> headwear{ "hat", "cap", "bandana" };

	myClothes.insert(pair<string, list<string>>("My shoes", shoes));
	myClothes.insert(pair<string, list<string>>("My outwear", outerwear));
	myClothes.insert(pair<string, list<string>>("My headwear", headwear));

	for (auto pair : myClothes)
	{
		cout << pair.first << " - ";
		for (auto item : pair.second)
			cout << item << ", ";
		cout << endl;
	}*/

	//level 1
	Node* root = createNode(1);

	//level2
	root->left = createNode(2);
	root->right = createNode(3);

	//level 3
	root->left->left = createNode(4);
	root->left->right = createNode(5);
	root->right->right = createNode(6);
	root->right->left = createNode(7);

	//level 4
	root->left->right->left = createNode(9);
	root->right->right->left = createNode(15);

	//printTree(root);
	
	//Операции приведения типов

	//1. const_cast: снимает или добавляет модификатор (const) для текущего типа данных

	//Снятие
	int a = 10; // имеется некоторая целочисленная переменная
	const int* ptr_a = &a; // на эту переменную ведет константный (не может менять ее значение через разыменование *) указатель
	int* ptr = const_cast<int*>(ptr_a); //снятие модификатора const: этот указатель можеть менять значение через разыменование *

	// *ptr = 4; - работает
	// *ptr_a = 4; - не работает

	// Добавление 
	const int * ptr_cnst = const_cast<const int*>(ptr);

	//То же самое допустимо для ссылок

	const double b = -10.0;
	const double& cnstRefB = b;
	double& refB = const_cast<double&>(cnstRefB);
	const double& refB_c = const_cast<const double&>(refB);


	// Недопустимо для обычных переменных
	// double c = const_cast<double>(a); - не работает

	// P.S. Лучше им не пользоваться
	 
	//2. reinterpret_cast: преобразование одного типа в другой с некоторой 
	// проверкой со стороны компилятора на возможность записанного действия
	
	//Применим к указателям и ссылками. Не изменяет const
	// int *ptr = reinterpret_cast<int*>(ptr_a) - не работает
	// char c = reinterpret_cast<char>(a) - не работает
	
	int val = 10;
	int* valPtr = &val;
	char* ptr_ch = reinterpret_cast<char*>(valPtr);
	char& refch = reinterpret_cast<char&>(val);

	// Возможно приведение типов пользовательских типов данных
	Point2D pt{1, 2};

	Point3D* ptr_3d = reinterpret_cast<Point3D*>(&pt);
	Point3D& lnk_3d = reinterpret_cast<Point3D&>(pt);

	//3. static_cast: преобразованине типов с учетом цепочки
	//наследования классов или структур
	 
	/*char type_char{ 'a' };
	short type_short{ 10 };
	int type_int{ 0 };
	double type_double{ 0 };

	char* char_ptr{ &type_char };
	short* type_ptr{ &type_short };
	int* type_ptr{ &type_int };
	double* type_ptr{ &type_double };*/

	//static_cast не может приводить указатели к обычной переменной
	//и приводить несвязанные между собой операторы (в отличие от reinterpret_cast)
	  
	Point2D* p_2d = new Point2D();

	//Point3D* ptr_3d = static_cast<Point3D*>(p_2d); - ошибка (сработает, если наследлвать структуру Point3D от Point2D)
	/*Point3D* ptr_3d = reinterpret_cast<Point3D*>(p_2d);
	delete p_2d;*/

	Point3D p1_3d(1.3, -3.5, 5.0);
	Point3D p2_3d(-2.4, 3.1, 10);

	//p1_3d.getDistanceTo(p2_3d);

	CompNum c1(3, 4);

	c1.trigForm();

	CompNum c2;

	c2 = c1;
	c2.trigForm();

/*	CompNum c2(1.9, -4);

	CompNum c3 = c1 * c2*/;

	/*c3.getData();*/

	//4. dynamic_cast - преобразование типов с учетом цепочки наследования
	// классов или структурр в процессе выполнения программы (динамически)
	// Если переданный в круглых скобках указатель являетсяобъектом
	// класса, к которому приводится преобразование в фигурных скобках,
	// то указатель будет ссылаться на объект, иначе dynamic_cast вернет nullptr
	// static_pointer_cast & dynamic_pointer_cast - аналоги для умных указателей
	// Может работать только с классами, содержащими виртуальные методы
	// P.S. лучше не использоваться, т.к. может уменьшить скорость программы 
	//delete[] A1;
	//delete[] A2;

	vector<vector<int>> stuff;


	/*fillMatr(stuff);
	printMatr(stuff);*/

	vector<vector<int>> v1 = { {0, -2, 4, 2}, {5, 2, 1, 6}, {-6, 8, 1, -3} };
	vector<vector<int>> v2 = { {7, 9, -8}, {-1, 6, -3}, {10, 9, 4}, {3, 1, 2} };
	vector<vector<int>> v3 = { {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0} };

	/*printMatr(v1);
	printMatr(v2);

	multMatr(v1, v2, v3);
	printMatr(v3);*/

	return 0;

} 

void DelEl(int arr[], const int size, int id_del, int& counter)
{
	for (int i = id_del; i < size; i++)
		arr[i] = arr[i + 1];

	if (counter > 0) counter--;

}

void InsEl(int arr[], const int size, int id_ins, int val_ins, int& counter)
{
	int end = (counter < size) ? counter : size - 1;
	for (int i = end; i > id_ins; i--)
		arr[i] = arr[i - 1];
	arr[id_ins] = val_ins;

	if (counter < size) counter++;
}

void printArr(int arr[], const int size, int counter)
{
	for (int i = 0; i < size; i++)
	{
		cout << "#" << i << " " << arr[i] << endl;
	}
	cout << "Total: " << counter;

	cout << endl << endl;
}

void fillArr(int* const A, const int size)
{
	for (int i = 0; i < size; i++)
	{
		A[i] = ((i * i - 1) * 3 - 2) * size;
	}
}

void SortVec(vector<int>& data)
{
	sort(data.begin(), data.end());
}


void displayRatings(const list<int>& playersRatings)
{
	for (list<int>::const_iterator it = playersRatings.begin(); it != playersRatings.end(); it++)
	{
		cout << "Player's rating: " << *it << endl;
	}
	cout << endl << endl;
}

void insertPlayerIntoOrderedList(int newPlayerRating, list<int>& playersByRating)
{
	for (list<int>::const_iterator it = playersByRating.begin(); it != playersByRating.end(); it++)
	{
		if (*it > newPlayerRating)
		{
			playersByRating.insert(it, newPlayerRating);
			return;
		}
	}
	playersByRating.push_back(newPlayerRating);
}

void multMatr(vector<vector<int>>& m1, vector<vector<int>>& m2, vector<vector<int>>& res)
{
	int resEl;
	const int outerSize = m1.size();
	const int innerSize = m2[0].size();
	const int subInnerSize = m1[0].size();
	for (int i = 0; i < outerSize; i++)
	{
		for (int j = 0; j < innerSize; j++)
		{
			for (int k = 0; k < subInnerSize; k++)
			{
				res[i][j] += m1[i][k] * m2[k][j];
			}
		}
	}
}

void fillMatr(vector<vector<int>>& matr)
{
	int currEl;
	for (int i = 0; i < 3; i++)
	{
		vector<int> tmp;
		for (int j = 0; j < 3; j++)
		{
			cout << "Enter " << i << j << " element" << endl;
			cin >> currEl;
			tmp.push_back(currEl);
		}
		matr.push_back(tmp);
	}
}

void printMatr(vector<vector<int>>& matr)
{
	int innerSize = matr[0].size();
	int outerSize = matr.size();
	
	for (int i = 0; i < outerSize; i++)
	{
		for (int j = 0; j < innerSize; j++)
			cout << matr[i][j]<<" ";
		cout << endl << endl;
	}
}

int Fact(int N)
{
	if (N == 0)
		return 0;

	if (N == 1)
		return 1;

	return N * Fact(N - 1);
}

void copyArray(int* modifiableArray, int* replicableArray, int SIZE)
{
	delete[] modifiableArray; //free the memory originally occupied by the array
	modifiableArray = new int[SIZE]; // allocate new memory which size is equal to the size of the replicable array

	for (int i = 0; i < SIZE; i++)
	{
		modifiableArray[i] = replicableArray[i]; // copy all elements from the target array
	}
}
