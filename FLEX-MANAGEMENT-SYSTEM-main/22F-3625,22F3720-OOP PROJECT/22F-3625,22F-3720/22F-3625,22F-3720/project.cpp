#include<iostream>
#include"project.h"
#include<iomanip>
#include<fstream>
#include<string>
#include<windows.h>
using namespace std;








//////////////////////////////////////////// Admin class


Admin::Admin() {}

bool Admin::authorize()
{
	system("color 5f");


	Sleep(10);
	cout << "\n\n";
	char a[] = "                            \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb|Login as Admin|\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb";
	int size;
	size = strlen(a);
	for (int i = 0; i < size; i++)
	{
		Sleep(25);
		cout << a[i];
	}

	cout << endl << endl;


	cout << setw(100) << "HINT(o)" << endl;
	cout << setw(45) << "Enter Username:";
	cin >> setw(100) >> name;
	cout << setw(45) << "Eenter Password:";
	cin >> setw(100) >> pass;
	bool check = false;

	ifstream in;
	in.open("admindata.txt");
	if (in.is_open()) {

		string fusername;
		int fpass;
		while (in >> fusername >> fpass) {
			if (name == fusername && pass == fpass) {
				check = true;

			}

		}
	}
	return check;
}


string Admin::getfname() {
	return	firstName;
}
string Admin::getlname() {
	return lastName;
}
string Admin::getusername() {
	return username;
}
string Admin::getpass() {
	return password;
}
string Admin::getdepartment() {
	return department;
}
string Admin::getgender() {
	return gender;
}
string Admin::getcontact() {
	return contactNo;
}
string Admin::getdegree() {
	return qualification;
}
string Admin::getadd() {
	return address;
}

string Admin::getdate() {
	return date;
}
string Admin::getbloodgroup() {
	return bloodgroup;
}

string Admin::getfeestatus() {
	return feestatus;
}
int Admin::getmarks() {
	return marks;
}

float Admin::getsal() {
	return salary;

}


void Admin::setdepartment()
{
	int d;
	cout << "Enter Department:\n1.Computer science\n2.Electrical Engineering\n3.Software Engineering\n4.Business\n5.Social sciences ";
	cin >> d;
	switch (d) {
	case 1:
		department = "computer";
		break;
	case 2:

		department = "electrical";
		break;
	case 3:
		department = "software";
		break;
	case 4:

		department = "business";
		break;
	case 5:
		department = "Social";
		break;

	}
}

void Admin::setteacherattributes()
{
	cout << setw(75) << "Enter First Name:";
	cin >> setw(90) >> firstName;
	cout << setw(74) << "Enter Last Name:";
	cin >> setw(90) >> lastName;
	setdepartment();
	cout << "Enter Username: ";
	cin >> username;
	cout << "Enter Password: ";
	cin >> password;
	cout << endl;
	cout << "Enter Registration Date:";
	cin >> date;
	cout << "Enter Gender: ";
	cin >> gender;
	cout << "Enter Contact No.: ";
	cin >> contactNo;
	cout << "Enter Qualification: ";
	cin >> qualification;
	cout << "Enter Address:";
	cin >> address;
	cout << "Enter Salary for this Teacher:";
	cin >> salary;
	cout << endl;

}
void Admin::setattributes()       // set data for student
{
	cout << setw(75) << "Enter First Name:";
	cin >> setw(90) >> firstName;
	cout << setw(74) << "Enter Last Name:";
	cin >> setw(90) >> lastName;
	cout << setw(74) << "Enter Username: ";
	cin >> setw(90) >> username;
	cout << setw(74) << "Enter Password: ";
	cin >> setw(90) >> password;
	cout << endl;

	setdepartment();
	cout << "Enter Registration Date:";
	cin >> date;
	cout << "Enter Gender: ";
	cin >> gender;
	cout << "Enter Contact No.: ";
	cin >> contactNo;
	cout << "Enter Blood Group:" << endl;
	cin >> bloodgroup;
	cout << "Enter Address:" << endl;
	cin >> address;
	cout << "Enter Fees Status:" << endl;
	cin >> feestatus;
	cout << "Enter Qualification: " << endl;
	cin >> qualification;
	cout << "Enter  Marks:" << endl;
	cin >> marks;

}

