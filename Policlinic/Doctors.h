#include <random> 
#include <string> 
#include <iomanip> 
#include <iostream> 
#include "People.h"
using namespace std;
#pragma once

class Doctors: public People
{
protected:
	string Speciality;
	int CabinetNumber;
public:
	Doctors(string name, string surname, int age, string speciality,  int cabinetNumber)
		:People( name,  age,  surname)
	{
		this->name = name;
		this->surname = surname;
		this->age = age;
		this->Speciality = speciality;
		this->CabinetNumber = cabinetNumber;
	}
	string GetName()
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
	string GetSpeciality()
	{
		return Speciality;
	}
	int GetCabinetNumber()
	{
		return CabinetNumber;
	}
};


