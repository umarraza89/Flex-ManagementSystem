#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
# include<windows.h>
using namespace std;

///////////////////////////person

class person {
private:
	string firstName, lastName, department, username, password, gender, contactNo, qualification, address, date, bloodgroup, feestatus;
	int d, marks;
	static int rollno;
public:
	virtual void setteacherattributes() = 0;
	virtual void setattributes() = 0;
	virtual void setdepartment() = 0;
	virtual bool authorize() = 0;
	virtual void addteacher() = 0;
	virtual void editTeacherData() = 0;
	virtual void displayteacherdata() = 0;
	virtual void addstudent() = 0;
	virtual void editstudentData() = 0;
	virtual void displaystudentdata() = 0;




};


//////////////////////////////////////////// Admin class


class Admin :public person {
private:
	string name;
	string firstName, lastName, department, username, password, gender, contactNo, qualification, address, date, bloodgroup, feestatus;
	int d, marks;
	int pass;
	float salary;
	static int ids;
	int rollno, rollnot;
public:
	Admin();
	bool authorize();

	//getters
	string getfname();
	string getlname();
	string  getusername();
	string getpass();
	string getdepartment();
	string getgender();
	string getcontact();
	string getdegree();
	string getadd();
	string getdate();
	string getbloodgroup();

	string getfeestatus();
	int getmarks();

	float getsal();


	void setdepartment();

	void setteacherattributes();

	void setattributes();      // set data for student

	void addstudent();



	////////////////////////////// /////////////////////////////add teacher

	void addteacher();



	void displayteacherdata();

	void displaystudentdata();


	void editstudentData();

	void editTeacherData();
	~Admin() {

	}
};




//////////////////////////////////////////////// student   module



class Student : public Admin {

private:
	static int id;

public:
	Student();

	bool authorize();
	void viewRegisteredCourses();
	void viewMarks();
	void viewFeeStatus();
	void viewgrades();
	void viewattendance();

};




//////////////////////////////////////////// teacher class

class Teacher : public Admin {
private:
	string name;
	int pass;
public:
	Teacher();
	bool authorize();
	/////////////////////////////////////////////////////////// view time table
	void viewTimeTable();
	void assignMarks();
	void markingAttandanc();
	void assigningGrades();
};



////////////////////////////////////////////GUI

void gotoxy(int x, int y);

/// Interface

char Interface();


//////////// Main Menu


int Menu();