void Admin::addstudent()
{
	system("cls");
	system("color B0");
	int id;
	cout << "\n\n";
	char a[] = "\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb|ADDING Student|\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb";
	int size;
	size = strlen(a);
	for (int i = 0; i < size; i++)
	{

		cout << a[i];
	}
	cout << endl << endl;

	setattributes();
	ifstream in("ids.txt");
	in >> id;
	id++;

	rollno = id;
	ofstream out("ids.txt");
	out << rollno;
	ofstream studentfile("studentdata.txt", ios::app);
	if (studentfile.is_open()) {

		studentfile << getfname() << " " << getlname() << "  " << getusername() << " " << getpass() << "  " << rollno << " " << getdepartment() << "  " << getdate() << " " << getgender() << " " << getcontact() << " " << getbloodgroup() << " " << getadd() << " " << getfeestatus() << " " << getdegree() << " " << getmarks() << endl;

		cout << "Registration successful." << endl;
		studentfile.close();
	}
	else {
		cout << "Error opening file for writing.\n";
	}

	const int maxCourses = 5;
	string courses[maxCourses];

	int num;
	cout << "Please enter the number of courses you want to register (up to " << maxCourses << "): ";
	cin >> num;

	cin.ignore();

	for (int i = 0; i < num; i++) {
		cout << "Enter your course number " << i + 1 << ": ";
		getline(cin, courses[i]);
	}

	ofstream courseFile("courses.txt", ios::app);

	if (courseFile.is_open()) {


		courseFile << getusername() << " ";

		for (int i = 0; i < num; i++)
		{
			courseFile << courses[i] << " ";
		}
		courseFile << "-1";
		courseFile << endl;

		cout << "Registration successful. Course data written to file.\n";
		courseFile.close();


	}
	else {
		cout << "Error opening file for writing.\n";
	}


	cout << endl << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	cout << "\t\t\t\t" << "|---->";
	cout << "Student added Successfuly!\n\n";



}



////////////////////////////// /////////////////////////////add teacher

void Admin::addteacher()
{
	system("cls");
	system("color B0");



	cout << "\n\n";
	char a[] = "\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb|ADDING Teacher|\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb";
	int size;
	size = strlen(a);
	for (int i = 0; i < size; i++)
	{

		cout << a[i];
	}
	cout << endl << endl;

	int id;
	cout << "Username and password authenticated succesfully:" << endl;
	setteacherattributes();
	ifstream in("teaid.txt");
	in >> id;
	id++;

	rollnot = id;
	ofstream write("teaid.txt");
	write << rollnot;
	ofstream out("teacherdata.txt", ios::app);
	if (out.is_open())
	{
		out << getfname() << " " << getlname() << " " << getdepartment() << " " << "  " << rollnot << "  " << getusername() << " " << getpass() << " " << getdate() << " " << getgender() << " " << getcontact() << " " << getdegree() << " " << getadd() << "  " << getsal() << endl;

		cout << "Teacher added successfully:" << endl;
		out.close();
	}

	else {
		cout << "Error opening file for writing.\n";
	}



	const int MAX_LECTURES = 10;
	string username;
	int numberLectures;



	cout << "Enter number of Lectures for this teacher: ";
	cin >> numberLectures;

	ofstream timetableFile("timetablefile.txt", ios::app);

	if (timetableFile.is_open()) {
		timetableFile << getusername() << " " << numberLectures << " ";

		for (int i = 0; i < numberLectures; ++i) {
			string lecture, day, timing;

			cout << "Lecture " << i + 1 << ": " << endl;
			cout << "Enter name of lecture: ";
			cin >> lecture;
			cout << "Enter day on which lecture will take place: ";
			cin >> day;
			cout << "Enter timing for lecture: ";
			cin >> timing;

			timetableFile << lecture << " " << day << " " << timing << " ";
		}

		timetableFile << "-1" << endl;
		cout << "Teacher Timetable added successfully!" << endl;
		timetableFile.close();
	}
	else {
		cout << "Unable to open timetable file." << endl;
	}

	cout << endl << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	cout << "\t\t\t\t" << "|---->";
	cout << "Complete Data About Teacher Added!\n\n";


}



