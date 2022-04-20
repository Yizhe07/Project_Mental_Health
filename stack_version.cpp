
#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;


class Person
{
public:
	Person()
	{}
	Person(Person& one)
	{
		strcpy_s(strID, one.strID);
		strcpy_s(strGender, one.strGender);
		strcpy_s(strCountry, one.strCountry);
		strcpy_s(strState, one.strState);
		strcpy_s(strHistory, one.strHistory);
		strcpy_s(strWork, one.strWork);
		strcpy_s(strScore, one.strScore);
		fAge[0] = one.fAge[0];
	}
	void SetData(const char* id, const char* gender, const char* country, const char* state, const char* history, const char* work, const char* score, float s)
	{
		strcpy_s(strID, id);
		strcpy_s(strGender, gender);
		strcpy_s(strCountry, country);
		strcpy_s(strState, state);
		strcpy_s(strHistory, history);
		strcpy_s(strWork, work);
		strcpy_s(strScore, score);
		fAge[0] = s;
	}
	void Output(void)
	{
		cout << "ID:" << strID << endl;
		cout << "GENDER:" << strGender << endl;
		cout << "COUNTRY:" << strCountry << endl;
		cout << "STATE:" << strState << endl;
		cout << "HISTORY:" << strHistory << endl;
		cout << "WORK:" << strWork << endl;
		cout << "SCORE:" << strScore << endl;
		cout << "AGE:" << fAge[0] << endl;
	}
	void Input(void)
	{
		cout << "ID:";
		cin >> strID;
		cout << "GENDER:";
		cin >> strGender;
		cout << "COUNTRY:";
		cin >> strCountry;
		cout << "STATE:";
		cin >> strState;
		cout << "HISTORY:";
		cin >> strHistory;
		cout << "WORK:";
		cin >> strWork;
		cout << "SCORE:";
		cin >> strScore;
		cout << "AGE:";
		cin >> fAge[0];
	}
private:
	char strID[12];
	char strGender[12];
	char strCountry[12];
	char strState[12];
	char strHistory[12];
	char strWork[12];
	char strScore[12];
	float fAge[3];
};


class CStack
{
public:
	CStack(int nSize = 10);
	~CStack();
public:
	void push(Person a);
	Person pop(void);
private:
	Person* sp;
	Person* buffer;
	int m_nSize;
};




class Control
{
	enum Operator
	{
		Display = 1,
		Insert,
		Delete,
		Modify,
		Search,
		Sort,
		Exit,
	};
public:
	void initialization();
	void start();
	void menu();
	void display();
	void insert();
	void delet();
	void modify();
	void search();
	void sort();
};



void Control::start()
{
	menu();
	while (true)
	{
		cout << "Please choose>";
		int op = -1;
		cin >> op;
		switch (op)
		{
		case 0:
			system("cls");
			menu();
			break;
		case Control::Display:
			display();
			break;
		case Control::Insert:
			insert();
			break;
		case Control::Delete:
			delet();
			break;
		case Control::Modify:
			modify();
			break;
		case Control::Search:
			search();
			break;
		case Control::Sort:
			sort();
			break;
		case Control::Exit:
			exit(0);
			break;
		default:
			break;
		}
	}
}


void Control::menu()
{
	cout << "===   Mental health System   ===" << endl;
	cout << "***** 1, Display          *****" << endl;
	cout << "***** 2, Insert new data  *****" << endl;
	cout << "***** 3, Delete data      *****" << endl;
	cout << "***** 4, Modify data      *****" << endl;
	cout << "***** 5, Search data      *****" << endl;
	cout << "***** 6, Sort data        *****" << endl;
	cout << "***** 7, Exit and save    *****" << endl;
	cout << "***** 0, Clear screen     *****" << endl;
	cout << endl;
}

void Control::initialization()
{

}

void Control::display()
{
	CStack one(10);
	Person Per;
	Per.SetData("1", "Male", "USA", "MS", "YES", "NO", "A", 43);
	one.push(Per);
	Per.SetData("2", "Female", "USA", "LA", "YES", "YES", "C", 56);
	one.push(Per);
	Per.SetData("3", "Female", "USA", "NY", "NO", "YES", "D", 37);
	one.push(Per);
	Per.SetData("4", "Male", "USA", "VA", "NO", "NO", "B", 50);
	one.push(Per);
	Per.SetData("5", "Female", "USA", "MS", "YES", "NO", "B", 19);
	one.push(Per);
	Per = one.pop();
	Per.Output();
	Per = one.pop();
	Per.Output();
	Per = one.pop();
	Per.Output();
	Per = one.pop();
	Per.Output();
	Per = one.pop();
	Per.Output();
}

void Control::insert()
{

}

void Control::delet()
{

}

void Control::modify()
{

}

void Control::search()
{

}

void Control::sort()
{

}

int main(void)
{
	Control x;
	x.start();
}

CStack::CStack(int nSize)
{
	m_nSize = nSize;
	buffer = new Person[m_nSize];
	if (buffer != NULL)
		sp = buffer;
	else
		exit(1);
}



CStack::~CStack()
{
	if (buffer) {
		delete[] buffer;
		buffer = NULL;
	}
}


void CStack::push(Person a)
{
	if (sp > buffer + m_nSize) {
		exit(1);
	}
	else
		*sp++ = a;
}


Person CStack::pop(void)
{
	sp--;
	if (sp < buffer) {
		exit(1);
	}
	else
		return *sp;
}
