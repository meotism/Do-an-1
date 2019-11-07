#include"Bool.h"
#include<iostream>

int main(){
	Bool b;
	int n;
	std::cout << "Chon cach nhap: ";
	std::cout << "\n1: nhap theo ham(abcdABCD..) ";
	std::cout << "\n2: nhap theo so nguyen(0,1,2,..,16) \n";

	std::cin >> n;
	if (n == 1){
		std::cout << "\n1: nhap theo ham(abcdABCD..): ";
		b.Input();
		b.Token();
		b.TeBaoLon();
		b.Output();
	}
	else{
		std::cout << "\n2: nhap theo so nguyen(0,1,2,..,16): ";

		b.Input2();
		b.MinTerm();
		b.TeBaoLon();
		b.Output();
	}

	system("pause");
	return 1;
}