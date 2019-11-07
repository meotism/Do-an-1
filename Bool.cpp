#include "Bool.h"
#include<iostream>

Bool::Bool()
{
	_key1 = "xyztabcdefghijklmnopqrsuvw";
	_key2 = "XYZTABCDEFGHIJKLMNOPQRSUV";
}
Bool::~Bool()
{
}


bool KhongThuocMang(std::vector<int> arr, int x){
	int len = arr.size();
	for (int i = 0; i < len; i++)
	if (arr[i] == x)
		return false;

	return true;
}


bool KhongThuocMang(std::vector<std::string> str, std::string s){
	int len = str.size();
	for (int i = 0; i < len; i++)
	if (str[i] == s)
		return false;

	return true;
}
bool KhongThuocMang(std::vector<TeBao> tb, TeBao t){
	int len = tb.size();
	for (int i = 0; i < len; i++)
	if (tb[i].str == t.str)
		return false;

	return true;

}

void Bool::Input2(){
	std::cout << "\nNhap so luong bien(2<=n<=10): ";
	std::cin >> _n;
	if (_n >= 5){
		_key1 = "abcdefghijklmnopqrsuvw";
		_key2 = "ABCDEFGHIJKLMNOPQRSUV";
	}
	std::cout << "Nhap ham bool: (0,1,2,..."<<pow(2,_n)-1<<" :)(nhap -1 de dung): ";
	int temp=0;
	do{
		std::cin >> temp;
		if (KhongThuocMang(_dayso, temp))
		_dayso.push_back(temp);
	} while (temp != -1);
	

}



void Bool::Input(){
	std::cout << "\nNhap so luong bien(2<=n<=10): ";
	std::cin >> _n;
	if (_n >= 5){
		_key1 = "abcdefghijklmnopqrsuvw";
		_key2 = "ABCDEFGHIJKLMNOPQRSUV";
	}
	
		std::cout << "Nhap ham bool: (";
		for (int i = 0; i < _n; i++)
		{
			std::cout << _key1[i] << " " << _key2[i] << " ";
		}
		std::cout << "): ";
		std::cin >> _str;
	

}

//Chuyen 1 chuoi thanh so theo nhi phan
std::string ChuoiSo(std::string str, int n,std::string key1,std::string key2){
	std::string temp;
	
	for (int i = 0; i < n; i++){
		if (str.find(key1[i]) !=-1)
			temp += '1';
		else if (str.find(key2[i]) !=-1)
			temp += '0';
		else
			temp += '_';
	}

	return temp;
}

//Chuyen so thanh Chuoi
std::string SoChuoi(std::string str, std::string key1, std::string key2){
	int len = str.length();
	std::string ans;
	int cout = 0;
	for (int i = 0; i < len; i++)
	{
		if (str[i] == '0')
			ans.push_back(key2[i]);
		else if (str[i] == '1')
			ans.push_back(key1[i]);
		else
			cout++;
	}
	if (cout == len)
		ans.push_back ('1');
	return ans;
}


std::string NhiPhan(int n,int chieudai){
	std::string ans, temp;

	int sodu;
	char c;
	while (n > 0){
		sodu = n % 2;
		c = sodu + 48;
		temp.push_back(c);
		n = n / 2;
	}
	int len = temp.size();
	int chenhlech = chieudai - len;
	for (int i = 0; i< chenhlech; i++)
		ans.push_back('0');
	for (int i = 0; i < len; i++)
		ans.push_back(temp[len - i - 1]);
	
	return ans;
}

//00_1 co con la 0001 0011 hay 1 11
//Return true neu la con
bool KTcon(std::string s1, std::string s2){
	int len = s1.length();
	for (int i = 0; i < len; i++){
		if (s2[i] != '_')
		{
			if (s1[i] != s2[i])
				return false;
		}
	}
	return true;
}



std::vector<std::string> SinhSo(std::string str){
	std::vector<std::string> ans;

	int n = str.length();

	for (int i = 0; i < pow(2, n); i++){
		std::string temp = NhiPhan(i,n);
		if (KTcon(temp, str))
			ans.push_back(temp);
	}

	return ans;
}



void Bool::MinTerm(){
	std::string temp;
	_dayso.pop_back();
	for (int i = 0; i < _dayso.size(); i++)
	{
		std::cout << _dayso[i] << " ";
		temp = NhiPhan(_dayso[i], this->_n);
		std::cout << temp <<" "<<SoChuoi(temp,_key1,_key2)<<std::endl;
		_minterm.push_back(temp);
	}
}


