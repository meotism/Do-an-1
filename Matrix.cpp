#include "Matrix.h"
#include<iostream>
#include<cmath>
#include<vector>


Matrix::Matrix()
{
	_n = 0;
	_m = 0;
	this->_data = NULL;
}

Matrix::~Matrix()
{
	if (_data != NULL){
		for (int i = 0; i < _n; i++)
			delete[] _data[i];
		delete[] _data;
	}
}



Matrix::Matrix(const Matrix &ans)
{
	_n = ans._n;
	_m = ans._m;
	_data = new float*[_n];
	for (int i = 0; i < _n; i++)
		_data[i] = new float[_m];
	for (int i = 0; i < _n; i++){
		for (int j = 0; j < _m; j++){
			_data[i][j] = ans._data[i][j];
		}
	}
}


void Matrix::Input()
{
	std::cout << "Nhap so dong: ";
	std::cin >> _n;
	std::cout << "\nNhap so cot: ";
	std::cin >> _m;

	_data = new float*[_n];
	for (int i = 0; i < _n; i++)
		_data[i] = new float[_m];
	for (int i = 0; i < _n; i++){
		for (int j = 0; j < _m; j++){
			std::cout << "Nhap a[" << i << "," << j << "]:  ";
			std::cin >> _data[i][j];
		}
	}
}

void Matrix::Output(){
	std::cout<<"\n";
	for (int i = 0; i < _n; i++){
		for (int j = 0; j < _m; j++)
			std::cout << _data[i][j]<<" ";
		std::cout << std::endl;
	}
}

float** CatMatran(float **a, int dong, int cot,int n){
	float** b = new float*[n - 1];
	for (int i = 0; i < n - 1; i++)
		b[i] = new float[n - 1];

	int m, k;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			m = i; k = j;
			if (i >= dong)
				m++;
			if (j >= cot)
				k++;
			b[i][j] = a[m][k];
		}
	}
	return b;
}



float DinhThuc(float **a, int n){
	if (n < 1)
		return 0;
	if (n == 1)
		return a[0][0];
	if (n == 2)
		return a[0][0] * a[1][1] - a[0][1] * a[1][0];

	float ans = 0;

	for (int i = 0; i < n; i++){
		float **b=CatMatran(a, 0, i,n);
		ans += a[0][i] * pow(-1, i)*DinhThuc(b, n - 1);
		
		for (int m = 0; m < n - 1; m++)
			delete[]b[m];
		delete[]b;
	}

	return ans;
}

float Matrix::Det(){
	float ans = DinhThuc(_data, _n);
	return ans;
}

Matrix Matrix::NghichDao(){
	if (this->Det() == 0)
		return *this;
	Matrix ans;
	ans._n = _n;
	ans._m = _m;
	ans._data = new float*[_n];
	for (int i = 0; i < _n ; i++)
		ans._data[i] = new float[_n];

	float dt = this->Det();
	for (int i = 0; i < _n; i++)
	{
		for (int j = 0; j < _n; j++)
		{
			float **b = CatMatran(_data, i, j, _n);
			ans._data[j][i] = (pow((-1), i + j)*DinhThuc(b, _n - 1))/dt;
			
			for (int m = 0; m < _n-1; m++)
				delete[]b[m];
			delete[]b;
		}
	}

	return ans;
}
Matrix &Matrix::operator=(const Matrix &m){
	if (this != &m){
		if (_data != NULL)
		{
			for (int i = 0; i < _m; i++)
				delete[]_data[i];
			delete[]_data;
		}

		_n = m._n;
		_m = m._m;
		_data = new float*[_n];
		for (int i = 0; i < _n; i++)
			_data[i] = new float[_m];

		for (int i = 0; i < _n; i++){
			for (int j = 0; j < _m; j++){
				_data[i][j] = m._data[i][j];
			}
		}
		return *this;
	}
}

