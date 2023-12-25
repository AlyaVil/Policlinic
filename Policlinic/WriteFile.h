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
		//vector<string> vDate;
		vector <string> text;
		ofstream tofile("result.txt");

		tofile << "Пациент:" << " " << pat.GetSurname() << " " << pat.GetName() << endl;
		tofile << "Возраст:" << " " << pat.GetAge() << endl;
		tofile << "Текущий диагноз:" << " " << pat.GetDiagnosis() << endl;
		//tofile << "Записан на : " << vDate[position - 1] << " в " << vTime[position - 1] << "\n" << endl;
		tofile << "Специалист:" << doc.GetSpeciality() << endl;
		tofile << "ФИО:" << " " << doc.GetSurname() << " " << doc.GetName() << endl;
		tofile << "Номер кабинета: #" << doc.GetCabinetNumber() << endl;
		for (int i = 0; i < text.size(); i++)
		{
			tofile << text[i] << endl;
		}
		tofile << setw(25) << "Процедура" << setw(15) << "Стоимость" << endl;

		/*for (Services serv : servis)
		{
			serv.Print();
			salary += serv.GetCost();
		}*/
		tofile << "Общая стоимость: " << salary << endl;
		tofile.close();

	}
	//void WriteDoctor(vector <Doctors> vDoctors)
	//{
	//	vector <string> text;
	//	ofstream tofile("doctors.txt");

	//	for (Doctors doc : vDoctors)
	//	{
	//		tofile << "Специалист:" << doc.GetSpeciality() << endl;
	//		tofile << "ФИО:" << " " << doc.GetSurname() << " " << doc.GetName() << endl;
	//		tofile << "Номер кабинета: #" << doc.GetCabinetNumber() << endl;
	//	}
	//}
	void WriteDoctor()
	{
		/*ofstream file("doctors.txt");
		for (Doctors doc : vDoctors)
		{

		}*/
	}
	void WritePatient(vector <Patients> pats)
	{

		ofstream toFile("patients.txt");

		for (Patients pat : pats)
		{
			toFile << "Имя" << pat.GetName() << endl;
			toFile << "Фамилия" << pat.GetSurname() << endl;
			toFile << "Паспорт" << pat.GetPassport() << endl;
			toFile << "Возраст" << pat.GetAge() << endl;
			toFile << "номер мед к" << pat.GetNumberOfCard() << endl;
			toFile << "диагн" << pat.GetDiagnosis() << endl;
			toFile << endl << endl;
		}
		/*fstream file;
		file.open("patient.txt", ios_base::out);
		for (int i = 0; i < vPatients.size(); i++)
		{
			file << vPatients[i] << endl;
		}
		file.close();
		return;*/
	}

};

//fstream file;
//file.open("vector_file.txt", ios_base::out);
//
//for (int i = 0; i < v.size(); i++)
//{
//	file << v[i] << endl;
//}
//
//file.close();
//
//return 0;
//}