void Admin::displayteacherdata()
{
	system("cls");
	system("color 17");

	cout << "\n\n";
	char a[] = "\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb";
	int size;
	size = strlen(a);
	for (int i = 0; i < size; i++)
	{

		cout << a[i];
	}
	cout << endl << endl;

	cout << setw(100) << "|Display Teacher DATA|" << endl << endl;

	string name;
	string	firstName, lastName, department, username, password, date, gender, contactNo, qualification, address;
	int id;
	ifstream in;
	float salary;
	in.open("teacherdata.txt");
	if (in.is_open()) {
		if (!in.eof()) {
			while (in >> firstName >> lastName >> department >> id >> username >> password >> date >> gender >> contactNo >> qualification >> address >> salary) {
				cout << endl << endl;
				cout << "Teacher name(first&last) is:" << firstName << " " << lastName << endl;
				cout << "Gender:" << gender << endl;
				cout << "Qualification is:" << qualification << endl;
				cout << "Contact no is:" << contactNo << endl;
				cout << "Username is:" << username << endl;

			}
			in.close();
		}

	}
	else {
		in.close();
	}


	cout << "\n\n";

	for (int i = 0; i < size; i++)
	{

		cout << a[i];
	}
	cout << endl << endl;


}






void Admin::displaystudentdata() {
	system("cls");
	system("color 17");

	cout << "\n\n";
	char a[] = "\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb";
	int size;
	size = strlen(a);
	for (int i = 0; i < size; i++)
	{

		cout << a[i];
	}
	cout << endl << endl;

	cout << setw(100) << "|Display Student DATA|" << endl << endl;

	string name;
	string firstName, fname, lastName, department, username, password, gender, contactNo, qualification, address, date, bloodgroup, feestatus;
	int mark, rollno, id;

	int marks;

	ifstream in("studentdata.txt");

	if (in.is_open()) {
		if (!in.eof()) {
			while (in >> firstName >> lastName >> username >> password >> rollno >> department >> date >> gender >> contactNo >> bloodgroup >> address >> feestatus >> qualification >> mark) {
				cout << endl << endl;
				cout << "Student ID is:" << rollno << endl;
				cout << "First and last name combine:" << firstName << " " << lastName << endl;
				cout << "Department is:" << department << endl;

			}
			in.close();
		}
		else {
			cout << "Unable to open student data file." << endl;
		}
	}


	cout << "\n\n";

	for (int i = 0; i < size; i++)
	{

		cout << a[i];
	}
	cout << endl << endl;


}


void Admin::editstudentData() {
	system("cls");
	system("color B0");


	Sleep(10);
	cout << "\n\n";
	char a[] = "\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb|Editig Student DATA|\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb";
	int size;
	size = strlen(a);
	for (int i = 0; i < size; i++)
	{
		Sleep(15);
		cout << a[i];
	}
	cout << endl << endl;
	string firstName, fname, lastName, department, username, password, gender, contactNo, qualification, address, date, bloodgroup, feestatus;
	int mark, rollno, id;

	cout << "Enter id for the student:" << endl;
	cin >> id;

	ifstream in("studentdata.txt");
	if (!in.is_open()) {
		cout << "Error in opening file." << endl;
		return;
	}

	ofstream out("newfile2.txt");

	while (in >> firstName >> lastName >> username >> password >> rollno >> department >> date >> gender >> contactNo >> bloodgroup >> address >> feestatus >> qualification >> mark) {
		if (id == rollno) {
			int choice;
			cout << "1:Change Firstname:" << endl;
			cout << "2:Change Lastname:" << endl;
			cout << "3:Change Fee status:" << endl;
			cout << "4:Change Address" << endl;
			cout << "5:Change contact no" << endl;
			cin >> choice;

			if (choice == 1) {
				cout << "enter new firstname you want:" << endl;
				cin >> firstName;
			}
			else if (choice == 2) {
				cout << "enter new lastname:" << endl;
				cin >> lastName;
			}
			else if (choice == 3) {
				cout << "enter Fees status" << endl;
				cin >> feestatus;
			}
			else if (choice == 4) {
				cout << "enter New address" << endl;
				cin >> address;
			}
			else if (choice == 5) {
				cout << "enter contact no" << endl;
				cin >> contactNo;;
			}
			else {
				cout << "invalid choice:" << endl;
			}
		}
		out << firstName << " " << lastName << " " << username << " " << password << " " << rollno << " " << department << " " << date << " " << gender << " " << contactNo << " " << bloodgroup << " " << address << " " << feestatus << " " << qualification << " " << mark << endl;

	}

	in.close();
	out.close();

	remove("studentdata.txt");
	rename("newfile2.txt", "studentdata.txt");

	cout << "Data updated successfully." << endl;
}



