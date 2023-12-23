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
//#include <vector>
//#include "Patients.h"
//#include "Doctors.h"
//#define NOMINMAX
//#include <Windows.h>
using namespace std;

class Controllers
{
public:
	string Name;
	int NumberOfCard;
	double TotalCost;
	double Cost;
	string NameOfServ;
	string Diagnosis;
	string Speciality;
	string surname;
	int age;
	char choice;
	vector <Services> vServices;
	vector<string> vDate;
	vector<string> vTime;
	vector <Doctors> vDoctors;
	vector <Patients> vPatients;
	int numerator = 1;

	//double TotalCost(Services* services[])// ��������� ����� ���� �����
	//{
	//	double services = cost[]->GetTotalCost();
	//	for (int i = 0, i < 100, i++)
	//}

	Controllers()
	{
		CreateModel();
	}
	//���� ������ �������
	void writeFile(Doctors doctors[])
	{
		ofstream file("Doctors.txt");
	}

	//������ ����f ������ ��������
	void writeFile(Patients patients[])
	{
		ofstream file("Patients.txt");
	}

	//���� ������ ������
	void writeFile(Services services[])
	{
		ofstream file("Services.txt");
		if (!file)
		{
			cout << "Unable to open the file." << endl;
		}
		//else

		//{ // �������� ����� ��� ������
		//	for (int i = 0; i < vServices.size(); i++)
		//	{
		//		/*vServices.at(i) = i;
		//		cout << vServices.at(i);*/
		//		/*file << left << setw(20);
		//		file << services[i];*/
		//	}
		//}
	}

	void writeFile(string date[])
	{
		ofstream file("Date.txt");
		if (!file)
		{
			cout << "Unable to open the file." << endl;
		}
	}


