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

	//double TotalCost(Services* services[])// посчитать сумму всех услуг
	//{
	//	double services = cost[]->GetTotalCost();
	//	for (int i = 0, i < 100, i++)
	//}

	Controllers()
	{
		CreateModel();
	}
	//файл ыектор доктора
	void writeFile(Doctors doctors[])
	{
		ofstream file("Doctors.txt");
	}

	//запись файлf вектор пациенты
	void writeFile(Patients patients[])
	{
		ofstream file("Patients.txt");
	}

	//файл вектор услуги
	void writeFile(Services services[])
	{
		ofstream file("Services.txt");
		if (!file)
		{
			cout << "Unable to open the file." << endl;
		}
		//else

		//{ // открытие файла для записи
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
			cout << " Выберите категорию"
				<< "\n 1. Инъекции"
				<< "\n 2. Анализы "
				<< "\n 3. Справки"
				<< "\n 4. Готово"
				<< endl;
			cin >> choice;
			system("cls");
			if (choice == '1')
			{
				cout << "#" << setw(25) << "Процедура" << setw(10) << "Стоимость" << endl;
				for (Services cl : vServices)
				{

					if (cl.GetCategory() == "Инъекции")
					{
						cout << cl.GetId() << setw(15) << cl.GetNameOfserv() << setw(10) << cl.GetCost() << endl;
					}

				}


				//cout << PrintThree() << endl;
			}
			if (choice == '2')
			{
				cout << "#" << setw(25) << "Процедура" << setw(15) << "Стоимость" << endl;

				for (Services cl : vServices)
				{
					if (cl.GetCategory() == "Анализы")
					{
						cout << cl.GetId() << setw(25) << cl.GetNameOfserv() << setw(15) << cl.GetCost() << endl;
					}
				}

			}
			if (choice == '3')
			{
				cout << "#" << setw(25) << "Процедура" << setw(15) << "Стоимость" << endl;
				for (Services cl : vServices)
				{
					if (cl.GetCategory() == "Справки")
					{
						cout << cl.GetId() << setw(25) << cl.GetNameOfserv() << setw(15) << cl.GetCost() << endl;
					}
				}
			}
			if (choice != '4')
			{


				cout << "выбрать услугу y/n: ";
				cin >> iterText;
				if (iterText == "y")
				{
					cout << "\n номер услуги: " << endl;
					cin >> iterText;
					iter = stoi(iterText);
					for (Services serv : vServices)
					{
						if (serv.GetId() == iter)
						{
							servis.push_back(serv);
						}
					}
					//посчитать количество выбраных проц

				}
			}
			system("cls");
			cout << "количество процедур " << servis.size() << endl;

		} while (choice != '4');

		//cout << setw(40) << "Корзина пациента:"<<  << endl << endl;
		cout << setw(25) << "Процедура" << setw(15) << "Стоимость" << endl;

		for (Services servis : servis)
		{
			servis.Print();
			salary += servis.GetCost();
		}

		cout << endl;
		cout << endl;
		cout << endl;
		cout << "Общая стоимость: " << salary << endl;
		//cout << "количество процедур " << servis.size() << endl;

		salary = 0;
	}
	void Menu()
	{
		/*SetConsoleCP(1251);
		SetConsoleOutputCP(1251);*/
		do
		{
			cout << "\n Меню"
				<< "\n 1. Информация о пациенте"
				<< "\n 2. Записать пациента"
				<< "\n 3. Дополнительные услуги"
				<< "\n 4. Выход"
				<< "\nYour choice " << endl;
			cin >> choice;

			switch (choice)
			{
			case '1':
				cout << "способ поиска"
					<< "\n 1. По списку"
					<< "\n 2. По номеру карты" << endl;
				cin >> choice;

				if (choice == '1')
				{
					/*string searchSurname;
					string searchName;
					cout << "Введите фамилию для поиска: ";
					cin >> searchSurname;
					cout << "Введите имя для поиска: ";
					cin >> searchName;
					for (Patients pat : vPatients)
					{
						if (searchSurname == pat.GetSurname())
						{
							if (searchName == pat.Getname())
							{
								cout << "имя" << pat.Getname() << endl;
							}
							cout << "Фамилия" << pat.GetSurname() << endl;


							cout << "Возраст:" << " " << pat.GetAge() << endl;
							cout << "Номер карты пациента " << " " << pat.GetNumberOfCard() << ":" << endl;
							cout << "Текущий диагноз" << " " << pat.GetDiagnosis() << endl;
						}
					}*/
					//вывести оставшуюся инфу о пац и вывод при ошибке ввода фамилии
				}
				if (choice == '2')
				{
					int searchNumberOfCard;
					system("cls");
					cout << "Введите номер карты для поиска: ";
					cin >> searchNumberOfCard;

					for (Patients pat : vPatients)
					{
						if (searchNumberOfCard == pat.GetNumberOfCard())
						{
							//cout << "Номер карты пациента " << " " << pat.GetNumberOfCard() << endl;
							cout << "Фамилия:" << " " << pat.GetSurname() << endl;
							cout << "Имя:" << " " << pat.GetName() << endl;
							cout << "Возраст:" << " " << pat.GetAge() << endl;
							//cout << "Номер карты пациента " << " " << pat.GetNumberOfCard() << ":" << endl;
							cout << "Текущий диагноз:" << " " << pat.GetDiagnosis() << endl;
							//вывести оставшуюся инфу о пац и вывод при ошибке ввода номера карты
						}
					}
				}
				break;

			case '2':
				cout << "введите номер карты пациента:" << " ";
				cin >> NumberOfCard;
				//cout << "Пациент:" << pat.GetSurname();
				cout << "Выберите специалиста:"
					<< "\n 1. Хирург"
					<< "\n 2. Терапевт"
					<< "\n 3. Офтальмолог"
					<< "\n 4. Стоматолог"
					<< "\n 5. Отоларинголог" << endl;
				cin >> choice;
				switch (choice)
				{
				case'1':
					for (Doctors doc : vDoctors)
					{
						if (doc.GetSpeciality() == "Хирург")
						{
							TimeVaribol(doc);
						}
					}
					break;
				case'2':
					for (Doctors doc : vDoctors)
					{
						if (doc.GetSpeciality() == "Терапевт")
						{
							TimeVaribol(doc);
						}
					}
					break;
				case'3':
					for (Doctors doc : vDoctors)
					{
						if (doc.GetSpeciality() == "Офтальмолог")
						{
							TimeVaribol(doc);
						}
					}
					break;
				case'4':
					for (Doctors doc : vDoctors)
					{
						if (doc.GetSpeciality() == "Стоматолог")
						{
							TimeVaribol(doc);
						}
					}
					break;
				case'5':
					for (Doctors doc : vDoctors)
					{
						if (doc.GetSpeciality() == "Отоларинголог")
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
			cout << "Выб дату:" << endl << "\n";

			for (int i = 0; i < vDate.size(); i++)
			{
				cout << i + 1 << "  " << vDate[i] << endl;
			}

			cin >> iterText;
			int position = stoi(iterText);
			system("cls");
			cout << "Ваш выбор даты:" << vDate[position - 1] << endl;


			cout << "выб время:" << endl;
			for (int i = 0; i < vTime.size(); i++)
			{
				cout << i + 1 << " " << vTime[i] << endl;
			}

			cin >> iterText;
			system("cls");
			cout << "Ваш выбор даты:" << vDate[position - 1] << endl;
			cout << "Ваш выбор Времени:" << vTime[position - 1] << endl;


			cout << "Для подтверждения записи нажмите у" << "  ";
			cin >> iterText;
			system("cls");
			if (iterText == "y")
			{
				for (Patients pat : vPatients)//цикл все портит, выводит всех пац
				{
					cout << "Запись создана" << "\n"
						<< "Пациент:" << " " << pat.GetSurname() << " " << pat.GetName() << "\n"
						<< "Возраст" << pat.GetAge() << "\n"
						<< "Pаписан на : " << vDate[position - 1] << " в " << vTime[position - 1] << "\n"
						<< "К специалисту:" << doc.GetSpeciality() << "\n"
						<< "ФИО:" << " " << doc.GetSurname() << " " << doc.GetName() << "\n"
						<< "Номер кабинета: #" << doc.GetCabinetNumber() << endl;
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

		vServices.push_back((*new Services("Инъекции", "в/м инъекции", 500)));
		vServices.push_back((*new Services("Инъекции", "в/в инъекции", 500)));
		vServices.push_back((*new Services("Инъекции", "п/к инъекции", 500)));
		vServices.push_back((*new Services("Анализы", "Анализ крови на сахар", 100)));
		vServices.push_back((*new Services("Анализы", "Анализ крови общий", 100)));
		vServices.push_back((*new Services("Справки", "Больничный лист", 800)));
		vServices.push_back((*new Services("Справки", "Мед книжка", 1000)));


		//vector <Patients> vPatients; //пуст вектора

		//Patients* patients = new Patients(Name, surname, age, NumberOfCard, Diagnosis);

		vPatients.push_back((*new Patients("Иван", "Петров", 23, 12, "Простуда")));
		vPatients.push_back((*new Patients("Петр", "Петров", 45, 789012, "Грипп")));
		vPatients.push_back((*new Patients("Анна", "Сидорова", 19, 345678, "Ангина")));
		vPatients.push_back((*new Patients("А", "А", 35, 11, "Плоскостопие")));
		vPatients.push_back((*new Patients("Екатерина", "Фомина", 27, 588522, "Сколиоз")));
		vPatients.push_back((*new Patients("Олег", "Жмурин", 87, 23425, "Острая боль в животе")));
		vPatients.push_back((*new Patients("Зоя", "Космодемьянская", 40, 27438, "Средний кариес")));

		//Doctors(string name, string surname, int age, string speciality, int cabinetNumber)
		vDoctors.push_back(*new Doctors("Иван", "Иванов", 56, "Хирург", 1));
		vDoctors.push_back((*new Doctors("Иван", "Иванов", 34, "Терапевт", 2)));
		vDoctors.push_back((*new Doctors("Иван", "Иванов", 45, "Офтальмолог", 3)));
		vDoctors.push_back((*new Doctors("Иван", "Иванов", 49, "Стоматолог", 4)));
		vDoctors.push_back((*new Doctors("Иван", "Иванов", 37, "Отоларинголог", 5)));

		//vector <>//время и дата(потом добавить ее к врачам) 
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


