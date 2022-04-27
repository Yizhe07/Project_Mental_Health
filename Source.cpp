#include<string>
#include<sstream>
#include<vector>
#include<fstream>
#include<iostream>
#include<algorithm>
#include<cstring>



/*

 Division of duties

Yizhe Wang:

1. (The stack version display code)
2. Create the data structure for person (Class person and sequences of strings)
3. Read data from the txt file
4. Save the dataset in a new text file
5. Menu
6. Delete function
7. Modify function (Individual work)
8. Search function
9. Sort function
10. Read and Write function (Individual work)
11. Documentation and user guideline



Jalen Smith:

1. Find and the dataset
2. Display function
3. Empty function (Individual work)
4. PowerPoint for presentation
5. Documentation
6. Menu


Jamal Beacham

1. Keep the dataset in right text format
2. Insert Function
3. Size Function (Individual work)
4. Documentation
5. Menu



*/




using namespace std;

class Person
{
	using uint32 = unsigned; //Use uint32 to restore more data because there is no negative numbers.
public:
	Person(); //The function itself
	Person(uint32 ID); //Use ID to identify different people.
	Person(uint32 ID, int Age, const std::string& Gender, //use std to store the the data. Data structure used is std string.
		const std::string& Country, const std::string& State,
		const std::string& History, const std::string& Work,
		const std::string& Score);
	void display(); //The display operation.
	std::string datainfo(); //To get our data information as strings.
	void datawrite(const std::string& str); //To write our data information down.
public:
	bool operator==(const Person& right) const; // To eliminate inappropriate data and be more efficient.
	bool operator>(const Person& right) const;
	bool operator<(const Person& right) const;
public:
	uint32 ID; //All of the different types in our data
	int Age;
	std::string Gender;
	std::string Country;
	std::string State;
	std::string History;
	std::string Work;
	std::string Score;
};

Person::Person() :ID(0), Age(0) // In order to initialize our data. All of the numbers should be 0.
{
}

Person::Person(uint32 ID) : Person()
{
	this->ID = ID;
}

// The data structure should be a sequnces of strings.
Person::Person(uint32 ID, int Age, const std::string& Gender, const std::string& Country, const std::string& State, const std::string& History, const std::string& Work, const std::string& Score)
	:ID(ID), Age(Age), Gender(Gender), Country(Country), State(State), History(History), Work(Work), Score(Score)
{
}

//Display all of the data.
void Person::display()
{
	cout << this->ID << "\t" << this->Age << "\t" << this->Gender << "\t" << this->Country << "\t" << this->State << "\t" << this->History << "\t" << this->Work << "\t" << this->Score << endl;

}

// To get our data information as a sequence of strings.
std::string Person::datainfo()
{
	stringstream ss;
	ss << this->ID << "\t" << this->Age << "\t" << this->Gender << "\t" << this->Country << "\t" << this->State << "\t" << this->History << "\t" << this->Work << "\t" << this->Score << endl;
	return ss.str();
}

// Write the data down.
void Person::datawrite(const std::string& str)
{
	stringstream ss(str);
	ss << this->ID << "\t" << this->Age << "\t" << this->Gender << "\t" << this->Country << "\t" << this->State << "\t" << this->History << "\t" << this->Work << "\t" << this->Score;
}

// To eliminate inappropriate data and be more efficient.
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

// Define another class for the menu.
class Control
{
	enum Operator //Create the menu. One number for one operation.
	{
		Display = 1,
		Insert,
		Delete,
		Sort,
		Search,
		Size,
		Empty,
		Modify,
		Exit,
	};
public:
	Control(); //Use itself in order to read the data in first.
	void start();
	void menu();
	void display();
	void insert();
	void delet();
	void sort();
	void search();
	void modify();
	void size();
	void empty();
private:
	void read(const std::string& fileName);
	void write(const std::string& fileName);
public:
	std::string tableHeader; //The table header
	std::vector<Person> pervec; // Use vector to store our data and process different operations.
};

Control::Control() //Read the data in first.
{
	read("./data.txt");
}

void Control::start()
{
	menu();
	while (true)
	{
		cout << "Please choose the operation you want<From 0 to 8>";
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
		case Control::Sort:
			sort();
			break;
		case Control::Empty:
			empty();
			break;
		case Control::Size:
			size();
			break;
		case Control::Search:
			search();
			break;
		case Control::Modify:
			modify();
			break;
		case Control::Exit:
			write("./save.txt"); //Save our data in another txt file.
			exit(0);
			break;
		default:
			break;
		}
	}
}

//Menu
void Control::menu()
{
	cout << "===   Mental Health System   ===" << endl;
	cout << "***** 1, Display          *****" << endl;
	cout << "***** 2, Insert new data  *****" << endl;
	cout << "***** 3, Delete data      *****" << endl;
	cout << "***** 4, Sort data        *****" << endl;
	cout << "***** 5, Search data      *****" << endl;
	cout << "***** 6, Size of the data *****" << endl;
	cout << "***** 7, Check empty      *****" << endl;
	cout << "***** 8, Modify data      *****" << endl;
	cout << "***** 9, Exit and save    *****" << endl;
	cout << "***** 0, Clear screen     *****" << endl;
	cout << endl;
}