void Admin::editTeacherData()
{
	system("cls");
	system("color B0");


	Sleep(10);
	cout << "\n\n";
	char a[] = "\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb|Editing Teacher|\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb";
	int size;
	size = strlen(a);
	for (int i = 0; i < size; i++)
	{
		Sleep(15);
		cout << a[i];
	}
	cout << endl << endl;

	string usert;
	string firstName, lastName, department, username, password, gender, contactNo, date, qualification, address;
	int id;
	float salary;
	cout << "Enter username for the teacher:" << endl;
	cin >> usert;

	ifstream in("teacherdata.txt");
	if (!in.is_open()) {
		cout << "Error opening file." << endl;
		return;
	}

	ofstream out("newfile.txt");

	while (in >> firstName >> lastName >> department >> id >> username >> password >> date >> gender >> contactNo >> qualification >> address >> salary) {
		if (usert == username) {
			int choice;
			cout << "1:Change address:" << endl;
			cout << "2:Change contact number:" << endl;
			cout << "3:Change Qualification:" << endl;
			cout << "4:Change Salary:" << endl;
			cin >> choice;

			if (choice == 1) {
				cout << "enter new address:" << endl;
				cin >> address;
			}
			else if (choice == 2) {
				cout << "enter new contact number:" << endl;
				cin >> contactNo;
			}
			else if (choice == 3) {
				cout << "enter new degree:" << endl;
				cin >> department;
			}
			else if (choice == 4) {
				cout << "Enter new salary:" << endl;
				cin >> salary;
			}
			else {
				cout << "invalid choice:" << endl;
			}
		}
		out << firstName << " " << lastName << " " << department << " " << id << " " << username << " " << password << " " << date << " " << gender << " " << contactNo << " " << qualification << " " << address << " " << salary << endl;
	}

	in.close();
	out.close();

	remove("teacherdata.txt");
	rename("newfile.txt", "teacherdata.txt");


}

/*Admin::~Admin() {
}*/





//////////////////////////////////////////////// student   module




Student::Student()
{
}

bool Student::authorize() {
	system("cls");
	system("color 80");

	Sleep(10);
	cout << "\n\n";
	char a[] = "                            \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb|Login as Student|\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb";
	int size;
	size = strlen(a);
	for (int i = 0; i < size; i++)
	{
		Sleep(25);
		cout << a[i];
	}

	cout << endl << endl;
	cout << "\nStudent Authentication\n";

	string enteredUsername, enteredPassword;

	cout << "Enter your username: ";
	cin >> enteredUsername;
	cout << "Enter your password: ";
	cin >> enteredPassword;


	ifstream studentFile("studentdata.txt");
	if (studentFile.is_open()) {
		int rollno;
		string storedUsername, storedPassword, fname, lname, degree, date, gen, con, bg, add, fstatus, qual, marks;

		while (studentFile >> fname >> lname >> storedUsername >> storedPassword >> rollno >> degree >> date >> gen >> con >> bg >> add >> fstatus >> qual >> marks) {
			if (enteredUsername == storedUsername && enteredPassword == storedPassword) {
				ofstream out("studentsusername.txt");
				out << enteredUsername;
				cout << "Authentication successful.\n";
				studentFile.close();
				return true;
			}
		}
		studentFile.close();
	}

	cout << "Authentication failed. Incorrect username or password.\n";
	return false;
}











void Student::viewRegisteredCourses() {
	system("cls");
	system("color 17");

	cout << "\n\n";
	char a[] = "\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb";
	int size;
	size = strlen(a);
	for (int i = 0; i < size; i++)
	{

		cout << a[i];
	}
	cout << endl << endl;

	cout << setw(100) << "|View Registered Cources|" << endl << endl;


	string name, fromfile;
	ifstream courseFile("courses.txt");
	ifstream read("studentsusername.txt");
	read >> fromfile;
	if (!courseFile.is_open()) {
		cout << "Error opening courses file.\n";
		return;
	}

	string username, course;
	while (courseFile >> username) {
		if (fromfile == username) {
			cout << "Courses are" << name << ": ";

			while (courseFile >> course) {
				if (course == "-1") {
					cout << endl;
					break;
				}
				cout << course << " ";
			}
		}
	}

	courseFile.close();

	cout << endl << endl;
	for (int i = 0; i < size; i++)
	{

		cout << a[i];
	}
	cout << endl << endl;
}