//this is fuction: swap row1 to row 2
void Swap(float **a,int row1,int row2,int col){

	for (int i = 0; i < col; i++)
	{
		float temp = a[row1][i];
		a[row1][i] = a[row2][i];
		a[row2][i] = temp;
	}
}

Matrix Matrix::ChuyenVi(){
	Matrix ans;
	ans._n = _m;
	ans._m = _n;

	ans._data = new float*[ans._n];
	for (int i = 0; i < ans._n; i++)
		ans._data[i] = new float[ans._m];
	for (int i = 0; i < ans._n; i++){
		for (int j = 0; j < ans._m; j++){
			ans._data[i][j] = _data[j][i];
		}
	}
	return ans;
}







int Matrix::Rank(){
	Matrix copy = *this;
	if (copy._n > copy._m)
		copy = copy.ChuyenVi();
	int rank = copy._n;

	int i = 0;
	int j = 0;

	while (i < copy._n&&j < copy._m){
		if (copy._data[i][j]!=0){
			for (int k = i + 1; k < copy._n; k++){
				float mult = (float)copy._data[k][j] / copy._data[i][j];
				for (int h = 0; h < copy._m; h++)
				{
					copy._data[k][h] -= mult * copy._data[i][h];
				}
			}

			i = i + 1;
			j = j + 1;
		}
		else
		{
			int cout = 0;
			for (int k = i + 1; k < copy._n; k++)
			{
				if (copy._data[k][j]){
					Swap(copy._data, k, i, copy._m);
					break;
				}
				else cout++;
			}
			if (cout == copy._n - i-1)
				j=j+1;

		}
		//copy.Output();
	}
	for (int i = copy._n-1; i >= 0; i--){
		int cout = 0;
		for (int j = 0; j < copy._m; j++){
			if (copy._data[i][j] == 0)
				cout++;
		}
		if (cout == copy._m)
			rank--;
		else
			break;
	}

	return rank;
}

Matrix Matrix::Compact()
{
	Matrix copy = *this;
	if (copy._n > copy._m)
		copy = copy.ChuyenVi();
	int rank = copy._n;

	int i = 0;
	int j = 0;

	while (i < copy._n&&j < copy._m){
		if (copy._data[i][j] != 0){
			for (int k = 0; k < copy._n; k++){
				if (k != i){
					float mult = (float)copy._data[k][j] / copy._data[i][j];
					for (int h = 0; h < copy._m; h++)
					{
						copy._data[k][h] -= mult * copy._data[i][h];
					}
				}
			}

			i = i + 1;
			j = j + 1;
		}
		else
		{
			int cout = 0;
			for (int k = i + 1; k < copy._n; k++)
			{
				if (copy._data[k][j]){
					Swap(copy._data, k, i, copy._m);
					break;
				}
				else cout++;
			}
			if (cout == copy._n - i - 1)
				j = j + 1;

		}
	}
	for (int i = copy._n - 1; i >= 0; i--){
		int cout = 0;
		for (int j = 0; j < copy._m; j++){
			if (copy._data[i][j] == 0)
				cout++;
		}
		if (cout == copy._m)
			rank--;
		else
			break;
	}
	return copy;
	
}


Matrix Matrix::operator*(const Matrix& m)
{
	if (_m == m._n){
		Matrix ans;
		ans._n = m._m;
		ans._m = _n;
		ans._data = new float*[m._m];
		for (int i = 0; i < m._m; i++)
			ans._data[i] = new float[_n];

		int sum = 0;
		for (int i = 0; i < m._m; i++) {
			for (int j = 0; j < _n; j++) {
				sum = 0;
				for (int h = 0; h < _m; h++) {
					sum = sum + this->_data[i][h] * m._data[h][j];
				}
				std::cout << std::endl;
				ans._data[i][j] = sum;
			}
		}
		return ans;
	}
	else
	std::cout << "Khong the nhan 2 ma tran. " << std::endl; return *this;
}



//return true neu thuoc nguoc lai return false
bool KTThuocMang(std::vector<int> arr,int x){
	for (int i = 0; i < arr.size();i++)
	  if (arr[i] == x)
		return true;

	return false;
}