//Display
void Control::display()
{
	std::cout << this->tableHeader << endl;
	//Dispaly the table header first.
	for (auto& val : pervec) //Use auto to display the correct type of data.
	{
		val.display();
	}
	std::cout << "There are(" << pervec.size() << ")data" << endl; //Size of the data
}

//Insert
void Control::insert()
{
	Person per;
	cout << "Please enter the ID" << endl;
	cin >> per.ID;
	cout << "Please enter Age" << endl;
	cin >> per.Age;
	cout << "Please enter Gender" << endl;
	cin >> per.Gender;
	cout << "Please enter Country(Please enter country abbreviation)" << endl;
	cin >> per.Country;
	cout << "Please enter State(Please enter state abbreviation)" << endl;
	cin >> per.State;  
	cout << "If you have mental problems history, please enter Yes, else please enter No" << endl;
	cin >> per.History;
	cout << "If you have too much work, please enter Yes, else please enter No" << endl;
	cin >> per.Work;
	cout << "Please enter Score(A, B, C or D)" << endl;
	cin >> per.Score;
	pervec.push_back(per); //use push_back to add a new data in the end.
}

void Control::delet()
{
	int n = -1;
	cout << "Please enter the ID of the person you want to delete>";
	cin >> n;
	auto del = std::find(pervec.begin(), pervec.end(), Person(n)); //Also can use auto here to tarverse the list.
	//If n is in the list, then delete it, else print error
	if (del != pervec.end())
	{
		pervec.erase(del);
	}
	else
	{
		cout << "No ID found, please choose another operation." << endl;
	}
}

//In order to modify the list, we can first delete the chosed data and then write in a new one.
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
		cout << "Please enter  new Gender" << endl;
		cin >> per.Gender;
		cout << "Please enter  new Country(Please enter country abbreviation)" << endl;
		cin >> per.Country;
		cout << "Please enter new State(Please enter state abbreviation)" << endl;
		cin >> per.State;
		cout << "If you have mental problems history, please enter Yes, else please enter No" << endl;
		cin >> per.History;
		cout << "If you have too much work, please enter Yes, else please enter No" << endl;
		cin >> per.Work;
		cout << "Please enter Score(A, B, C or D)" << endl;
		cin >> per.Score;
		pervec.push_back(per);
	}
	//If not found,print error.
	else
	{
		std::cout << "No ID found, please choose another operation." << endl;
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
	else
	{
		cout << "No ID found, please choose another operation." << endl;
	}

}

void Control::sort()
{
	int sign;
	cout << "If want to sort ID from low to high, enter 1, if you want to sort ID from high to low, enter 2" << endl;
	cin >> sign;
	//Use the sort function in algorithm. It will sort the ID of different people.
	if (sign == 1)
	{
		std::sort(pervec.begin(), pervec.end());
		std::cout << "Sorting succeed" << std::endl;
	}
	//The default of sort function is from low to high, we can add greater in th end to sort from high to low.
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

//Size of the data.
void Control::size()
{
	Person per;
	std::cout << "The total number of the data is " << pervec.size() << endl;
}

//check if the data file is empty
void Control::empty()
{
	fstream file;
	int ch;
	file.open("data.txt", ios::in);
	ch = file.get(); 
	if (file.eof())
	{
		cout << "Empty data file" << endl;
	}
	else
	{
		cout << "The data file is not empty" << endl;
	}
	file.close();
	return;
}

//Read the txt file
void Control::read(const std::string& fileName)
{

	//Check if the file can be opened.
	fstream stream(fileName.c_str(), ios::in);
	if (!stream.is_open())
	{
		cerr << fileName << " file open failed" << endl;
		return;
	}
	Person per;
	//Creat an empty buffer.
	char buf[1024] = { 0 };
	stream.getline(buf, 1024);
	tableHeader = buf;
	//First need to read the table header.
	//And then the data
	while (!stream.eof())
	{
		memset(buf, 0, sizeof(buf));
		stream.getline(buf, 1024);
		//Read the data
		//And then display it.
		stringstream ss(buf);
		ss >> per.ID >> per.Age >> per.Gender >> per.Country >> per.State >> per.History >> per.Work >> per.Score;
		pervec.push_back(per);
	}
	stream.close();
}

//Save the new dataset as another txt file.
void Control::write(const std::string& fileName)
{
	fstream write(fileName.c_str(), ios::trunc | ios::out);
	//check if the file can be opened.
	if (!write.is_open())
	{
		cerr << fileName << " file open failed [save]";
		return;
	}
	//write the table header
	tableHeader += '\n';
	//Use the strings already read for the table header.
	write.write(tableHeader.c_str(), tableHeader.size());
	for (auto& val : pervec)
	{
		//Write the new data.
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
