#pragma once
#include<iostream>
class Vector
{
private:
	float* _list;
	int _n;
public:
	Vector();
	~Vector();
	void Nhap();
	void Xuat();
	Vector(float *val, int n);
	Vector operator+(const Vector&);
	Vector operator-(const Vector&);
	Vector operator*(float k);
	Vector operator=(const Vector&);
	float operator[](int n);
	int getn();
};

