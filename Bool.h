#pragma once
#include<vector>
#include<string>

class Bool
{
private:
	std::string _str;
	std::vector<std::string> _minterm;
	std::vector<std::string> _tblon;
	std::string _key1;
	std::string _key2;
	std::vector <std::vector<int>> _ans;
	int _n; 
	std::vector<int> _dayso;
public:
	Bool();
	~Bool();

	void Input();
	void Token();
	void TeBaoLon();
	void Output();
	void Input2();
	void MinTerm();
};

struct TeBao{
	std::string str;
	int heso=0;
};