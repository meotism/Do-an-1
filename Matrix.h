#pragma once
class Matrix
{
private:
	int _n;
	int _m;
	float **_data;
public:
	Matrix();
	~Matrix();
	Matrix(const Matrix &ans);
	
	Matrix NghichDao();
	Matrix ChuyenVi();

	void Solve();
	Matrix Compact();

	void Input();
	void Output();
	int Rank();
	float Det();

	Matrix operator*(const Matrix &m);
	Matrix& operator=(const Matrix &m);
	int getn();
	int getm();
};