	double calculateTotalCost(const vector <Services> vServices)
	{
		double totalCost = 0.0;
		for (Services ser : vServices)
		{
			totalCost += ser.GetCost();

		}
		return TotalCost;
	}
	void Three()
	{
		vector <Services> servis;
		int iter = 0;
		int salary = 0;
		string iterText;
		//int ID;
		int amount = 0;
		do
		{
			cout << " �������� ���������"
				<< "\n 1. ��������"
				<< "\n 2. ������� "
				<< "\n 3. �������"
				<< "\n 4. ������"
				<< endl;
			cin >> choice;
			system("cls");
			if (choice == '1')
			{
				cout << "#" << setw(25) << "���������" << setw(10) << "���������" << endl;
				for (Services cl : vServices)
				{

					if (cl.GetCategory() == "��������")
					{
						cout << cl.GetId() << setw(15) << cl.GetNameOfserv() << setw(10) << cl.GetCost() << endl;
					}

				}


				//cout << PrintThree() << endl;
			}
			if (choice == '2')
			{
				cout << "#" << setw(25) << "���������" << setw(15) << "���������" << endl;

				for (Services cl : vServices)
				{
					if (cl.GetCategory() == "�������")
					{
						cout << cl.GetId() << setw(25) << cl.GetNameOfserv() << setw(15) << cl.GetCost() << endl;
					}
				}

			}
			if (choice == '3')
			{
				cout << "#" << setw(25) << "���������" << setw(15) << "���������" << endl;
				for (Services cl : vServices)
				{
					if (cl.GetCategory() == "�������")
					{
						cout << cl.GetId() << setw(25) << cl.GetNameOfserv() << setw(15) << cl.GetCost() << endl;
					}
				}
			}
			if (choice != '4')
			{


				cout << "������� ������ y/n: ";
				cin >> iterText;
				if (iterText == "y")
				{
					cout << "\n ����� ������: " << endl;
					cin >> iterText;
					iter = stoi(iterText);
					for (Services serv : vServices)
					{
						if (serv.GetId() == iter)
						{
							servis.push_back(serv);
						}
					}
					//��������� ���������� �������� ����

				}
			}
			system("cls");
			cout << "���������� �������� " << servis.size() << endl;

		} while (choice != '4');

		//cout << setw(40) << "������� ��������:"<<  << endl << endl;
		cout << setw(25) << "���������" << setw(15) << "���������" << endl;

		for (Services servis : servis)
		{
			servis.Print();
			salary += servis.GetCost();
		}

		cout << endl;
		cout << endl;
		cout << endl;
		cout << "����� ���������: " << salary << endl;
		//cout << "���������� �������� " << servis.size() << endl;

		salary = 0;
	}
	void Menu()
	{
		/*SetConsoleCP(1251);
		SetConsoleOutputCP(1251);*/
		do
		{
			cout << "\n ����"
				<< "\n 1. ���������� � ��������"
				<< "\n 2. �������� ��������"
				<< "\n 3. �������������� ������"
				<< "\n 4. �����"
				<< "\nYour choice " << endl;
			cin >> choice;

			switch (choice)
			{
			case '1':
				cout << "������ ������"
					<< "\n 1. �� ������"
					<< "\n 2. �� ������ �����" << endl;
				cin >> choice;

				if (choice == '1')
				{
					/*string searchSurname;
					string searchName;
					cout << "������� ������� ��� ������: ";
					cin >> searchSurname;
					cout << "������� ��� ��� ������: ";
					cin >> searchName;
					for (Patients pat : vPatients)
					{
						if (searchSurname == pat.GetSurname())
						{
							if (searchName == pat.Getname())
							{
								cout << "���" << pat.Getname() << endl;
							}
							cout << "�������" << pat.GetSurname() << endl;


							cout << "�������:" << " " << pat.GetAge() << endl;
							cout << "����� ����� �������� " << " " << pat.GetNumberOfCard() << ":" << endl;
							cout << "������� �������" << " " << pat.GetDiagnosis() << endl;
						}
					}*/
					//������� ���������� ���� � ��� � ����� ��� ������ ����� �������
				}
				if (choice == '2')
				{
					int searchNumberOfCard;
					system("cls");
					cout << "������� ����� ����� ��� ������: ";
					cin >> searchNumberOfCard;

					for (Patients pat : vPatients)
					{
						if (searchNumberOfCard == pat.GetNumberOfCard())
						{
							//cout << "����� ����� �������� " << " " << pat.GetNumberOfCard() << endl;
							cout << "�������:" << " " << pat.GetSurname() << endl;
							cout << "���:" << " " << pat.GetName() << endl;
							cout << "�������:" << " " << pat.GetAge() << endl;
							//cout << "����� ����� �������� " << " " << pat.GetNumberOfCard() << ":" << endl;
							cout << "������� �������:" << " " << pat.GetDiagnosis() << endl;
							//������� ���������� ���� � ��� � ����� ��� ������ ����� ������ �����
						}
					}
				}
				break;

			case '2':
				cout << "������� ����� ����� ��������:" << " ";
				cin >> NumberOfCard;
				//cout << "�������:" << pat.GetSurname();
				cout << "�������� �����������:"
					<< "\n 1. ������"
					<< "\n 2. ��������"
					<< "\n 3. �����������"
					<< "\n 4. ����������"
					<< "\n 5. �������������" << endl;
				cin >> choice;
				switch (choice)
				{
				case'1':
					for (Doctors doc : vDoctors)
					{
						if (doc.GetSpeciality() == "������")
						{
							TimeVaribol(doc);
						}
					}
					break;
				case'2':
					for (Doctors doc : vDoctors)
					{
						if (doc.GetSpeciality() == "��������")
						{
							TimeVaribol(doc);
						}
					}
					break;
				case'3':
					for (Doctors doc : vDoctors)
					{
						if (doc.GetSpeciality() == "�����������")
						{
							TimeVaribol(doc);
						}
					}
					break;
				case'4':
					for (Doctors doc : vDoctors)
					{
						if (doc.GetSpeciality() == "����������")
						{
							TimeVaribol(doc);
						}
					}
					break;
				case'5':
					for (Doctors doc : vDoctors)
					{
						if (doc.GetSpeciality() == "�������������")
						{
							TimeVaribol(doc);
						}
					}
					break;
				default:
					break;
				}

				break;


			case '3':

				Three();

				break;
			}
		} while (choice != '4');
	}
	void TimeVaribol(Doctors doc)
	{
		if (choice != '5')
		{
			string iterText;
			cout << "��� ����:" << endl << "\n";

			for (int i = 0; i < vDate.size(); i++)
			{
				cout << i + 1 << "  " << vDate[i] << endl;
			}

			cin >> iterText;
			int position = stoi(iterText);
			system("cls");
			cout << "��� ����� ����:" << vDate[position - 1] << endl;


			cout << "��� �����:" << endl;
			for (int i = 0; i < vTime.size(); i++)
			{
				cout << i + 1 << " " << vTime[i] << endl;
			}

			cin >> iterText;
			system("cls");
			cout << "��� ����� ����:" << vDate[position - 1] << endl;
			cout << "��� ����� �������:" << vTime[position - 1] << endl;


			cout << "��� ������������� ������ ������� �" << "  ";
			cin >> iterText;
			system("cls");
			if (iterText == "y")
			{
				for (Patients pat : vPatients)//���� ��� ������, ������� ���� ���
				{
					cout << "������ �������" << "\n"
						<< "�������:" << " " << pat.GetSurname() << " " << pat.GetName() << "\n"
						<< "�������" << pat.GetAge() << "\n"
						<< "P������ �� : " << vDate[position - 1] << " � " << vTime[position - 1] << "\n"
						<< "� �����������:" << doc.GetSpeciality() << "\n"
						<< "���:" << " " << doc.GetSurname() << " " << doc.GetName() << "\n"
						<< "����� ��������: #" << doc.GetCabinetNumber() << endl;
				}
			}
		}
	}
	void CreateModel()
	{

		setlocale(LC_ALL, "Russian");
		//string Category;
		char choice;



		//Services* servises = new Services(Category,NameOfServ, Cost);

		vServices.push_back((*new Services("��������", "�/� ��������", 500)));
		vServices.push_back((*new Services("��������", "�/� ��������", 500)));
		vServices.push_back((*new Services("��������", "�/� ��������", 500)));
		vServices.push_back((*new Services("�������", "������ ����� �� �����", 100)));
		vServices.push_back((*new Services("�������", "������ ����� �����", 100)));
		vServices.push_back((*new Services("�������", "���������� ����", 800)));
		vServices.push_back((*new Services("�������", "��� ������", 1000)));


		//vector <Patients> vPatients; //���� �������

		//Patients* patients = new Patients(Name, surname, age, NumberOfCard, Diagnosis);

		vPatients.push_back((*new Patients("����", "������", 23, 12, "��������")));
		vPatients.push_back((*new Patients("����", "������", 45, 789012, "�����")));
		vPatients.push_back((*new Patients("����", "��������", 19, 345678, "������")));
		vPatients.push_back((*new Patients("�", "�", 35, 11, "������������")));
		vPatients.push_back((*new Patients("���������", "������", 27, 588522, "�������")));
		vPatients.push_back((*new Patients("����", "������", 87, 23425, "������ ���� � ������")));
		vPatients.push_back((*new Patients("���", "���������������", 40, 27438, "������� ������")));

		//Doctors(string name, string surname, int age, string speciality, int cabinetNumber)
		vDoctors.push_back(*new Doctors("����", "������", 56, "������", 1));
		vDoctors.push_back((*new Doctors("����", "������", 34, "��������", 2)));
		vDoctors.push_back((*new Doctors("����", "������", 45, "�����������", 3)));
		vDoctors.push_back((*new Doctors("����", "������", 49, "����������", 4)));
		vDoctors.push_back((*new Doctors("����", "������", 37, "�������������", 5)));

		//vector <>//����� � ����(����� �������� �� � ������) 
		//vector<string> vDate;
		vDate.push_back(*new string("12.10.2023"));
		vDate.push_back(*new string("13.10.2023"));
		vDate.push_back(*new string("14.10.2023"));
		vDate.push_back(*new string("15.10.2023"));
		vDate.push_back(*new string("16.10.2023"));

		//vector<string> vTime;
		vTime.push_back(*new string("10:00"));
		vTime.push_back(*new string("11:00"));
		vTime.push_back(*new string("12:30"));
		vTime.push_back(*new string("14:00"));
		vTime.push_back(*new string("15:30"));

	}
};


