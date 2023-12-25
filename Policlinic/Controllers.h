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


	Controllers()//конструктор
	{
		CreateModel();
		writeFile = new WriteFile();
	}

	void Three()//метод для выбора категории записи
	{
		vector <Services> servis;

		int iter = 0;
		int salary = 0;
		string iterText;
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
			if (choice == '1')//вывод инъекций
			{
				cout << "#" << setw(25) << "Процедура" << setw(10) << "Стоимость" << endl;
				for (Services cl : vServices)
				{

					if (cl.GetCategory() == "Инъекции")
					{
						cout << cl.GetId()+1 << setw(15) << cl.GetNameOfserv() << setw(10) << cl.GetCost() << endl;
					}
				}
			}
			if (choice == '2')//вывод анализов
			{
				cout << "#" << setw(25) << "Процедура" << setw(15) << "Стоимость" << endl;

				for (Services cl : vServices)
				{
					if (cl.GetCategory() == "Анализы")
					{
						cout << cl.GetId()+1 << setw(25) << cl.GetNameOfserv() << setw(15) << cl.GetCost() << endl;
					}
				}

			}
			if (choice == '3')//вывод справок
			{
				cout << "#" << setw(25) << "Процедура" << setw(15) << "Стоимость" << endl;
				for (Services cl : vServices)
				{
					if (cl.GetCategory() == "Справки")
					{
						cout << cl.GetId()+1 << setw(25) << cl.GetNameOfserv() << setw(15) << cl.GetCost() << endl;
					}
				}
			}
			if (choice != '4')//выводится при любом значении
			{

				cout << "Чтобы выбрать услугу  нажмите \"y\" " << endl;
				cout << "Вернуться в меню услуг -\"n\"";
				cin >> iterText;
				if (iterText == "y")
				{
					cout << "\n Номер услуги: " << endl;
					cin >> iterText;
					iter = stoi(iterText);
					for (Services serv : vServices)//для выбранных услуг отдельно
					{
						if (serv.GetId()+1 == iter)
						{
							servis.push_back(serv);
						}
					}

				}
			}
			system("cls");
			cout << "Количество выбранных процедур: " << servis.size() << endl;

		} while (choice != '4');//когда нажато готово
		/*for(Patients pat: vPatients){
		cout << setw(40) << "Корзина пациента:"<<pat.GetSurname()<< endl;}*/
		cout << setw(25) << "Процедура" << setw(15) << "Стоимость" << endl;

		for (Services serv : servis)
		{
			serv.Print();
			salary += serv.GetCost();
		}

		cout << endl;
		cout << endl;
		cout << endl;
		cout << "Общая стоимость: " << salary << endl;

		salary = 0;
		Menu();
	}
	void Menu()//основное меню
	{
		do
		{
			cout << "\n Меню"
				<< "\n 1. Информация о пациенте"
				<< "\n 2. Записать пациента"
				<< "\n 3. Дополнительные услуги"
				<< "\n 4. Выход"
				<< "\n Ваш выбор " << endl;
			cin >> choice;
			bool found = true;

			switch (choice)
			{
			case '1'://инф о пациенте
				system("cls");
				cout << "Cпособ поиска:"
					<< "\n 1. По пасспорту"
					<< "\n 2. По номеру карты" << endl;
				cin >> choice;
				
				if (choice == '1')// поиск по паспорту
				{
					int searchPassport;
					system("cls");
					cout << "Введите номер пасспорта: ";
					cin >> searchPassport;
					bool found = true;
					for (Patients pat : vPatients)
					{

						if (searchPassport == pat.GetPassport())
						{
							cout << "Имя:" << " " << pat.Getname() << endl;
							cout << "Фамилия:" << " " << pat.GetSurname() << endl;
							cout << "Возраст:" << " " << pat.GetAge() << endl;
							cout << "Номер карты пациента: " << " " << pat.GetNumberOfCard() << endl;
							cout << "Текущий диагноз:" << " " << pat.GetDiagnosis() << endl;
							found = false;//остановка
						}
					}

					if (found)
					{
						cout << "Пациент с таким номером пасспорта не найден" << endl;
					}
				}
				if (choice == '2')//поиск по номеру карты
				{
					int searchNumberOfCard;
					system("cls");
					cout << "Введите номер карты для поиска: ";
					cin >> searchNumberOfCard;
					bool found = true;

					for (Patients pat : vPatients)
					{
						if (searchNumberOfCard == pat.GetNumberOfCard())
						{
							cout << "Фамилия:" << " " << pat.GetSurname() << endl;
							cout << "Имя:" << " " << pat.GetName() << endl;
							cout << "Возраст:" << " " << pat.GetAge() << endl;
							cout << "Текущий диагноз:" << " " << pat.GetDiagnosis() << endl;
							found = false;
						}

						if (found)//если введеное значение не найдено
						{
							cout << "Пациент с таким номером карты не найден";
						}
					}
				}
				break;

			case '2'://записать пациента
					int searchNumberOfCard;
				do
				{
					system("cls");
					cout << "\n Введите номер карты пациента:" << " ";
					cin >> searchNumberOfCard;

					for (Patients pat : vPatients)
					{
						if (searchNumberOfCard == pat.GetNumberOfCard())//сравнение введеного знач с данными
						{
							cout << "Фамилия:" << " " << pat.GetSurname() << endl;
							cout << "Имя:" << " " << pat.GetName() << endl;
							cout << "Возраст:" << " " << pat.GetAge() << endl;
							cout << "Текущий диагноз:" << " " << pat.GetDiagnosis() << endl;
							found = false;

							ChoiceDoctor();
						}
					}
					if (found)//если введеное значение не найдено
					{
						cout << "Пациент с таким номером карты не найден" << endl;
						cout << "для выхода нажмите \"0\""<< endl;
					}
				} while (found && searchNumberOfCard != 0);//до тех пор, пока не будет нажат 0 
				system("cls");
				Menu();
			case '3':

				Three();//метод выбора категории записи

				break;
			}
		}
		while (choice != '4');//выход из программы
		return;
	}


	void TimeVaribol(Doctors doc, Patients pat)//метод вывода времени и даты
	{
		
		string iterText;
		system("cls");
		cout << "Выберите дату:" << endl << "\n";

		for (int i = 0; i < vDate.size(); i++)
		{
			cout << i + 1 << "  " << vDate[i] << endl;//вывод даты
		}

		cin >> iterText;
		int position = stoi(iterText);
		system("cls");
		cout << "Ваш выбор даты:" << vDate[position - 1] << endl;

		cout << "Выберите время:" << endl;
		for (int i = 0; i < vTime.size(); i++)
		{
			cout << i + 1 << " " << vTime[i] << endl;//вывод времени
		}

		cin >> iterText;
		system("cls");
		cout << "Ваш выбор даты:" << vDate[position - 1] << endl;
		cout << "Ваш выбор Времени:" << vTime[position - 1] << endl;

		cout << "Для подтверждения записи нажмите \"у\"" << "  " << endl;;
		cout << "Для выхода в меню нажмите \"n\"" << "  " << endl;
		cin >> iterText;
		system("cls");
		bool found = true;
		if (iterText == "y")//при подтверждении записи
		{
			cout << "Запись создана" << "\n"
				<< "Пациент:" << " " << pat.GetSurname() << " " << pat.GetName() << "\n"
				<< "Возраст:" << " " << pat.GetAge() << "\n"
				<< "Записан на : " << vDate[position - 1] << " в " << vTime[position - 1] << "\n" << endl;
			cout << "К специалисту:" << doc.GetSpeciality() << "\n"
				<< "ФИО:" << " " << doc.GetSurname() << " " << doc.GetName() << "\n"
				<< "Номер кабинета: #" << doc.GetCabinetNumber() << endl;
			Menu();
		}
		if (iterText == "n")//при отказе от записи
		{
			Menu();
		}
		
	}
	void ChoiceDoctor()//метод выбора врача и вывода времени
	{
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
				for (Patients pat : vPatients)
				{
					if (doc.GetSpeciality() == "Хирург")
					{
						TimeVaribol(doc, pat);//метод выбора времени
					}
				}
			}
			break;
		case'2':
			for (Doctors doc : vDoctors)
			{
				for (Patients pat : vPatients)
				{
					if (doc.GetSpeciality() == "Терапевт")
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
					if (doc.GetSpeciality() == "Офтальмолог")
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
					if (doc.GetSpeciality() == "Стоматолог")
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
					if (doc.GetSpeciality() == "Отоларинголог")
					{
						TimeVaribol(doc, pat);
					}
				}
			}
			break;

		default:
			cout << "Выберите другой вариант";
			Menu();
			break;
		}

	}
	void CreateModel()//метод создания экземпляров
	{

		setlocale(LC_ALL, "Russian");
	
		// Services(Category,NameOfServ, Cost);

		vServices.push_back((*new Services("Инъекции", "в/м инъекции", 500)));
		vServices.push_back((*new Services("Инъекции", "в/в инъекции", 500)));
		vServices.push_back((*new Services("Инъекции", "п/к инъекции", 500)));
		vServices.push_back((*new Services("Анализы", "Анализ крови на сахар", 100)));
		vServices.push_back((*new Services("Анализы", "Анализ крови общий", 100)));
		vServices.push_back((*new Services("Справки", "Больничный лист", 800)));
		vServices.push_back((*new Services("Справки", "Мед книжка", 1000)));



		//Patients(Name, surname, age, NumberOfCard, Diagnosis, passport);

		vPatients.push_back((*new Patients("Иван", "Петров", 23, 12, "Простуда", 1)));
		vPatients.push_back((*new Patients("Петр", "Петров", 45, 789012, "Грипп", 2222)));
		vPatients.push_back((*new Patients("Анна", "Сидорова", 19, 345678, "Ангина", 3333)));
		vPatients.push_back((*new Patients("А", "А", 35, 11, "Плоскостопие", 4444)));
		vPatients.push_back((*new Patients("Екатерина", "Фомина", 27, 588522, "Сколиоз", 5555)));
		vPatients.push_back((*new Patients("Олег", "Жмурин", 87, 23425, "Острая боль в животе", 6666)));
		vPatients.push_back((*new Patients("Зоя", "Космодемьянская", 40, 27438, "Средний кариес", 7777)));

		//Doctors(string name, string surname, int age, string speciality, int cabinetNumber)
		vDoctors.push_back(*new Doctors("Иван", "Иванов", 56, "Хирург", 1));
		vDoctors.push_back((*new Doctors("Иван", "Иванов", 34, "Терапевт", 2)));
		vDoctors.push_back((*new Doctors("Иван", "Иванов", 45, "Офтальмолог", 3)));
		vDoctors.push_back((*new Doctors("Иван", "Иванов", 49, "Стоматолог", 4)));
		vDoctors.push_back((*new Doctors("Иван", "Иванов", 37, "Отоларинголог", 5)));

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


