
#include <iostream> 
using namespace std;
#pragma once
class People
{
protected:
	string name;
	string surname;
	int age;
public:
	People(string name, int age, string surname)
	{
		this->name = name;
		this->age = age;
		this->surname = surname;
	}
	string Getname()
	{
		return name;
	}
	string GetSurname()
	{
		return surname;
	}
	int GetAge()
	{
		return age;
	}
};

