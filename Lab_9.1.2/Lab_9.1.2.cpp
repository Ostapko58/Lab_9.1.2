#include<iostream>
#include<windows.h>
#include<iomanip>
#include<string>
using namespace std;


enum Specialnists
{
	computer_science,
	informatics,
	math_a_economics,
	physics_and_informatics,
	labor_education
};

struct Student
{
	string prizv;
	int kyrs;
	Specialnists specialst;
	int math_grade;
	int physics_grade;
	union
	{
		int programing_grade;
		int chisel_metod_grade;
		int pedagogic_grade;
	};

};



void Create(Student* stud, const int N)
{
	int specialst;
	for (int i = 0; i < N; i++)
	{
		cout << "Студент № " << i + 1 << ":" << endl;
		cin.get(); cin.sync();
		cout << " Прізвище: "; getline(cin, stud[i].prizv);
		cout << " Курс: "; cin >> stud[i].kyrs;
		cout << " Спеціальність (0 - Комп’ютерні науки, 1 - Інформатика, 2 - Математика та економіка, 3 - Фізика та інформатика, 4 - Трудове навчання): ";
		cin >> specialst;
		stud[i].specialst = (Specialnists)specialst;
		cout << " Оцінка з математики: "; cin >> stud[i].math_grade;
		cout << " Оцінка з фізики: "; cin >> stud[i].physics_grade;

		switch (stud[i].specialst)
		{
		case computer_science:
			cout << " Оцінка з програмування : "; cin >> stud[i].programing_grade;
			break;
		case informatics:
			cout << " Оцінка з чисельних методів : "; cin >> stud[i].chisel_metod_grade;
			break;
		default:
			cout << " Оцінка з чисельних педагогіки : "; cin >> stud[i].pedagogic_grade;
			break;
		}
		cout << endl;
	}
}

void Print(Student* stud, const int N, string* List)
{
	cout << "======================================================================================================================================================================================="
		<< endl;
	cout << "| № |     Прізвище     | Курс |      Спеціальність      | Оцінка з математики | Оцінка з фізики | Оцінка з програмування | Оцінка з чисельних методів | Оцінка з чисельних педагогіки |"
		<< endl;
	cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"
		<< endl;
	for (int i = 0; i < N; i++)
	{
		cout << "| " << setw(1) << right << i + 1 << " ";
		cout << "| " << setw(17) << left << stud[i].prizv
			<< "| " << setw(4) << right << stud[i].kyrs << " "
			<< "| " << setw(23) << left << List[stud[i].specialst] << " "
			<< "| " << setw(19) << right << stud[i].math_grade << " "
			<< "| " << setw(15) << right << stud[i].physics_grade << " ";
		switch (stud[i].specialst)
		{
		case computer_science:
			cout << "| " << setw(22) << setprecision(2) << fixed << right
				<< stud[i].programing_grade << " |" << setw(29) << right << " |" << setw(32) << right << " |" << endl;
			break;
		case informatics:
			cout << "| " << setw(24) << setprecision(2) << fixed << right
				<< " |" << setw(27) << right << stud[i].chisel_metod_grade << " |" << setw(32) << right << " |" << endl;
			break;
		default:
			cout << "| " << setw(24) << setprecision(2) << fixed << right
				<< " |" << setw(29) << right << " |" << setw(30) << right << stud[i].pedagogic_grade << " |" << endl;
			break;
		}
	}
	cout << "======================================================================================================================================================================================="
		<< endl;
	cout << endl;
}

//void PrizvPrint(Student* stud, const int N)
//{
//	cout << "Прізвища студентів,які мають 5 з фізики:" << endl;
//	for (int i = 0; i < N; i++)
//	{
//		if (stud[i].physics_grade==5)
//		{
//			cout << stud[i].prizv << endl;
//		}
//	}
//}

bool PrizvPrint(Student * stud, const int i)
{
		if (stud[i].physics_grade==5)
		{
			return true;
		}
		else
		{
			return false;
		}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string List[] = {
	"Комп’ютерні науки",
	"Інформатика",
	"Математика та економіка",
	"Фізика та інформатика",
	"Трудове навчання"
	};

	int N;
	cout << "Введіть N: "; cin >> N;

	Student* stud = new Student[N];
	Create(stud, N);
	Print(stud, N, List);
	cout << "Прізвища студентів,які мають 5 з фізики:" << endl;
	for (int i = 0; i < N; i++)
	{
		if (PrizvPrint(stud, i))
		{
			cout << stud[i].prizv << endl;
		}
		
	}

	return 0;
}
