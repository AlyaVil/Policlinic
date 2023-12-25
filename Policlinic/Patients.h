//#include <random> 
//#include <string> 
//#include <iomanip> 
//#include <cstdlib>
//#include <ctime>
#include <iostream> 
#include "People.h"
using namespace std;
#pragma once
class Patients: public People
{
protected:
	int Passport;
	int NumberOfCard;
	string Diagnosis;
public:
	Patients(string name, string surname, int age, int numberOfCard, string diagnosis, int passport)
		:People(name, age, surname)
	{
		this->name = name;
		this->surname = surname;
		this->age = age;
		this->NumberOfCard = numberOfCard;
		this->Diagnosis = diagnosis;
		Passport = passport;
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
	int GetNumberOfCard()
	{
		return NumberOfCard;
	}
	string GetDiagnosis()
	{
		return Diagnosis;
	}
	int GetPassport()
	{
		return Passport;
	}
};


