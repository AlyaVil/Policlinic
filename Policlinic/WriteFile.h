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

		tofile << "�������:" << " " << pat.GetSurname() << " " << pat.GetName() << endl;
		tofile << "�������:" << " " << pat.GetAge() << endl;
		tofile << "������� �������:" << " " << pat.GetDiagnosis() << endl;
		//tofile << "������� �� : " << vDate[position - 1] << " � " << vTime[position - 1] << "\n" << endl;
		tofile << "����������:" << doc.GetSpeciality() << endl;
		tofile << "���:" << " " << doc.GetSurname() << " " << doc.GetName() << endl;
		tofile << "����� ��������: #" << doc.GetCabinetNumber() << endl;
		for (int i = 0; i < text.size(); i++)
		{
			tofile << text[i] << endl;
		}
		tofile << setw(25) << "���������" << setw(15) << "���������" << endl;

		/*for (Services serv : servis)
		{
			serv.Print();
			salary += serv.GetCost();
		}*/
		tofile << "����� ���������: " << salary << endl;
		tofile.close();

	}
	//void WriteDoctor(vector <Doctors> vDoctors)
	//{
	//	vector <string> text;
	//	ofstream tofile("doctors.txt");

	//	for (Doctors doc : vDoctors)
	//	{
	//		tofile << "����������:" << doc.GetSpeciality() << endl;
	//		tofile << "���:" << " " << doc.GetSurname() << " " << doc.GetName() << endl;
	//		tofile << "����� ��������: #" << doc.GetCabinetNumber() << endl;
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
			toFile << "���" << pat.GetName() << endl;
			toFile << "�������" << pat.GetSurname() << endl;
			toFile << "�������" << pat.GetPassport() << endl;
			toFile << "�������" << pat.GetAge() << endl;
			toFile << "����� ��� �" << pat.GetNumberOfCard() << endl;
			toFile << "�����" << pat.GetDiagnosis() << endl;
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