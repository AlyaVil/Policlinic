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

		tofile << "�������:" << " " << pat.GetSurname() << " " << pat.GetName() << endl;
		tofile << "�������:" << " " << pat.GetAge() << endl;
		tofile << "������� �������:" << " " << pat.GetDiagnosis() << endl;
		tofile << "����������:" << doc.GetSpeciality() << endl;
		tofile << "���:" << " " << doc.GetSurname() << " " << doc.GetName() << endl;
		tofile << "����� ��������: #" << " " << doc.GetCabinetNumber() << endl;
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
			tofile << "����������:" << " " << doc.GetSpeciality() << endl;
			tofile << "���:" << " "  << doc.GetSurname() << " " << doc.GetName() << endl;
			tofile << "�������:" << " " << doc.GetAge() << endl;
			tofile << "����� ��������: #" << " " << doc.GetCabinetNumber() << endl;
			tofile << endl << endl;
		}
	}
	void WritePatient(vector <Patients> pats)
	{
		ofstream toFile("patients.txt");

		for (Patients pat : pats)
		{
			toFile << "���:" << " " << pat.GetName() << endl;
			toFile << "�������:" << " " << pat.GetSurname() << endl;
			toFile << "�������:" << " " << pat.GetPassport() << endl;
			toFile << "�������:" << " " << pat.GetAge() << endl;
			toFile << "����� ��� �����:" << " " << pat.GetNumberOfCard() << endl;
			toFile << "�������:" << " " << pat.GetDiagnosis() << endl;
			toFile << endl << endl;
		}
	}

};

