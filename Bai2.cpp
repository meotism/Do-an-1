#include <iostream>
#include "Vector.h"
//#include<Windows.h>

void main() {
	int menu = 0;
	do{
		system("cls");
		float k;
		Vector v1, v2;
		std::cout << "Nhap vector thu nhat\n";
		v1.Nhap();
		std::cout << "v1 = ";
		v1.Xuat();
	
		int thaotac=0;
		std::cout << "\nNhap thao tac muon dung: " << std::endl;
		std::cout << "1.Cong hai vector. " << std::endl;
		std::cout << "2.Nhan vector voi so thuc k." << std::endl;
		std::cin >> thaotac;
		if (thaotac == 1){
			std::cout << "\nNhap vector thu 2: " << std::endl;
			v2.Nhap();
			std::cout << "v2 = ";
			v2.Xuat();
			if (v1.getn() == v2.getn()){
				Vector tong = v1 + v2;
				std::cout << "\nTong vector v1 + v2 sau khi cong la: ";
				tong.Xuat();
			}
			else{
				std::cout << "\n Hai Vector da nhap khong cung chieu....";
			}
		}
		else{
			float k;
			std::cout << "\nNHap so thuc K: ";
			std::cin >> k;
			Vector ans = v1*k;
			std::cout << "\nTich vector v1 voi so thuc k la: " << std::endl;
			ans.Xuat();
		}
		std::cout << "\nNhap 0 de thuc hien lai. Nhap -1 de thoat."<<std::endl;
		std::cin >> menu;
	} while (menu == 0);
}