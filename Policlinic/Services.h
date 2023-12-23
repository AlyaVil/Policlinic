#pragma once
//#include <random> 
//#include <string> 
//#include <iomanip> 
//#include <cstdlib>
#include <iostream>
//#include <ctime>
//#include <cctype>
//#include <cstring>
//#include <fstream>
//#include <ios>
#include "Patients.h"
#include "Doctors.h"
using namespace std;

class Services
{
protected:
	int id;
	string NameOfServ;
	int cost;
	string Category;
	static inline int staticId;
	int NextId()
	{
		return staticId++;
	}
public:
	Services(string Category, string nameOfServ, int cost)
	{
		id = NextId();
		this->NameOfServ = nameOfServ;
		this->cost = cost;
		this->Category = Category;
	}
	int GetId()
	{
		return id;
	}
	string GetNameOfserv()
	{
		return NameOfServ;
	}
	int GetCost()
	{
		return cost;
	}
	string GetCategory()
	{
		return Category;
	}
	void Print()
	{
		cout << setw(25) << NameOfServ << setw(15) << cost << endl;
	}
};





