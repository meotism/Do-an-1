#include "Vector.h"

Vector::Vector()
{
	_list = NULL;
	_n = 0;
}


Vector::~Vector()
{
	delete[]_list;
}

Vector::Vector(float* val, int n)
{
	_n = n;
	_list = new float[n];
	for (int i = 0; i < _n; i++)
	{
		_list[i] = val[i];
	}

}
Vector Vector::operator=(const Vector& v) {
	return Vector(v._list, v._n);
}

void Vector::Nhap() {
	std::cout << "Nhap so phan tu vector: ";
	std::cin >> _n;
	_list = new float[_n];
	for (int i = 0; i < _n; i++)
	{
		std::cout << "Nhap phan tu thu " << i << " : ";
		std::cin >> _list[i];
	}

}

void Vector::Xuat() {
	if (_n == 0)
		std::cout << "vector rong!";
	else
		std::cout << "(";
	for (int i = 0; i < _n - 1; i++)
	{
		std::cout << _list[i] << ";";
	}
	std::cout << _list[_n - 1] << ")";
}

Vector Vector::operator+(const Vector& v){
	if (_n != v._n)
	{
		std::cout << "\n2 vector khong cung chieu nen khong cong"; return Vector(_list, _n);
	}
	else{
		float *sum = new float[_n];
		for (int i = 0; i < _n; i++)
		{
			sum[i] = _list[i] + v._list[i];
		}
		std::cout << "\nCong 2 vector:";
		return Vector(sum, _n);
	}
}
Vector Vector::operator-(const Vector& v) {
	if (_n != v._n)
	{
		std::cout << "\n2 vector khong cung chieu nen khong tru"; return Vector(_list, _n);
	}
	else{
		float *minus = new float[_n];
		for (int i = 0; i < _n; i++)
		{
			minus[i] = _list[i] - v._list[i];
		}
		std::cout << "\nTru 2 vector:";
		return Vector(minus, _n);
	}
}
Vector Vector::operator*(float k) {
	float *multi = new float[_n];
	for (int i = 0; i < _n; i++)
	{
		multi[i] = _list[i] * k;
	}
	return Vector(multi, _n);
}
float Vector::operator[](int n)
{
	return _list[n];
}
int Vector::getn()
{
	int n;
	n=_n;
	return n;
}