void Bool::Token(){
	std::vector<std::string> k;
	int len = _str.length();
	std::string temp;

	for (int i = 0; i < len; i++){

		if (_str[i] != 'v'  && _str[i] != 'V')
			temp += _str[i];
		if (i == len - 1 || _str[i] == 'v' || _str[i] == 'V')
		{
			temp = ChuoiSo(temp, _n, _key1, _key2);
			k.push_back(temp);
			temp = "";
		}

	}

	for (int i = 0; i < k.size(); i++){
		std::vector < std::string> ss = SinhSo(k[i]);
		/*std::cout << k[i] << " " << std::endl;*/

		for (int i = 0; i < ss.size(); i++){
			if (KhongThuocMang(_minterm,ss[i]))
			_minterm.push_back(ss[i]);
		}
	}

	/*std::cout << "MidTerm: " << std::endl;
	for (int i = 0; i < _minterm.size(); i++)
		std::cout << _minterm[i] << std::endl;*/
	
}


//Kiem tra 2 chuoi co cong vs nhau duoc hay ko
bool KTcong(std::string s1, std::string s2){
	int len = s1.length();
	int khac = 0;
	for (int i = 0; i < len; i++){
		if (s1[i] == '_'&&s2[i] != '_')
			return false;
		if (s2[i] == '_'&&s1[i] != '_')
			return false;
		if ((s1[i] == '0'&&s2[i] == '1') || (s2[i] == '0'&&s1[i] == '1'))
			khac++;
	}

	if (khac == 1)
		return true;
	return false;
}


std::string  CongHaiChuoi(std::string s1, std::string s2){
	int len = s1.length();
	int index = 0;
	std::string ans;

	for (int i = 0; i < len; i++){
		if ((s1[i] == '0'&&s2[i] == '1') || (s2[i] == '0'&&s1[i] == '1'))
		{
			index = i; break;
		}
	}

	for (int i = 0; i < len; i++){
		if (i == index)
			ans.push_back('_');
		else 
			ans.push_back(s1[i]);
	}
	return ans;
}

//Tim ra te bao lon
void Bool::TeBaoLon(){
	std::vector<std::vector<TeBao>> arr;

	//Dua thong tin vao arr[0]
	std::vector<TeBao> temp;
	for (int i = 0; i < _minterm.size(); i++){
		TeBao t;
		t.str = _minterm[i]; t.heso = 0;
		temp.push_back(t);
	}

	//for (int i = 0; i < temp.size(); i++)
	//	std::cout << "He so: " << temp[i].heso << " chuoi: " << temp[i].str << std::endl;

	arr.push_back(temp);

	for (int index = 0; index < _n; index++){
		temp.clear();
		TeBao tam;
		for (int i = 0; i < arr[index].size(); i++){
			for (int j = i+1; j < arr[index].size(); j++){
				if (KTcong(arr[index][i].str, arr[index][j].str)){
					tam.str = CongHaiChuoi(arr[index][i].str, arr[index][j].str);
					arr[index][i].heso = 1;
					arr[index][j].heso = 1;
					tam.heso = 0;
					if (KhongThuocMang(temp, tam))
						temp.push_back(tam);
				}
			}
		}
		arr.push_back(temp);
	}


	for (int i = 0; i < arr.size(); i++)
	{
		for (int j = 0; j < arr[i].size(); j++){
			if (arr[i][j].heso == 0){
				_tblon.push_back(arr[i][j].str);
			}
		}
	}
}

void DienMang(int** arr, int dong, int cot,std::vector<std::string> _minterm,std::vector<std::string> _tblon)
{
	std::cout << std::endl;
	for (int i = 0; i < dong; i++){
		for (int j = 0; j < cot; j++){
			arr[i][j] = 0;
			if (KTcon(_minterm[j], _tblon[i])){
				arr[i][j] = 1;
			}
			//std::cout << arr[i][j] << " ";
		}
		//std::cout << std::endl;
	}

}


//Tim cot nao co tong bang 1 va xoa sau do tra ve mang pet
void Buoc1(int** arr, int dong, int cot, std::vector<int> &pet){
	for (int i = 0; i < cot; i++){
		int tong = 0;
		int pos = -1;
		for (int j = 0; j < dong; j++){
			tong += arr[j][i];
			if (arr[j][i] == 1)
				pos = j;
		}
		//Neu tong bang  1 thi xoa
		if (tong == 1){
			pet.push_back(pos);
			for (int j = 0; j < cot; j++){
				if (arr[pos][j] == 1){
					for (int h = 0; h < dong; h++)
						arr[h][j] = 0;
				}
			}

		}
	}
}


bool Insert(std::vector<int> a, int x){
	for (int i = 0; i < a.size(); i++)
	if (x == a[i])
		return false;
	return true;
}

