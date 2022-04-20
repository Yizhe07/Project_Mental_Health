#include<string>
#include<sstream>
#include<vector>
#include<fstream>
#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

class Person
{
	using uint32 = unsigned;
public:
	Person();
	Person(uint32 ID);
	Person(uint32 ID, int Age, const std::string& Gender, 
		const std::string& Country, const std::string& State, 
		const std::string& History, const std::string& Work, 
		const std::string& Score);
	void display();
	std::string datainfo();
	void datawrite(const std::string& str);
public:
	bool operator==(const Person& right) const;
	bool operator>(const Person& right) const;
	bool operator<(const Person& right) const;
public:
	uint32 ID;
	int Age;
	std::string Gender;
	std::string Country;
	std::string State;
	std::string History;
	std::string Work;
	std::string Score;
};

Person::Person() :ID(0), Age(0)
{
}

Person::Person(uint32 ID) : Person()
{
	this->ID = ID;
}

Person::Person(uint32 ID, int Age, const std::string& Gender, const std::string& Country, const std::string& State, const std::string& History, const std::string& Work, const std::string& Score)
	:ID(ID), Age(Age), Gender(Gender), Country(Country), State(State), History(History), Work(Work), Score(Score)
{
}

void Person::display()
{
	cout << this->ID << "\t" << this->Age << "\t" << this->Gender << "\t" << this->Country << "\t" << this->State << "\t" << this->History << "\t" << this->Work << "\t" << this->Score << endl;

}

std::string Person::datainfo()
{
	stringstream ss;
	ss << this->ID << "\t" << this->Age << "\t" << this->Gender << "\t" << this->Country << "\t" << this->State << "\t" << this->History << "\t" << this->Work << "\t" << this->Score << endl;
	return ss.str();
}

void Person::datawrite(const std::string& str)
{
	stringstream ss(str);
	ss << this->ID << "\t" << this->Age << "\t" << this->Gender << "\t" << this->Country << "\t" << this->State << "\t" << this->History << "\t" << this->Work << "\t" << this->Score;
}


bool Person::operator==(const Person& right) const
{
	return this->ID == right.ID;
}

bool Person::operator>(const Person& right) const
{
	return this->ID > right.ID;
}

bool Person::operator<(const Person& right) const
{
	return this->ID < right.ID;
}


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
	Control();
	void start();
	void menu();
	void display();
	void insert();
	void delet();
	void modify();
	void search();
	void sort();
private:
	void read(const std::string& fileName);
	void write(const std::string& fileName);
public:
	std::string tableHeader;
	std::vector<Person> pervec;
};

Control::Control()
{
	read("./data.txt");
}

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
			write("./save.txt");
			exit(0);
			break;
		default:
			break;
		}
	}
}

void Control::menu()
{
	cout << "===   Mental health System   ==="<< endl;
	cout << "***** 1, Display          *****" << endl;
	cout << "***** 2, Insert new data  *****" << endl;
	cout << "***** 3, Delete data      *****" << endl;
	cout << "***** 4, Modify data      *****" << endl;
	cout << "***** 5, Search data      *****" << endl;
	cout << "***** 6, Sort data        *****" << endl;
	cout << "***** 7, Exit             *****" << endl;
	cout << "***** 0, Clear screen     *****" << endl;
	cout << endl;
}

void Control::display()
{
	std::cout << this->tableHeader << endl;
	for (auto& val : pervec)
	{
		val.display();
	}
	std::cout << "There are(" << pervec.size() << ")data" << endl;
}

