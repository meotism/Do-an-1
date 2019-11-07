#include"Matrix.h"
#include<iostream>

int main()
{
	Matrix m;
	int menu = 0;
	do{
    	system("cls");
		int thaotac;

		std::cout << "1. Thao tac voi ma tran. " << std::endl;
		std::cout << "2. Giai he phuong trinh tuyen tinh. " << std::endl;
		std::cin >> thaotac;

		if (thaotac == 1){
			system("cls");
			std::cout << "\nNhap ma tran : ";
			m.Input();
			do{
				system("cls");
				std::cout << "\nMatran da nhap la: ";
				m.Output();
				std::cout << "1. Tim dinh thuc cua ma tran" << std::endl;
				std::cout << "2. Ma tran nghich dao " << std::endl;
				std::cout << "3. Tich hai ma tran " << std::endl;
				std::cout << "4. Tim hang cua ma tran" << std::endl;
				std::cin >> thaotac;
				if (thaotac == 1){
					if (m.getn() != m.getn())
						std::cout << "\nDay la khong phai la ma tran vuong nen khong ton tai dinh thuc.\n";
					else
						std::cout << "\nDinh thuc cua ma tran la: " << m.Det();
				}
				else if (thaotac == 2){
					Matrix temp;
					if (m.getn() != m.getn())
						std::cout << "\nDay la khong phai la ma tran vuong nen khong ton tai ma tran nghich dao.\n";
					else{
						temp = m.NghichDao();
						std::cout << "\nMa tran nghich dao cua ma tran da nhap la:\n";
						temp.Output();
					}
				}
				else if (thaotac == 3){
					Matrix n, ans;
					std::cout << "\nNhap ma tran thu hai: \n";
					n.Input();
					if (m.getm() == n.getn()){
						ans = m*n;
						std::cout << "\nTich hai ma tran la: \n";
						ans.Output();
					}
					else{
						std::cout << "\nHai ma tran khong nhan voi nhau duoc.";
					}
				}
				else if (thaotac == 4){
					float rank = m.Rank();
					std::cout << "\nHang cua ma tran la:  " << rank;
				}
				std::cout << "\nNhap 0 de tiep tuc cac thao tac voi ma tran nay, -1 de quay lai.\n";
				std::cin >> thaotac;
			} while (thaotac == 0);
		}
		else if (thaotac == 2){
			m.Solve();
		}
		std::cout << "\nNhap 0 de thuc hien lai chuong trinh, -1 de thoat: \n";
		std::cin >> menu;

	} while (menu == 0);
	return 0;
}