bool TrungDong(std::vector<std::vector<int>> a, std::vector<int> b){
	int len = a.size();
	int lenb = b.size();
	
	for (int i = 0; i < len; i++){
		int leni = a[i].size();
		if (leni == lenb){
			int tonga, tongb, ticha, tichb;
			tonga = tongb = 0;
			ticha= tichb = 1;
			for (int j = 0; j < lenb; j++){
				ticha *= a[i][j];
				tonga += a[i][j];
				tichb *= b[j];
				tongb += b[j];
			}
			if (tonga == tongb&&ticha == tichb)
				return false;

		}
	}
	return true;
}

void DeQuy(std::vector<std::vector<int>> petlogic, std::vector<std::vector<int>> &ans, int dong, int lv, std::vector<int> temp){
	if (lv == dong){
		if (TrungDong(ans, temp) == true)
			ans.push_back(temp);
		return;
	}

	int len;
	len = petlogic[lv].size();

	for (int i = 0; i < len; i++){
		std::vector<int> copy = temp;
		if (Insert(copy, petlogic[lv][i]) == true)
			copy.push_back(petlogic[lv][i]);
		DeQuy(petlogic, ans, dong, lv + 1, copy);
	}
}

void Buoc2(int** a, int dong, int cot, std::vector<int> pet, std::vector<std::string> tblon,std::string _key1,std::string _key2){
	std::vector<std::vector<int>> petlogic, ans;
	for (int i = 0; i < cot; i++){
		std::vector<int> temp;
		for (int j = 0; j < dong; j++){
			if (a[j][i] == 1)
				temp.push_back(j);
		}
		if (temp.size() != 0)
			petlogic.push_back(temp);
	}

	//In mang
	int len = petlogic.size();
	/*std::cout << std::endl;
	for (int i = 0; i < len; i++){
		std::vector<int> temp = petlogic[i];
		int templen = petlogic[i].size();
		for (int j = 0; j < templen; j++)
			std::cout << petlogic[i][j] << " ";
		std::cout << std::endl;
	}
*/
	//2
	int lv = 0;
	std::vector<int> temp;
	DeQuy(petlogic, ans, len, lv, temp);


	len = ans.size();
	/*std::cout << "ans: \n";
	for (int i = 0; i < len; i++){
		std::vector<int> temp = ans[i];
		int templen = ans[i].size();
		for (int j = 0; j < templen; j++)
			std::cout << ans[i][j] << " ";
		std::cout << std::endl;
	}*/
	//3
	int min1 = 1000;
	int min2 = 1000;
	len = ans.size();
	for (int i = 0; i < len; i++){
		std::vector<int> temp = ans[i];
		if (ans[i].size() <= min1){
			min1 = ans[i].size();
			int length = 0;
			for (int j = 0; j < ans[i].size(); j++){
				length += SoChuoi(tblon[ans[i][j]], _key1, _key2).length();
			}
			if (length < min2)
			{
				min2 = length;
			}
		}
	}

	std::cout << "\nCong thuc da thuc toi tieu: ";
	for (int i = 0; i < len; i++){
		std::vector<int> temp = ans[i];
		if (ans[i].size() == min1){
			int length = 0;
			for (int j = 0; j < ans[i].size(); j++){
				length += SoChuoi(tblon[ans[i][j]],_key1,_key2).length();
			}
			if (length == min2)
			{
				std::cout << std::endl;
				for (int j = 0; j < pet.size(); j++)
					std::cout << SoChuoi(tblon[pet[j]], _key1, _key2) << " ";
				for (int j = 0; j < ans[i].size(); j++)
					std::cout << SoChuoi(tblon[ans[i][j]], _key1, _key2) << " ";
			}
		}
	}


}


void Bool::Output(){
	std::cout << "Te bao lon: " << std::endl;
	for (int i = 0; i < _tblon.size(); i++){
		std::string temp = SoChuoi(_tblon[i], _key1, _key2);
		std::cout <<temp  << " ";
	}

	//Tao mang arr
	int cot = _minterm.size();
	int dong = _tblon.size();
	int** arr=new int*[dong];
	for (int i = 0; i < dong; i++)
		arr[i] = new int[cot];

	DienMang(arr, dong, cot, _minterm, _tblon);
	std::vector<int> pet;
	//Tim cot nao co tong bang 1 va xoa sau do tra ve mang pet
	 Buoc1(arr,dong,cot,pet);
/*
	 for (int i = 0; i < pet.size(); i++)
	 for (int i = 0; i < dong; i++){
		 std::cout << std::endl;
		 for (int j = 0; j < cot; j++){
			 std::cout << arr[i][j] << " ";
		 }
	 }*/
	 Buoc2(arr,dong,cot,pet,_tblon,_key1,_key2);
}	