void Student::viewMarks() {
	system("cls");
	system("color 17");


	cout << "\n\n";
	char a[] = "\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb";
	int size;
	size = strlen(a);
	for (int i = 0; i < size; i++)
	{

		cout << a[i];
	}
	cout << endl << endl;

	cout << setw(100) << "|View Marks|" << endl << endl;

	string studentUsername;
	int marks;
	string name, fromfile;
	;
	ifstream read("studentsusername.txt");
	read >> fromfile;

	ifstream marksFile("stumarks.txt");

	if (!marksFile.is_open()) {
		cout << "Error opening marks file.\n";

	}

	string username, course;
	while (marksFile >> username) {
		if (fromfile == username) {
			cout << "Marks " << studentUsername << ":" << endl;

			while (marksFile >> course && course != "-1") {
				marksFile >> marks;
				cout << course << ": " << marks << endl;
			}

			cout << "-------------------------" << endl;
			marksFile.close();

		}
	}


	marksFile.close();

	cout << endl << endl;
	for (int i = 0; i < size; i++)
	{

		cout << a[i];
	}
	cout << endl << endl;
}










void Student::viewFeeStatus() {
	system("cls");
	system("color 17");
	cout << "\n\n";
	char a[] = "\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb";
	int size;
	size = strlen(a);
	for (int i = 0; i < size; i++)
	{

		cout << a[i];
	}
	cout << endl << endl;
	cout << setw(100) << "|View Fee Status|" << endl << endl;


	string name, fromfile;

	ifstream read("studentsusername.txt");
	read >> fromfile;


	ifstream in("studentdata.txt");
	if (in.is_open()) {
		int rollno;
		string username, storedPassword, fname, lname, degree, date, gen, con, bg, add, fstatus, qual, marks;
		while (in >> fname >> lname >> username >> storedPassword >> rollno >> degree >> date >> gen >> con >> bg >> add >> fstatus >> qual >> marks) {
			if (fromfile == username) {
				cout << "Fee Status: " << fstatus << endl;
				break;
			}
		}
		in.close();
	}
	else {
		cout << "Error opening student data file.\n";
	}
	cout << endl << endl;

	for (int i = 0; i < size; i++)
	{

		cout << a[i];
	}
}


void Student::viewgrades() {
	system("cls");
	system("color 17");

	cout << "\n\n";
	char a[] = "\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb";
	int size;
	size = strlen(a);
	for (int i = 0; i < size; i++)
	{

		cout << a[i];
	}
	cout << endl << endl;


	cout << setw(100) << "|View Grades|" << endl << endl;


	ifstream in("grades.txt");
	string username, name, fromfile;
	ifstream read("studentsusername.txt");
	read >> fromfile;
	string data;
	char grade;
	while (in >> username) {
		if (fromfile == username) {
			while (in >> data >> grade) {
				if (data == "-1")
				{

					break;
				}

				cout << "grade for: " << data << " is:" << grade << endl;
			}
		}


	}      cout << endl << endl;
	for (int i = 0; i < size; i++)
	{

		cout << a[i];
	}
	cout << endl << endl;

}


void Student::viewattendance() {
	system("cls");
	system("color 17");

	cout << "\n\n";
	char a[] = "\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb";
	int size;
	size = strlen(a);
	for (int i = 0; i < size; i++)
	{

		cout << a[i];
	}
	cout << endl << endl;



	cout << setw(100) << "|View Attandace|" << endl << endl;

	ifstream in("studentattendance.txt");
	string name, date, attend, username, day;
	cout << "Enter your username: " << endl;
	cin >> name;
	cout << "Enter date:" << endl;
	cin >> date;

	if (in.is_open()) {
		while (in >> username >> day >> attend)
		{

			if (name == username && date == day) {
				cout << "Your attendance at date" << date << "is" << attend << endl;
			}
		}
	}

	else {
		cout << "eroor opening file:" << endl;
	}

	cout << endl << endl;
	for (int i = 0; i < size; i++)
	{

		cout << a[i];
	}
	cout << endl << endl;

}

//////////////////////////////////////////// teacher class

Teacher::Teacher()
{
}

