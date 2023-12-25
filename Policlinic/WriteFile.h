#pragma once
#include <iostream> 
#include "Patients.h"
#include "Doctors.h"
#include "Services.h"
#include <fstream>
#include <vector>


class WriteFile
{
public:
	WriteFile()
	{}
	void WriteResult(Doctors doc, Patients pat)
	{
		vector <Services> servis;

		int salary = 0;
		vector <string> text;
		ofstream tofile("result.txt");

		tofile << "Пациент:" << " " << pat.GetSurname() << " " << pat.GetName() << endl;
		tofile << "Возраст:" << " " << pat.GetAge() << endl;
		tofile << "Текущий диагноз:" << " " << pat.GetDiagnosis() << endl;
		tofile << "Специалист:" << doc.GetSpeciality() << endl;
		tofile << "ФИО:" << " " << doc.GetSurname() << " " << doc.GetName() << endl;
		tofile << "Номер кабинета: #" << " " << doc.GetCabinetNumber() << endl;
		for (int i = 0; i < text.size(); i++)
		{
			tofile << text[i] << endl;
		}

		tofile.close();

	}
	
	void WriteDoctor(vector <Doctors> docs)
	{
		ofstream tofile("doctors.txt");
		for (Doctors doc : docs)
		{
			tofile << "Специалист:" << " " << doc.GetSpeciality() << endl;
			tofile << "ФИО:" << " "  << doc.GetSurname() << " " << doc.GetName() << endl;
			tofile << "Возраст:" << " " << doc.GetAge() << endl;
			tofile << "Номер кабинета: #" << " " << doc.GetCabinetNumber() << endl;
			tofile << endl << endl;
		}
	}
	void WritePatient(vector <Patients> pats)
	{
		ofstream toFile("patients.txt");

		for (Patients pat : pats)
		{
			toFile << "Имя:" << " " << pat.GetName() << endl;
			toFile << "Фамилия:" << " " << pat.GetSurname() << endl;
			toFile << "Паспорт:" << " " << pat.GetPassport() << endl;
			toFile << "Возраст:" << " " << pat.GetAge() << endl;
			toFile << "Номер мед карты:" << " " << pat.GetNumberOfCard() << endl;
			toFile << "Диагноз:" << " " << pat.GetDiagnosis() << endl;
			toFile << endl << endl;
		}
	}

};