void TruHaiMang(float *a,float *b,float k, int n){
	for (int i = 0; i < n; i++)
		a[i] = (a[i] - b[i] * k);
}



void Matrix::Solve(){
//1 Nhap 
	int n;
	std::cout << "\nNhap so an: ";
	std::cin >> n;
	_n = n;
	_m = n + 1;
	_data = new float*[_n];
	for (int i = 0; i < _n; i++)
		_data[i] = new float[_m];
	for (int i = 0; i < _n; i++){
		for (int j = 0; j < _m; j++){
			std::cout << "Nhap a[" << i << "," << j << "]:  ";
			std::cin >> _data[i][j];
		}
	}
	
	this->Output();
//2 Kronecker - Capeli
	Matrix ans;
	Matrix A = *this;
	A._m--;
	ans = this->Compact();
	ans.Output();

	int rank1 = A.Rank();
	int rank2 = this->Rank();
	//std::cout << "\n" << rank1<<" " << rank2;
	if (rank2 == rank1 + 1)
		std::cout << "\nHe phuong trinh vo nghiem.";
	else if (rank2 == rank1&&rank1 == n)
	{
		std::cout << "\n He phuong trinh co nghiem duy nhat.";
		for (int i = 0; i < ans._n; i++)
		{
			std::cout << "\nNghiem x"<<i+1<<" =" << (double)ans._data[i][ans._m-1]/ans._data[i][i];
		
		}
		//ans.Output();
	}
	else{

		int dong = ans._n;
		int cot = ans._m;
		std::cout << "\n He phuong trinh vo so nghiem.\n";
		int soan =_n-rank2 ;
		
		float** a= new float*[dong];
		for (int i = 0; i < dong; i++)
			a[i] = new float[soan + 1];

		for (int i = 0; i < dong; i++){
			for (int j = 0; j < soan + 1; j++){
				a[i][j] = 0;
			}
		}

		std::vector<int> arr;
		std::vector<int> arr_an;
		for (int i = 0; i < dong; i++){
			for (int j = 0; j < cot; j++){
				if (ans._data[i][j] != 0)
				{
					arr.push_back(j);
					break;
				}
			}
		}
		/*for (int i = 0; i < arr.size(); i++)
			std::cout << arr[i] << " ";*/

		int index = 1;
		for (int i = 0; i < dong; i++){
			if (KTThuocMang(arr, i)==false){
				arr_an.push_back(i);
				a[i][index] = 1;
				index++;
			}
		}

	  /*	for (int i = 0; i < dong; i++){
			std::cout << std::endl;
			for (int j = 0; j < soan + 1; j++){
				std::cout << a[i][j] << " ";
			}
			std::cout << std::endl;
		}*/

		//Giai
		for (int i = dong-1; i >= 0; i--){
			for (int j = 0; j < cot; j++){
				if (ans._data[i][j]!=0){
					a[j][0] = ans._data[i][cot - 1];
					for (int h = cot - 2; h > j; h--){
						 TruHaiMang(a[j], a[h], ans._data[i][h], soan+1);
					}
					for (int h = 0; h < soan + 1; h++)
						a[j][h] = a[j][h] / ans._data[i][j];

					break;
				}
			}
		}

		for (int i = 0; i < dong; i++){
			std::cout << std::endl;
			std::cout << "x" << i + 1 << "  =  ";
			std::cout << a[i][0];
			for (int j = 1; j < soan; j++){
				if (a[i][j] != 0)
					std::cout << " + " << a[i][j] << "*t" << arr_an[j - 1] + 1;
			}
			if (a[i][soan] != 0)
				std::cout <<" + "<< a[i][soan] << "*t" << arr_an[soan - 1] + 1;
			std::cout << std::endl;
		}

	}
}


int Matrix::getn(){
	int n;
	n = _n;
	return n;
}
int Matrix::getm(){
	int m;
	m = _m;
	return m;
}

 