bool Teacher::authorize() {
	system("cls");
	system("color 6e");
	Sleep(10);
	cout << "\n\n";
	char a[] = "                            \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb|Login as Teacher|\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb";
	int size;
	size = strlen(a);
	for (int i = 0; i < size; i++)
	{
		Sleep(25);
		cout << a[i];
	}

	cout << endl << endl;
	cout << "\nTeacher Authentication\n";

	string enteredUsername, enteredPassword;

	cout << "Enter your username: ";
	cin >> enteredUsername;
	cout << "Enter your password: ";
	cin >> enteredPassword;


	ifstream in;
	ofstream out("teachersusername.txt");
	in.open("teacherdata.txt");
	if (in.is_open()) {
		int id, salary;
		string  firstName, lastName, department, username, password, date, gender, contactNo, qualification, address;
		while (in >> firstName >> lastName >> department >> id >> username >> password >> date >> gender >> contactNo >> qualification >> address >> salary) {
			if (enteredUsername == username && enteredPassword == password) {
				out << enteredUsername;
				cout << "Authentication successful.\n";
				in.close();
				return true;
			}

		}
		in.close();
	}
	cout << "Authentication failed. Incorrect username or password.\n";

	return false;

}






/////////////////////////////////////////////////////////// view time table
void Teacher::viewTimeTable() {
	system("cls");
	system("color 17");
	cout << "\n\n";
	char a[] = "\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb";
	int size;
	size = strlen(a);



	for (int i = 0; i < size; i++)
	{

		cout << a[i];
	}
	cout << endl << endl;



	cout << setw(100) << "|View Time Table|" << endl << endl;

	ifstream timetableFile("timetablefile.txt");

	if (timetableFile.is_open()) {
		string name;

		ifstream in("teachersusername.txt");
		in >> name;

		string storedUsername;
		int numberLectures;

		string username, data;
		while (timetableFile >> username) {
			if (name == username) {

				cout << "---------------------------------\n";
				cout << "LECTURE\tSUBJECT\tDAY\tTIME\n";
				while (timetableFile >> data) {
					if (data == "-1") {

						break;
					}
					cout << data << "\t";
				}
				cout << endl;
			}
		}

	}


	timetableFile.close();

	cout << endl << endl;
	for (int i = 0; i < size; i++)
	{

		cout << a[i];
	}
	cout << endl << endl;

}



void Teacher::assignMarks() {
	system("cls");
	system("color E0");
	cout << "\n\n";
	char a[] = "\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb|ASSIGN MARKS|\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb";


	int size;
	size = strlen(a);
	for (int i = 0; i < size; i++)
	{

		cout << a[i];
	}
	cout << endl << endl;



	string studentUsername;
	int marks;

	cout << "Enter student username: ";
	cin >> studentUsername;

	ifstream courseFile("courses.txt");
	ofstream out("stumarks.txt", ios::app);

	if (!courseFile.is_open()) {
		cout << "Error opening courses file.\n";
		return;
	}

	if (out.is_open()) {
		string name, course;

		while (courseFile >> name) {
			if (name == studentUsername) {
				out << studentUsername << " ";

				while (courseFile >> course) {
					if (course == "-1") {
						break;
					}

					cout << "Enter marks for " << course << ": ";
					cin >> marks;
					out << course << " " << marks << " ";
				}

				out << "-1" << endl;
			}
		}

		cout << "Marks assigned successfully.\n";
		out.close();
	}
	else {
		cout << "Error opening student data file.\n";
	}

	courseFile.close();
}


void Teacher::markingAttandanc() {
	system("cls");
	system("color E0");

	cout << "\n\n";
	char a[] = "\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb|Marking Attandance|\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb";
	cout << endl << endl;


	int size;
	size = strlen(a);
	for (int i = 0; i < size; i++)
	{

		cout << a[i];
	}
	cout << endl << endl;

	string studentUsername;
	string attendance;
	string date;
	int rollno;
	cout << "Enter student username: " << endl;
	cin >> studentUsername;
	cout << "enter date in string:" << endl;
	cin >> date;
	cout << "Enter attendance (Present/Absent): ";
	cin >> attendance;
	ofstream out("studentattendance.txt", ios::app);
	ifstream studentFile("studentdata.txt");


	if (studentFile.is_open()) {
		string username, storedPassword, fname, lname, degree, date, gen, con, bg, add, fstatus, qual, marks;
		while (studentFile >> fname >> lname >> username >> storedPassword >> rollno >> degree >> date >> gen >> con >> bg >> add >> fstatus >> qual >> marks) {
			if (studentUsername == username) {

				out << username << "  " << date << "  " << attendance << endl;
			}
			else {

			}
		}
		studentFile.close();



		cout << "Attendance marked successfully.\n";
	}
	else {
		cout << "Error opening student data file.\n";
	}
}