void Control::insert()
{
	Person per;
	cout << "Please enter the ID" << endl;
	cin >> per.ID;
	cout << "Please enter Age" << endl;
	cin >> per.Age;
	cout << "Please enter Gender" << endl;
	cin >> per.Gender;
	cout << "Please enter Country(Please enter country abbreviation in order to keep the format right)" << endl;
	cin >> per.Country;
	cout << "Please enter State(Please enter state abbreviation in order to keep the format right)" << endl;
	cin >> per.State;
	cout << "If you have mental problems history, please enter Yes, else please enter No" << endl;
	cin >> per.History;
	cout << "If you have too much work, please enter Yes, else please enter No" << endl;
	cin >> per.Work;
	cout << "Please enter Score(A, B, C or D)" << endl;
	cin >> per.Score;
	pervec.push_back(per);
}

void Control::delet()
{
	int n = -1;
	cout << "Please enter the ID of the person you want to delete>";
	cin >> n;
	auto del = std::find(pervec.begin(), pervec.end(), Person(n));
	if (del != pervec.end())
	{
		pervec.erase(del);
	}
}

void Control::modify()
{
	cout << "Please enter the ID of the person you want to modify" << endl;
	Person per;
	cin >> per.ID;
	auto findit = std::find(pervec.begin(), pervec.end(), per);
	if (findit != pervec.end())
	{
		pervec.erase(findit);
		cout << "Please enter the new ID" << endl;
		cin >> per.ID;
		cout << "Please enter  new Age" << endl;
		cin >> per.Age;
		cout << "Please enter  newGender" << endl;
		cin >> per.Gender;
		cout << "Please enter  new Country(Please enter country abbreviation in order to keep the format right)" << endl;
		cin >> per.Country;
		cout << "Please enter new State(Please enter state abbreviation in order to keep the format right)" << endl;
		cin >> per.State;
		cout << "If you have mental problems history, please enter Yes, else please enter No" << endl;
		cin >> per.History;
		cout << "If you have too much work, please enter Yes, else please enter No" << endl;
		cin >> per.Work;
		cout << "Please enter Score(A, B, C or D)" << endl;
		cin >> per.Score;
		pervec.push_back(per);
	}
}

void Control::search()
{
	cout << "Please enter the ID of the person you want to search for" << endl;
	Person per;
	cin >> per.ID;
	auto findIt = std::find(pervec.begin(), pervec.end(), per);
	if (findIt != pervec.end())
	{
		cout << "Found ";
		findIt->display();
	}

}

void Control::sort()
{
	int sign;
	cout << "If want to sort ID from low to high, enter 1, if you want to sort ID from high to low, enter 2" << endl;
	cin >> sign;
	if (sign == 1)
	{
		std::sort(pervec.begin(), pervec.end());
		std::cout << "Sorting succeed" << std::endl;
	}

	else if (sign == 2)
	{
		std::sort(pervec.begin(), pervec.end(), greater<>());
		std::cout << "Sorting succeed" << std::endl;
	}

	else if (sign != 2 && sign != 1)
	{
		cout << "Invalid input" << endl;
	}
}

void Control::read(const std::string& fileName)
{
	fstream stream(fileName.c_str(), ios::in);
	if (!stream.is_open())
	{
		cerr << fileName << " file open failed" << endl;
		return;
	}
	Person per;
	char buf[1024] = { 0 };
	stream.getline(buf, 1024);
	tableHeader = buf;
	while (!stream.eof())
	{
		memset(buf, 0, sizeof(buf));
		stream.getline(buf, 1024);

		stringstream ss(buf);
		ss >> per.ID >> per.Age >> per.Gender >> per.Country >> per.State >> per.History >> per.Work >> per.Score;
		pervec.push_back(per);
	}
	stream.close();
}

void Control::write(const std::string& fileName)
{
	fstream write(fileName.c_str(), ios::trunc | ios::out);
	if (!write.is_open())
	{
		cerr << fileName << " file open failed [save]";
		return;
	}
	tableHeader += '\n';
	write.write(tableHeader.c_str(), tableHeader.size());
	for (auto& val : pervec)
	{
		string info = val.datainfo();
		write.write(info.c_str(), info.size());
	}
	write.close();
}


int main()
{
	Control x;
	x.start();
}
