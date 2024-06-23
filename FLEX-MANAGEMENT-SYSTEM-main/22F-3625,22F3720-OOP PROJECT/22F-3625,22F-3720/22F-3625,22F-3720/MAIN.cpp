#include<iostream>
#include"project.h"
#include<iomanip>
#include<fstream>
#include<string>
# include<windows.h>
using namespace std;
int main()
{
	int key;

	Interface();




	system("cls");
	system("color 1f");




	int choice;
	do {


		choice = Menu();
		if (choice == 1)
		{
			system("cls");
			person* ptradmin;
			ptradmin = new Admin();

			bool found = ptradmin->authorize();
			if (found) {

				int key;
				cout << "1: Add teacher\n";
				cout << "2: Edit teacher data\n";
				cout << "3: Display teacher data\n";
				cout << "4: Add student\n";
				cout << "5: Edit student details\n";
				cout << "6: Display student data\n";

				cout << endl << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
				cout << "Enter your choice: ";
				cin >> key;


				switch (key) {
				case 1:
					ptradmin->addteacher();
					break;
				case 2:
					ptradmin->editTeacherData();
					break;
				case 3:
					ptradmin->displayteacherdata();
					break;
				case 4:
					ptradmin->addstudent();
					break;
				case 5:
					ptradmin->editstudentData();
					break;
				case 6:
					ptradmin->displaystudentdata();
					break;
				default:
					cout << "Invalid choice\n";
				}
			}
			else {
				cout << "Incorrect credentials:" << endl;
			}
		}
		else if (choice == 2)
		{
			system("cls");
			Teacher* teacherptr, t;

			teacherptr = &t;
			bool teacherFound = false;
			teacherFound = teacherptr->authorize();

			if (teacherFound == true)
			{
				int teacherChoice;
				cout << endl << endl;
				cout << "1: View TimeTable\n";
				cout << "2: Assign Marks\n";
				cout << "3: Mark Attendance\n";
				cout << "4: Assign Grades\n";

				cout << endl << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
				cout << "Enter your choice: ";
				cin >> teacherChoice;

				switch (teacherChoice) {
				case 1:
					teacherptr->viewTimeTable();
					break;
				case 2:
					teacherptr->assignMarks();
					break;
				case 3:
					teacherptr->markingAttandanc();
					break;
				case 4:
					teacherptr->assigningGrades();
					break;
				default:
					cout << "Invalid choice\n";
				}
			}
		}

		else if (choice == 3) {
			system("cls");
			Student* stuptr, s;
			stuptr = &s;

			bool studentFound = stuptr->authorize();
			cout << endl << endl;
			if (studentFound) {
				int studentChoice;
				cout << "1: View Attendance\n";
				cout << "2: View Marks\n";
				cout << "3: View Grades\n";
				cout << "4: View Registered Courses\n";
				cout << "5: View Fee Status\n";

				cout << endl << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
				cout << "Enter your choice: ";
				cin >> studentChoice;

				switch (studentChoice)
				{
				case 1:
					stuptr->viewattendance();
					break;
				case 2:
					stuptr->viewMarks();
					break;
				case 3:
					stuptr->viewgrades();
					break;
				case 4:
					stuptr->viewRegisteredCourses();
					break;
				case 5:
					stuptr->viewFeeStatus();
					break;
				default:
					cout << "Invalid choice\n";
				}

			}

		}
		cout << "IF YOU WANT TO RUN AGAIN THEN PRESS ANY KEY OTHER THAN 0" << endl;
		cin >> key;
	} while (key != 0);

	return 0;
}