void Teacher::assigningGrades() {
	system("cls");
	system("color E0");
	cout << "\n\n";
	char a[] = "\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb|Assigning Grades|\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb";
	int size;
	size = strlen(a);
	for (int i = 0; i < size; i++)
	{

		cout << a[i];
	}
	cout << endl << endl;

	cout << endl << endl;




	string name, username, data;
	int mark;
	char grade;

	ofstream out("grades.txt", ios::app);
	ifstream in("stumarks.txt");
	cout << "Enter student username: ";
	cin >> name;
	while (in >> username) {
		if (name == username) {

			out << name << " ";

			while (in >> data >> mark) {
				if (data == "-1")
				{
					cout << endl;
					break;
				}

				int marks = mark;
				if (marks > 50 && marks < 100)
				{
					grade = 'B';


				}

				else if (marks < 50 && marks < 100)
				{
					grade = 'D';


				}
				out << data << "  " << grade << "  " << "-1";
			}	out << endl;
		}

	}



	cout << "Grades assigned successfully.\n";


}





////////////////////////////////////////////GUI

void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

/// Interface

char Interface()
{

	Sleep(10);

	cout << "\n\n";
	char a[] = "                             \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb|WELCOME TO FLEX MANAGEMENT SYSTEM|\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb";
	int size;
	size = strlen(a);
	for (int i = 0; i < size; i++)
	{
		Sleep(25);
		cout << a[i];
	}
	int c = 1;
	cout << endl << endl;
	Sleep(0);
	char choice = '\0';
	Sleep(0);

	cout << setw(61) << "1. LOAD DATA FROM FILE";


	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	//	cout << setw(58) << "\n\t\t\t\t\t\t0. Exit!\n\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	for (int i = 0; i < 1; i++)
	{
		int x = 28;
		int y = 10;
		for (y = 3; y < 13; y++)
		{
			gotoxy(x, y);
			cout << "\xdb";
			Sleep(100);
		}
		y = 13;
		for (x = 28; x < 91; x++)
		{
			gotoxy(x, y);
			cout << "\xdb";
			Sleep(20);
		}
		for (y = 3; y < 14; y++)
		{
			gotoxy(x, y);
			cout << "\xdb";
			Sleep(100);
		}
	}
	for (int i = 0; i < 1; i++)
	{
		int x = 1;
		int y = 15;
		for (x = 40; x > 1; x--)
		{
			gotoxy(x, y);
			cout << "FLEX MANAGEMENT SYSTEM";
			Sleep(100);
			gotoxy(x, y);
			cout << "                                                         ";
			cout << "                                            ";
		}
		cout << endl << "       Created By 'UMAR AND WASEEM.'" << endl;
	}
	cout << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 94);
	cout << setw(58) << "Enter choice: ";
	cin >> choice; return choice;
}


//////////// Main Menu


int Menu()
{
	system("cls");
	system("color 20");
	Sleep(10);

	cout << "\n\n";
	char a[] = "                            \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb|Main_Menu|\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb";
	int size;
	size = strlen(a);
	for (int i = 0; i < size; i++)
	{
		Sleep(25);
		cout << a[i];
	}
	int c = 1;
	cout << endl << endl;
	Sleep(0);
	int  choice = 0;
	Sleep(0);


	cout << setw(59) << "1.Admin Mode\n";
	cout << setw(61) << "2.Teacher Mode\n";
	cout << setw(61) << "3.Student Mode\n";


	cout << setw(58) << "\n\t\t\t\t\t\t0. Exit!\n\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	for (int i = 0; i < 1; i++)
	{
		int x = 28;
		int y = 10;
		for (y = 3; y < 13; y++)
		{
			gotoxy(x, y);
			cout << "\xdb";
			Sleep(100);
		}
		y = 13;
		for (x = 28; x < 80; x++)
		{
			gotoxy(x, y);
			cout << "\xdb";
			Sleep(20);
		}
		for (y = 3; y < 14; y++)
		{
			gotoxy(x, y);
			cout << "\xdb";
			Sleep(100);
		}
	}

	cout << endl << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 94);
	cout << setw(58) << "Enter choice: ";
	cin >> choice;

	return choice;
}




