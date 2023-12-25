#pragma once
#include <iostream>
#include "WriteFile.h"
#include <vector>
#include "Patients.h"
#include "Doctors.h"
#include "Services.h"

using namespace std;

class Controllers
{
private:
	string Name;
	int NumberOfCard;
	//double TotalCost;
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
	int iter = 0;
	int searchNumberOfCard;
	WriteFile* writeFile;

public:


	Controllers()//�����������
	{
		CreateModel();
		writeFile = new WriteFile();
	}

	void Three()//����� ��� ������ ��������� ������
	{
		vector <Services> servis;

		int iter = 0;
		int salary = 0;
		string iterText;
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
			if (choice == '1')//����� ��������
			{
				cout << "#" << setw(25) << "���������" << setw(10) << "���������" << endl;
				for (Services cl : vServices)
				{

					if (cl.GetCategory() == "��������")
					{
						cout << cl.GetId()+1 << setw(15) << cl.GetNameOfserv() << setw(10) << cl.GetCost() << endl;
					}
				}
			}
			if (choice == '2')//����� ��������
			{
				cout << "#" << setw(25) << "���������" << setw(15) << "���������" << endl;

				for (Services cl : vServices)
				{
					if (cl.GetCategory() == "�������")
					{
						cout << cl.GetId()+1 << setw(25) << cl.GetNameOfserv() << setw(15) << cl.GetCost() << endl;
					}
				}

			}
			if (choice == '3')//����� �������
			{
				cout << "#" << setw(25) << "���������" << setw(15) << "���������" << endl;
				for (Services cl : vServices)
				{
					if (cl.GetCategory() == "�������")
					{
						cout << cl.GetId()+1 << setw(25) << cl.GetNameOfserv() << setw(15) << cl.GetCost() << endl;
					}
				}
			}
			if (choice != '4')//��������� ��� ����� ��������
			{

				cout << "����� ������� ������  ������� \"y\" " << endl;
				cout << "��������� � ���� ����� -\"n\"";
				cin >> iterText;
				if (iterText == "y")
				{
					cout << "\n ����� ������: " << endl;
					cin >> iterText;
					iter = stoi(iterText);
					for (Services serv : vServices)//��� ��������� ����� ��������
					{
						if (serv.GetId()+1 == iter)
						{
							servis.push_back(serv);
						}
					}

				}
			}
			system("cls");
			cout << "���������� ��������� ��������: " << servis.size() << endl;

		} while (choice != '4');//����� ������ ������
		/*for(Patients pat: vPatients){
		cout << setw(40) << "������� ��������:"<<pat.GetSurname()<< endl;}*/
		cout << setw(25) << "���������" << setw(15) << "���������" << endl;

		for (Services serv : servis)
		{
			serv.Print();
			salary += serv.GetCost();
		}

		cout << endl;
		cout << endl;
		cout << endl;
		cout << "����� ���������: " << salary << endl;

