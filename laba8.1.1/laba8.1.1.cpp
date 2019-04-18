#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <windows.h>
#include <iomanip>
using namespace std;

double av(int a, int b, int c, int d) {
	return (a + b + c + d) / 4;
}

struct student {
	string surname, name, sname;
	int group, year;
	int m, p, i, c;
	double aver;
};

student record() {
	struct student stud;
	cout << "Введите фамилию студента:\n";
	cin >> stud.surname;
	cout << "\nВведите имя студента:\n";
	cin >> stud.name;
	cout << "\nВведите отчество студента\n";
	cin >> stud.sname;
	cout << "\nВведите год рождения\n";
	cin >> stud.year;
	cout << "\nВведите группу студента\n";
	cin >> stud.group;
	cout << "\nВведите балл по математике\n";
	cin >> stud.m;
	cout << "\nВведите балл по химии\n";
	cin >> stud.c;
	cout << "\nВведите балл по информатике\n";
	cin >> stud.i;
	cout << "\nВведите балл по физике\n";
	cin >> stud.p;
	stud.aver = av(stud.p, stud.m, stud.i, stud.c);
	return stud;
}

void file(vector<student> a) {
	ofstream file("file.txt", ios::app);
	for (int i = 0; i < a.size(); i++) {
		file << a[i].surname << ' ';
		file << a[i].name << ' ';
		file << a[i].sname << ' ';
		file << a[i].year << ' ';
		file << a[i].group << ' ';
		file << a[i].p << ' ';
		file << a[i].m << ' ';
		file << a[i].i << ' ';
		file << a[i].c << ' ';
		file << fixed << setprecision(1) << a[i].aver << endl;
	}
	file.close();
}

int search(vector<student> a, string sur) {
	ifstream file("file.txt");
	for (int i = 0; i < a.size(); i++) {
		if (a[i].surname == sur) {
			cout << a[i].surname << endl;
			cout << a[i].name << endl;
			cout << a[i].sname << endl;
			cout << a[i].year << endl;
			cout << a[i].group << endl;
			cout << a[i].p << endl;
			cout << a[i].m << endl;
			cout << a[i].i << endl;
			cout << a[i].c << endl;
			cout << a[i].aver << endl;
			return i;
		}
		else
		{
			cout << "\nТакого студента не найдено\n";
		}
	}
	file.close();
}

vector<student> edit(vector<student> a, int siz) {
	int i;
	string tmp;
	int tm;
	cout << "Что изменить?\n1.Фамилию\n2.Имя\n3.Отчество\n4.Год рождения\n5.Группу\n6.Оценку по физике\n7.Оценку по математике\n8.Оценку по информатике\n9.Оценку по химии\n";
	cin >> i;
	switch (i)
	{
	case 1:
		cin >> tmp;
		a[siz].surname = tmp;
		break;
	case 2:
		cin >> tmp;
		a[siz].name = tmp;
		break;
	case 3:
		cin >> tmp;
		a[siz].sname = tmp;
		break;
	case 4:
		cin >> tm;
		a[siz].year = tm;
		break;
	case 5:
		cin >> tm;
		a[siz].group = tm;
		break;
	case 6:
		cin >> tm;
		a[siz].p = tm;
		break;
	case 7:
		cin >> tm;
		a[siz].m = tm;
		break;
	case 8:
		cin >> tm;
		a[siz].i = tm;
		break;
	case 9:
		cin >> tm;
		a[i].c = tm;
		break;
	}
	ofstream file("file.txt", ios::trunc);
	file.close();
	return(a);
}

int s() {
	string s;
	int i=0;
	ifstream file("file.txt");
	while (!file.eof()) {
		getline(file, s, '\n');
		i++;
	}
	return i;
}

void task(vector<student> a) {
	int group;
	bool ret;
	double score;
	cout << "\nВведите необходимую группу\n";
	cin >> group;
	cout << "\nВведите минимальный балл\n";
	cin >> score;
	for (int i = 0; i < a.size(); i++) {
		if (a[i].group == group) {
			if (a[i].aver >= score) {
				cout << a[i].surname << ' ';
				cout << a[i].name << ' ';
				cout << a[i].sname << ' ';
				cout << a[i].year << ' ';
				cout << a[i].group << ' ';
				cout << a[i].p << ' ';
				cout << a[i].m << ' ';
				cout << a[i].i << ' ';
				cout << a[i].c << ' ';
				cout << a[i].aver << '\n';
			}
		}
	}
}

int main()
{
	struct student std;
	int x;
	string sear;
	vector <student> stud;
	setlocale(LC_ALL, "rus");
	ifstream fil("file.txt");
	for (int i = 0; i < s(); i++) {
		fil >> std.surname;
		fil >> std.name;
		fil >> std.sname;
		fil >> std.year;
		fil >> std.group;
		fil >> std.p;
		fil >> std.m;
		fil >> std.i;
		fil >> std.c;
		fil >> std.aver;
		stud.push_back(std);
	}
	int m;
	do {
		cout << "Чего желаете?\n1.Создание студента\n2.Просмотр данных студента по фамилии\n3.Редактирование данных студента\n4.Нахождение всех студентов одной группы, балл которых выше введённого\n0.Выход\n";
		cin >> x;
		switch (x)
		{
		default: cout << "Введите 1,2,3,4,0\n";
			break;
		case 0:
			system("pause");
			break;
		case 1:
			stud.push_back(record());
			file(stud);
			break;
		case 2:
			cout << "Введите фамилию ученика, которого вы ищете\n";
			cin >> sear;
			search(stud, sear);
			break;
		case 3:
			cout << "Введите фамилию ученика, которого вы ищете\n";
			cin >> sear;
			m = search(stud, sear);
			stud = edit(stud, m);
			file(stud);
			break;
		case 4:
			task(stud);
			break;
		}
	} while (x != 0);
}