		salary = 0;
		Menu();
	}
	void Menu()//�������� ����
	{
		do
		{
			cout << "\n ����"
				<< "\n 1. ���������� � ��������"
				<< "\n 2. �������� ��������"
				<< "\n 3. �������������� ������"
				<< "\n 4. �����"
				<< "\n ��� ����� " << endl;
			cin >> choice;
			bool found = true;

			switch (choice)
			{
			case '1'://��� � ��������
				system("cls");
				cout << "C����� ������:"
					<< "\n 1. �� ���������"
					<< "\n 2. �� ������ �����" << endl;
				cin >> choice;
				
				if (choice == '1')// ����� �� ��������
				{
					int searchPassport;
					system("cls");
					cout << "������� ����� ���������: ";
					cin >> searchPassport;
					bool found = true;
					for (Patients pat : vPatients)
					{

						if (searchPassport == pat.GetPassport())
						{
							cout << "���:" << " " << pat.Getname() << endl;
							cout << "�������:" << " " << pat.GetSurname() << endl;
							cout << "�������:" << " " << pat.GetAge() << endl;
							cout << "����� ����� ��������: " << " " << pat.GetNumberOfCard() << endl;
							cout << "������� �������:" << " " << pat.GetDiagnosis() << endl;
							found = false;//���������
						}
					}

					if (found)
					{
						cout << "������� � ����� ������� ��������� �� ������" << endl;
					}
				}
				if (choice == '2')//����� �� ������ �����
				{
					int searchNumberOfCard;
					system("cls");
					cout << "������� ����� ����� ��� ������: ";
					cin >> searchNumberOfCard;
					bool found = true;

					for (Patients pat : vPatients)
					{
						if (searchNumberOfCard == pat.GetNumberOfCard())
						{
							cout << "�������:" << " " << pat.GetSurname() << endl;
							cout << "���:" << " " << pat.GetName() << endl;
							cout << "�������:" << " " << pat.GetAge() << endl;
							cout << "������� �������:" << " " << pat.GetDiagnosis() << endl;
							found = false;
						}

						if (found)//���� �������� �������� �� �������
						{
							cout << "������� � ����� ������� ����� �� ������";
						}
					}
				}
				break;

			case '2'://�������� ��������
					int searchNumberOfCard;
				do
				{
					system("cls");
					cout << "\n ������� ����� ����� ��������:" << " ";
					cin >> searchNumberOfCard;

					for (Patients pat : vPatients)
					{
						if (searchNumberOfCard == pat.GetNumberOfCard())//��������� ��������� ���� � �������
						{
							cout << "�������:" << " " << pat.GetSurname() << endl;
							cout << "���:" << " " << pat.GetName() << endl;
							cout << "�������:" << " " << pat.GetAge() << endl;
							cout << "������� �������:" << " " << pat.GetDiagnosis() << endl;
							found = false;

							ChoiceDoctor();
						}
					}
					if (found)//���� �������� �������� �� �������
					{
						cout << "������� � ����� ������� ����� �� ������" << endl;
						cout << "��� ������ ������� \"0\""<< endl;
					}
				} while (found && searchNumberOfCard != 0);//�� ��� ���, ���� �� ����� ����� 0 
				system("cls");
				Menu();
			case '3':

				Three();//����� ������ ��������� ������

				break;
			}
		}
		while (choice != '4');//����� �� ���������
		return;
	}


	void TimeVaribol(Doctors doc, Patients pat)//����� ������ ������� � ����
	{
		
		string iterText;
		system("cls");
		cout << "�������� ����:" << endl << "\n";

		for (int i = 0; i < vDate.size(); i++)
		{
			cout << i + 1 << "  " << vDate[i] << endl;//����� ����
		}

		cin >> iterText;
		int position = stoi(iterText);
		system("cls");
		cout << "��� ����� ����:" << vDate[position - 1] << endl;

		cout << "�������� �����:" << endl;
		for (int i = 0; i < vTime.size(); i++)
		{
			cout << i + 1 << " " << vTime[i] << endl;//����� �������
		}

		cin >> iterText;
		system("cls");
		cout << "��� ����� ����:" << vDate[position - 1] << endl;
		cout << "��� ����� �������:" << vTime[position - 1] << endl;

		cout << "��� ������������� ������ ������� \"�\"" << "  " << endl;;
		cout << "��� ������ � ���� ������� \"n\"" << "  " << endl;
		cin >> iterText;
		system("cls");
		bool found = true;
		if (iterText == "y")//��� ������������� ������
		{
			cout << "������ �������" << "\n"
				<< "�������:" << " " << pat.GetSurname() << " " << pat.GetName() << "\n"
				<< "�������:" << " " << pat.GetAge() << "\n"
				<< "������� �� : " << vDate[position - 1] << " � " << vTime[position - 1] << "\n" << endl;
			cout << "� �����������:" << doc.GetSpeciality() << "\n"
				<< "���:" << " " << doc.GetSurname() << " " << doc.GetName() << "\n"
				<< "����� ��������: #" << doc.GetCabinetNumber() << endl;
			Menu();
		}
		if (iterText == "n")//��� ������ �� ������
		{
			Menu();
		}
		
	}
	void ChoiceDoctor()//����� ������ ����� � ������ �������
	{
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
				for (Patients pat : vPatients)
				{
					if (doc.GetSpeciality() == "������")
					{
						TimeVaribol(doc, pat);//����� ������ �������
					}
				}
			}
			break;
		case'2':
			for (Doctors doc : vDoctors)
			{
				for (Patients pat : vPatients)
				{
					if (doc.GetSpeciality() == "��������")
					{
						TimeVaribol(doc, pat);
					}
				}
			}
			break;

		case'3':
			for (Doctors doc : vDoctors)
			{
				for (Patients pat : vPatients)
				{
					if (doc.GetSpeciality() == "�����������")
					{
						TimeVaribol(doc, pat);
					}
				}
			}
			break;

		case'4':
			for (Doctors doc : vDoctors)
			{
				for (Patients pat : vPatients)
				{
					if (doc.GetSpeciality() == "����������")
					{
						TimeVaribol(doc, pat);
					}
				}
			}
			break;

		case'5':
			for (Doctors doc : vDoctors)
			{
				for (Patients pat : vPatients)
				{
					if (doc.GetSpeciality() == "�������������")
					{
						TimeVaribol(doc, pat);
					}
				}
			}
			break;

		default:
			cout << "�������� ������ �������";
			Menu();
			break;
		}

	}
	void CreateModel()//����� �������� �����������
	{

		setlocale(LC_ALL, "Russian");
	
		// Services(Category,NameOfServ, Cost);

		vServices.push_back((*new Services("��������", "�/� ��������", 500)));
		vServices.push_back((*new Services("��������", "�/� ��������", 500)));
		vServices.push_back((*new Services("��������", "�/� ��������", 500)));
		vServices.push_back((*new Services("�������", "������ ����� �� �����", 100)));
		vServices.push_back((*new Services("�������", "������ ����� �����", 100)));
		vServices.push_back((*new Services("�������", "���������� ����", 800)));
		vServices.push_back((*new Services("�������", "��� ������", 1000)));



		//Patients(Name, surname, age, NumberOfCard, Diagnosis, passport);

		vPatients.push_back((*new Patients("����", "������", 23, 12, "��������", 1)));
		vPatients.push_back((*new Patients("����", "������", 45, 789012, "�����", 2222)));
		vPatients.push_back((*new Patients("����", "��������", 19, 345678, "������", 3333)));
		vPatients.push_back((*new Patients("�", "�", 35, 11, "������������", 4444)));
		vPatients.push_back((*new Patients("���������", "������", 27, 588522, "�������", 5555)));
		vPatients.push_back((*new Patients("����", "������", 87, 23425, "������ ���� � ������", 6666)));
		vPatients.push_back((*new Patients("���", "���������������", 40, 27438, "������� ������", 7777)));

		//Doctors(string name, string surname, int age, string speciality, int cabinetNumber)
		vDoctors.push_back(*new Doctors("����", "������", 56, "������", 1));
		vDoctors.push_back((*new Doctors("����", "������", 34, "��������", 2)));
		vDoctors.push_back((*new Doctors("����", "������", 45, "�����������", 3)));
		vDoctors.push_back((*new Doctors("����", "������", 49, "����������", 4)));
		vDoctors.push_back((*new Doctors("����", "������", 37, "�������������", 5)));

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
		
		writeFile->WritePatient(vPatients);
	}
};


